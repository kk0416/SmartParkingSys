#include "playvdthread.h"
#include <QString>
PlayVdThread::PlayVdThread(char *videoPath)
{
    this->scale=2;
    this->storepicflag=0;
    this->i=0;
    this->j=0;
    this->m_BtnpauseState=false;
    this->pictypeflag=0;
    this->vidflag=0;

    cascade.load("./c_xml/cars.xml");//从文件中加载分类器
    if(cap.open(videoPath))
    {
           qDebug()<<"open video";
    }
    vidp=QString::fromUtf8(videoPath);
    qDebug()<<"videoPath"<<vidp;

}

void PlayVdThread::run()
{
    this->m_BtnpauseState=true;

    while(1)//实现循环播放视频
    {

        qDebug()<<QString("run :%1").arg(this->m_BtnpauseState);

        if(cap.open((this->vidp).toStdString().c_str()))//视频路径，循环播放，重新读取
        {
             qDebug()<<"open video";
        }

        while(cap.read(frame))
        {
            this->m_mutex.lock();//锁

            getvideo();//手动录制视频
            getAvideo();//自动录制视频
            getpic();//抓拍照片

            if(frame.empty())//如果视频播放完，跳出循环，进行下一次播放
            {
                break;
                qDebug()<<"视频播放完，跳出循环，进行下一次播放";
            }

            this->detectCarDraw();//级联分类器
            this->m_mutex.unlock();//解锁
            emit frameVideo(frame);//读到一帧画面发送信号
            msleep(30);

        }

    }

}
//线程结束
void PlayVdThread::stopthread()
{
    this->exec();
}

void PlayVdThread::threadPause()
{
     qDebug()<<QString("pau11se :%1").arg(this->m_BtnpauseState);
    if(this->m_BtnpauseState==true)//防止运行中直接按继续按钮误解锁
    {
        qDebug()<<QString("pause :%1").arg(this->m_BtnpauseState);
        this->m_mutex.lock();
        this->m_BtnpauseState=false;
        qDebug()<<QString("BtnPause");
    }
    else
    {
         qDebug()<<"不要重复按暂停";
    }
}
//线程继续
void PlayVdThread::threadContin()
{
    if(this->m_BtnpauseState==false)//防止运行中直接按继续按钮误解锁
   {
       qDebug()<<QString("Continue :%1").arg(this->m_BtnpauseState);
       this->m_mutex.unlock();
       this->m_BtnpauseState=true;
       qDebug()<<QString("Continue");
   }
   else{
       qDebug()<<"先按继续再暂停";
   }
}
//级联分类器
void PlayVdThread::detectCarDraw()
{

    Mat grayframe;
    cvtColor(this->frame,grayframe,CV_RGB2GRAY);
    //灰度图缩小一半
    Mat smallGframe(cvRound(this->frame.rows/scale),cvRound(this->frame.cols/scale),CV_8UC1);
    cv::resize(grayframe,smallGframe,smallGframe.size());
    //直方图均值化：将灰度图黑白分明
    equalizeHist(smallGframe,smallGframe);
    vector<Rect>cars;//定义vector用来存放标记的矩形车辆（被检测物体的矩形框向量组）
    cascade.detectMultiScale(smallGframe,cars,1.1,2,0|CV_HAAR_SCALE_IMAGE,Size(30,30));//detectMultiScale将要检测的目标保存到vector里、
    //绘制方块
    vector<Rect>::const_iterator iter;
    for(iter=cars.begin();iter!=cars.end();iter++)
    {
      rectangle(this->frame,
                cvPoint(cvRound(iter->x*scale),cvRound(iter->y*scale)),
                cvPoint(cvRound((iter->x+iter->width)*scale),cvRound((iter->y+iter->height)*scale)),
                Scalar(0,255,0),2,8);
    }
}

void PlayVdThread::setStorepicflag(int value)
{
    storepicflag = value;
}

void PlayVdThread::setPictypeflag(int value)
{
    pictypeflag = value;
}

