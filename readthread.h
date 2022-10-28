#ifndef READTHREAD_H
#define READTHREAD_H
#include <QThread>
#include <QDebug>
#include "protocol.h"
#include "socketconnect.h"
#include <QMessageBox>
class ReadThread : public QThread
{
    Q_OBJECT
public:
    virtual ~ReadThread();
    static ReadThread* getInstance(int socketfd);//把socketfd作为参数传给构造函数
    void run();
private:
    ReadThread(int socketfd);

    int socketfd;
    static ReadThread* readthread;

    HEAD data;
    FEEDBACK fedbk;
    REG rgs;
    LOGIN login;
//    CAR_INFO carinfo3;
    CAR_INFO carinfo6;
    CAR_INFO carinfo7[50];
    PHOTO photo;
    VIDEO video;
    VIDEO videoinfo[50];
signals:
    void SendSign(int flag);//登录
    void SendRgs(int flag);//注册
    void sendincarinfo(int flag);//入场
    void sendphotoinfo(int flag);//图片
    void sendvideoinfo(VIDEO *videoinfo);//视频回放 VIDEO videoinfo[50]
    void sendvdinfo(int flag);//视频信息
    void sendoutcarinfo(CAR_INFO *carinfo6);//出场
    void sendsrccarinfo(CAR_INFO *carinfo7);//查询车辆信息



};
#endif // READTHREAD_H
