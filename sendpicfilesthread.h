#ifndef SENDPICFILESTHREAD_H
#define SENDPICFILESTHREAD_H
#include <QObject>
#include <QThread>
#include <QDebug>
#include <QDir>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include<QFile>
#include <unistd.h>
#include "protocol.h"
#include "readthread.h"
#include "writethread.h"
#include "socketconnect.h"
using namespace std;
class SendPicFilesThread : public QThread
{
    Q_OBJECT
public:
    SendPicFilesThread(int pictype,char* piccname,char *picpath);//创建线程对象的时候将要拆分上传的图片路径传进来
    virtual ~SendPicFilesThread() {}
    void run();
    void creatdir();//创建存放碎片文件的文件夹
    void splitfiles();//将传进来的图片文件拆分，放在上述文件夹里
    void sendsplitfiles();//一个一个上传图片文件给服务器，服务器接收后反馈成功，再发送下一个

    int getfilesize(QString filename);//获取文件大小
    int getfilecount(QString filepath);//获取文件夹下文件个数

private:
    SocketConnect *sc;
    ReadThread * rt;
    WriteThread * wt;

    HEAD head;
    PHOTO photo;
    char buf[sizeof (HEAD)+sizeof (PHOTO)];

    int type;//1-车牌，2-车辆 3-抓拍
    int all_size;//总长度
    int AllNum;//一共有几个包
    int NowNum;//当前是第几个包
    int currentSize;//当前包的长度
    char file_name[20];//文件名
    char block_data[10240];//碎片文件数据

    char filepath[50];//文件路径
    QString fullPath;//拆分文件夹路径

    int readfd;
    int rres;

    int flag;
public slots:
    void getpicres(int flag);
};
#endif // SENDPICFILESTHREAD_H
