#include "sendpicfilesthread.h"

SendPicFilesThread::SendPicFilesThread(int pictype,char*piccname,char *picpath)//图片类型、图片名字、图片路径
{
    this->type=0;
    this->flag=-1;
//    qDebug() << "000this->file_name" <<this->file_name;
//    qDebug() << "000this->filepath" <<this->filepath;
//    qDebug() << "000piccname" <<piccname;
//    qDebug() << "000picpath" <<picpath;
    this->type=pictype;
    strcpy(this->file_name,piccname);
    strcpy(this->filepath,picpath);
    qDebug() << "111this->file_name" <<this->file_name;
    qDebug() << "111this->filepath" <<this->filepath;
    qDebug() << "111this->type" <<this->type;

    this->sc=SocketConnect::getInstance();
    this->rt=ReadThread::getInstance(this->sc->getSocketfd());
    this->wt=WriteThread::getInstance(this->sc->getSocketfd());

    connect(this->rt,SIGNAL(sendphotoinfo(int)),this,SLOT(getpicres(int)));
}

void SendPicFilesThread::run()
{
    creatdir();//创建存放碎片文件的文件夹
    splitfiles();//将传进来的图片文件拆分，放在上述文件夹里
    sendsplitfiles();//一个一个上传图片文件给服务器，服务器接收后反馈成功，再发送下一个
    qDebug()<<"11----－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－ ";

}
//创建存放碎片文件的文件夹
void SendPicFilesThread::creatdir()
{
    // 判断文件夹是否存在，不存在则创建
//    qDebug() << "222this->file_name" <<this->file_name;

    QString p="./pic/splitdirs/";
    QString fname=QString::fromUtf8(this->file_name);
//    qDebug() << "fname---" <<fname;
    fullPath=p+fname;
//    qDebug() << "文件夹路径fullPath＝" <<fullPath;
    QDir dir(p);//文件夹所在目录
    QDir dir1(fullPath);//要创建的文件夹完整路径（包括该文件夹名字）
    if(!dir1.exists()){//判断该文件夹是否存在
        bool ismkdir = dir.mkdir(fname);//不存在的话，在父目录下创建新文件夹
        if(!ismkdir)
            qDebug() << "Create path fail" << endl;
        else
            qDebug() << "Create fullpath success" << endl;
    }
    else{
        qDebug() << "fullpath exist" << endl;
    }

}
//将传进来的图片文件拆分，放在上述文件夹里
void SendPicFilesThread::splitfiles()
{
     qDebug() <<"拆分";
     qDebug()<<"fullPath.toLatin1().data()"<<fullPath.toLatin1().data();
     int readFd = 0;
     int writeFd = 0;
     int readRes = 0;
     int fileNumber = 1;
     umask(0);
     readFd = open(this->filepath, O_RDONLY, 0777);
     int bufs[256] = { 0 };
     if (readFd < 0)
     {
         perror("open file error");//打开文件失败
     }
     else
     {
         while ((readRes = read(readFd, bufs, sizeof(bufs))) > 0)//以100kb为单位分割父文件
         {
             char childFileName[255] = { 0 };//存放分割后的子文件名
             sprintf(childFileName, "%s%d%s", (fullPath+"/").toLatin1().data(), fileNumber, ".temp");//子文件路径拼接
             writeFd = open(childFileName, O_CREAT | O_WRONLY, 0777);//创建子文件
             if (writeFd < 0)
             {
                 perror("open file error");
             }
             else
             {
                 write(writeFd, bufs, readRes);//子文件写入数据
                 qDebug() << childFileName << " 分割成功！" << endl;
                 fileNumber++;
                 close(writeFd);//关闭子文件
             }
             //清空数组
             bzero(bufs, sizeof(bufs));
             bzero(childFileName, sizeof(childFileName));
         }
         close(readFd);
     }
}
//一个一个上传图片文件给服务器，服务器接收后反馈成功，再发送下一个
void SendPicFilesThread::sendsplitfiles()
{
    qDebug() <<"发送";

    this->AllNum=getfilecount(fullPath+"/"); //当前文件个数,一共有几个包
    this->all_size=getfilesize(filepath);//图片大小总长度
    //循环发送
    for (int i=1;i<=this->AllNum;i++)
    {
        bzero(&this->photo,sizeof (this->photo));
        this->photo.NowNum=i;//当前是第几个包---
        QString sfilepath=fullPath+"/"+QString::number(i)+".temp";//碎片文件路径

        qDebug() <<"碎片文件路径sfilepath＝"<<sfilepath;
        //读取碎片文件，赋给ｂｌｏｃｋｄａｔａ
        readfd=open(sfilepath.toLatin1().data(),O_RDONLY, 0777);
        qDebug() <<"碎片文件路径sfilepath.toLatin1().data()＝"<<sfilepath.toLatin1().data();
        rres=read(readfd,this->photo.block_data,sizeof (this->photo.block_data));
        qDebug() << "rres="<<rres;
        close(readfd);

        this->photo.type=this->type;
        this->photo.all_size=this->all_size;
        this->photo.AllNum=this->AllNum;
        this->photo.currentSize=getfilesize(sfilepath);
//        memcpy(this->photo.file_name,this->file_name,sizeof (this->photo.file_name));
        sprintf(this->photo.file_name,"%s%s",this->file_name,".jpg");

        qDebug() << "图片类型type="<<this->photo.type
                <<"  图片总大小all_size="<<this->photo.all_size
                <<"  图片文件总数量AllNum＝"<<this->photo.AllNum
                <<"  当前包大小currentSize="<<this->photo.currentSize
                <<"  图片名file_name＝"<<this->photo.file_name
                <<"　当前是第几个NowNum＝"<<this->photo.NowNum;

        this->head.businessType=4;//图片文件
        this->head.businessLength=sizeof (this->photo);//登录结构体的长度
        this->head.acceptfd=0;

        qDebug()<<"pro.businesslength = "<<this->head.businessLength;
        memset(buf,0,sizeof (buf));
        memcpy(this->buf,&(this->head),sizeof(HEAD));//头写进去
        qDebug()<<"sizeof(this->pro) = "<<sizeof(this->head);
        qDebug()<<"bufsize1 = "<<sizeof (buf);
        memcpy(this->buf+sizeof(HEAD),&(this->photo),sizeof(this->photo));//指针偏移，存两个结构体
        qDebug()<<"sizeof(this->logusr) = "<<sizeof(this->photo);
        qDebug()<<"bufsize = "<<sizeof (buf);
        qDebug()<<"this->photo.block_data = "<<strlen (this->photo.block_data);

         qDebug()<<"this->photo.block_data = "<<sizeof(this->photo.block_data);
        this->wt->setData(&(this->buf),sizeof (this->buf));
        qDebug()<<"sendpicfileflag＝"<<flag<<endl;
        while (this->flag!=1)//死循环阻塞，每发完一个包，等待服务器反馈，ｆｌａｇ＝１，再进行下一个包的发送
        {

        }
        this->flag=0;
    }
 qDebug() <<"发送wanbi";
}
//获取文件大小
int SendPicFilesThread::getfilesize(QString filename)
{
    QFileInfo info(filename.toStdString().c_str());
    if (info.exists()) {
        qDebug() << info.size();
    } else {
        qDebug() << "文件路径不存在！";
    }
    return  info.size();

}
//获取文件夹下文件个数
int SendPicFilesThread::getfilecount(QString filepath)
{
    QDir dir(filepath);
    dir.setFilter(QDir::Files);
//加过滤器，选择前缀为name的文件
//    QStringList filters;
//    filters << "name*";
//    dir.setNameFilters(filters);
    QFileInfoList list=dir.entryInfoList();
    QFileInfo fileInfo;
    QStringList filelist;
    foreach (fileInfo, list)
    {
        filelist << fileInfo.fileName();
    }
    int count = filelist.count();
    qDebug()<<"文件个数＝"<<count<<endl;
    return count;
}
//读线程槽函数
void SendPicFilesThread::getpicres(int flag)
{
   qDebug()<<"收到服务器文件碎片反馈ｆｌａｇ＝"<<flag<<endl;
   this->flag=flag;

}
