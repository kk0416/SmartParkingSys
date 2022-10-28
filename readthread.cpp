#include "readthread.h"
ReadThread *ReadThread::readthread=nullptr;
ReadThread::ReadThread(int socketfd)
{
    this->socketfd=socketfd;
    memset(this->videoinfo,0,sizeof (this->videoinfo));
}

ReadThread *ReadThread::getInstance(int socketfd)
{
    if(ReadThread::readthread==nullptr)
    {
        ReadThread::readthread=new ReadThread(socketfd);
    }
    return ReadThread::readthread;

}
ReadThread::~ReadThread()
{


}
//不断读取服务器端反馈过来的信息
void ReadThread::run()
{

    while(1)
    {
        read(this->socketfd,&(this->fedbk),sizeof(FEEDBACK));//读取服务器端反馈的信息
//        qDebug()<<"fedbk.businesstype　＝　"<<this->fedbk.businesstype;
        //根据ｔｙｐｅ判断是进行登录还是注册
        if(fedbk.businesstype==1)//登录
        {
            qDebug()<<"ｌｏｇｉｎflag = "<<this->fedbk.flag;
            emit SendSign(this->fedbk.flag);//触发信号，到登录界面信号槽，将登录是否成功传到登录界面
        }
        else if (this->fedbk.businesstype==2)//注册
        {
            emit SendRgs(this->fedbk.flag);//触发信号，将注册结构体传给注册界面
        }
        else if (this->fedbk.businesstype==3)//入场信息
        {
//            read(this->socketfd,&this->carinfo,sizeof(CAR_INFO));//读取服务器发来的车辆信息相关信息
            emit sendincarinfo(this->fedbk.flag);//触发信号，将注册结构体传给主界面

        }
        else if (this->fedbk.businesstype==4)//图片信息
        {
            if(fedbk.flag==1)
             {
                qDebug()<<"一个图片碎片文件包存入成功";
             }
            emit sendphotoinfo(this->fedbk.flag);//触发信号，将图片信息传给主界面
        }
        else if (this->fedbk.businesstype==5)//视频信息
        {           
//                read(this->socketfd,&this->video,sizeof(VIDEO));//读取服务器发来的视频相关信息
                emit sendvdinfo(this->fedbk.flag);//触发信号，将视频结构体传给主界面
                qDebug()<<"视频信息存入数据库成功";         
        }
        else if (this->fedbk.businesstype==6)//出场信息
        {

            if(fedbk.flag==1)
             {
               read(this->socketfd,&this->carinfo6,sizeof(CAR_INFO));//读取服务器发来的出场相关信息
               emit sendoutcarinfo(&carinfo6);//触发信号，将出场结构体传给主界面

             }
            else if (fedbk.flag==2) {
                qDebug()<<"出场信息存入数据库失败";
            }

        }
        else if (this->fedbk.businesstype==7)//车辆查询信息
        {
            if(fedbk.flag==1)
            {
                read(this->socketfd,this->carinfo7,sizeof(this->carinfo7));//读取服务器发来的车辆查询相关信息

                qDebug()<<"sizeof(this->carinfo7)"<<sizeof(this->carinfo7);
                qDebug()<<"this->carinfo7[0].inDate"<<this->carinfo7[0].inDate;
                qDebug()<<"this->carinfo7[0].outDate"<<this->carinfo7[0].outDate;
                qDebug()<<"this->carinfo7[0].inDatePhoto"<<this->carinfo7[0].inDatePhoto;
                qDebug()<<"this->carinfo7[0].outDatePhoto"<<this->carinfo7[0].outDatePhoto;
                emit sendsrccarinfo(carinfo7);//触发信号，将车辆结构体传给主界面
                qDebug()<<"车辆信息查询成功";

            }
            else if (fedbk.flag==2) {
                qDebug()<<"车辆查询信息查找失败";
            }

        }
        else if (this->fedbk.businesstype==8)//视频查询信息
        {
            if(fedbk.flag==1)
             {
                read(this->socketfd,this->videoinfo,sizeof(this->videoinfo));//读取服务器发来的视频相关信息
                qDebug()<<"sizeof(this->videoinfo)"<<sizeof(this->videoinfo);
                qDebug()<<"this->videoinfo[0].size"<<this->videoinfo[0].size;
                qDebug()<<"this->videoinfo[0].videoname"<<this->videoinfo[0].videoname;
                qDebug()<<"this->videoinfo[0].uptime"<<this->videoinfo[0].uptime;
                qDebug()<<"this->videoinfo[0].filepath"<<this->videoinfo[0].filepath;
                emit sendvideoinfo(videoinfo);//触发信号，将视频结构体传给主界面
                qDebug()<<"视频信息查询成功";

             }
            else if (fedbk.flag==2) {
                qDebug()<<"视频信息查询失败";

            }

        }
    }


}


