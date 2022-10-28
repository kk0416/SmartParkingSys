#include "playbackvdthread.h"

PlayBackVdThread::PlayBackVdThread(char *videoPath)
{
    this->m_BtnpauseState=false;
    vidp=QString::fromUtf8(videoPath);
    qDebug()<<"videoPath"<<vidp;
}

void PlayBackVdThread::run()
{
    this->m_BtnpauseState=true;


        qDebug()<<QString("run :%1").arg(this->m_BtnpauseState);

        if(cap.open((this->vidp).toStdString().c_str()))//视频路径，循环播放，重新读取
        {
             qDebug()<<"open video";
        }

        while(cap.read(frame))
        {
            this->m_mutex.lock();//锁

            if(frame.empty())//如果视频播放完，跳出循环，进行下一次播放
            {
                break;
                qDebug()<<"视频播放完，跳出循环，进行下一次播放";
            }
            this->m_mutex.unlock();//解锁
            emit frameVideo(frame);//读到一帧画面发送信号
            msleep(30);

        }




}

void PlayBackVdThread::stopthread()
{
    this->exec();
}

void PlayBackVdThread::threadPause()
{
    qDebug()<<QString("视频回放pause :%1").arg(this->m_BtnpauseState);
   if(this->m_BtnpauseState==true)//防止运行中直接按继续按钮误解锁
   {
       qDebug()<<QString("视频回放pause :%1").arg(this->m_BtnpauseState);
       this->m_mutex.lock();
       this->m_BtnpauseState=false;
       qDebug()<<QString("视频回放BtnPause");
   }
   else
   {
        qDebug()<<"视频回放不要重复按暂停";
   }
}

void PlayBackVdThread::threadContin()
{
    if(this->m_BtnpauseState==false)//防止运行中直接按继续按钮误解锁
   {
       qDebug()<<QString("视频回放Continue :%1").arg(this->m_BtnpauseState);
       this->m_mutex.unlock();
       this->m_BtnpauseState=true;
       qDebug()<<QString("视频回放Continue");
   }
   else{
       qDebug()<<"视频回放先按继续再暂停";
   }
}