void PlayVdThread::setVidflag(int value)
{
    vidflag = value;
}
//手动录制视频
void PlayVdThread::getvideo()
{
    if(this->vidflag==1)
    {

        if(this->i==0)
        {
            QString fileNamev=QDateTime::currentDateTime().toString("yyyy-MM-dd-ss") ;
            qDebug()<<"fileNamev="<<fileNamev;
            vidwriter.open("./Vid/"+fileNamev.toStdString()+".avi",
                            CV_FOURCC('M', 'J', 'P', 'G'),
                            cap.get(CV_CAP_PROP_FPS), //不进行跟踪，定位，只显示、录制时的帧率
                            Size((int)cap.get(CV_CAP_PROP_FRAME_WIDTH),(int)cap.get(CV_CAP_PROP_FRAME_HEIGHT)),
                            true);

            vdtime=fileNamev;
            vdpath="./Vid/"+fileNamev+".avi";
            vdname=fileNamev+".avi";
            qDebug()<<"vdtime="<<vdtime;
            qDebug()<<"vdpath="<<vdpath;
            qDebug()<<"vdname="<<vdname;
        }

        this->i++;

        qDebug()<<"i="<<this->i;

        vidwriter.write(frame);

        if(this->i==180)
        {
            vidwriter.release();


            qDebug()<<"videofinish";
            this->vdsize=getfilesize(vdpath);
            qDebug()<<"该视频文件大小为"<<getfilesize(vdpath);
            qDebug()<<"vdpath"<<vdpath;
            //发送视频信息信号给主界面
            emit sendvdinfoemit(vdname,vdtime,vdpath,vdsize,i);
            this->vidflag=0;
            this->i=0;
        }

    }
}
//自动录制视频
void PlayVdThread::getAvideo()
{
    if(this->vidflag==2)
    {
       if(this->j==0||this->j%180==0)//如果为第一帧或者每隔３０ｓ的倍数，创建视频文件
       {
           if(this->j%180==0)
           {
              vidwriter1.release();
              qDebug()<<"vdpath1"<<vdpath;
              this->vdsize=getfilesize(vdpath);
              qDebug()<<"该视频文件大小为"<<getfilesize(vdpath);
              qDebug()<<"vdpath2"<<vdpath;
              //发送视频信息信号给主界面
              emit sendvdinfoemit(vdname,vdtime,vdpath,vdsize,j);
              qDebug()<<"--------------------------------ｎｅｘｔｖｉｄｅｏ---------------------------------"<<this->j;
           }

           QString fileNamev=QDateTime::currentDateTime().toString("yyyy-MM-hh-ss") ;
           vidwriter1.open("./Vid/"+fileNamev.toStdString()+".avi",
                           CV_FOURCC('M', 'J', 'P', 'G'),
                           cap.get(CV_CAP_PROP_FPS), //不进行跟踪，定位，只显示、录制时的帧率
                           Size((int)cap.get(CV_CAP_PROP_FRAME_WIDTH),(int)cap.get(CV_CAP_PROP_FRAME_HEIGHT)),
                           true);
           vdtime=fileNamev;
           vdpath="./Vid/"+fileNamev+".avi";
           vdname=fileNamev+".avi";
           qDebug()<<"vdtime="<<vdtime;
           qDebug()<<"vdpath="<<vdpath;
           qDebug()<<"vdname="<<vdname;
       }
       this->j++;
       qDebug()<<"j----"<<this->j;
       vidwriter1.write(frame);
    }
}
//抓拍图片
void PlayVdThread::getpic()
{
    if(this->storepicflag==1)
    {
        QString pictynm=nullptr;

        if(this->pictypeflag==1)//入场
        {
            pictynm="carpics/IN_C-";

        }
        else if (this->pictypeflag==2) //出场
        {
             pictynm="carpics/O_C-";


        }
        else if (this->pictypeflag==3) //停车
        {
             pictynm="parkpics/Park-";

        }
        QString datetime= QDateTime::currentDateTime().toString("yyyy-MM-dd-hh-ss");
        QString fileName=pictynm+datetime+ ".jpg";//通过时间命名文件
        imwrite("./pic/"+fileName.toStdString(),frame);//保存图片
        qDebug()<<"保存图片＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝";
        if(this->pictypeflag==1)//入场
        {
            QString inpicname="IN_C-"+datetime;//不要ｊｐｇ后缀
            QString inpicpath="./pic/"+fileName;
            qDebug()<<"入场图片mingzi："<<inpicname;
            qDebug()<<"入场图片路径："<<inpicpath;
            emit sendpicincaremit(inpicname,inpicpath);
            qDebug()<<"发送信号－－上传入场车辆信息↓";
            emit emitsendincarinfo();
            qDebug()<<"发送信号－－上传入场车辆信息↑";
            this->pictypeflag=0;
        }
        else if (this->pictypeflag==2) {
            QString outpicname="O_C-"+datetime;//不要ｊｐｇ后缀
            QString outpicpath="./pic/"+fileName;
            qDebug()<<"出场图片名字："<<outpicname;
            qDebug()<<"出场图片路径："<<outpicpath;
            emit sendpicoutcaremit(outpicname,outpicpath);
            qDebug()<<"发送信号－－上传出场车辆信息↓";
            emit emitsendoutcarinfo();
            qDebug()<<"发送信号－－上传出场车辆信息↑";
            this->pictypeflag=0;
        }
        else if (this->pictypeflag==3) {
            QString pkpicname="Park-"+datetime;//不要ｊｐｇ后缀
            QString pkpicpath="./pic/"+fileName;
            qDebug()<<"停车场图片名字："<<pkpicname;
            qDebug()<<"停车场图片路径："<<pkpicpath;
            emit sendpicpkcaremit(pkpicname,pkpicpath);
            qDebug()<<"发送信号－－上传停车场车辆信息↓";
            emit emitsendpkcarinfo();
            qDebug()<<"发送信号－－上传停车场车辆信息↑";
            this->pictypeflag=0;
        }
        this->storepicflag=0;
    }
}
//获取文件大小
int PlayVdThread::getfilesize(QString filename)
{
    QFileInfo info(filename.toStdString().c_str());
    if (info.exists()) {
        qDebug() << info.size();
    } else {
        qDebug() << "文件路径不存在！";
    }
    return  info.size();

}

