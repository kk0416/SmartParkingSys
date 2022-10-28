#ifndef PLAYVDTHREAD_H
#define PLAYVDTHREAD_H
#include <QDateTime>
#include <QObject>
#include <QThread>
#include <QDebug>
#include <opencv2/opencv.hpp>
#include <QMutex>
#include <QFileInfo>
using namespace cv;
using namespace std;
class PlayVdThread : public QThread
{
    Q_OBJECT
public:
    PlayVdThread(char *videoPath);
    virtual ~PlayVdThread() {}
    void run();
    void stopthread();
    void threadPause();//线程暂停
    void threadContin();//线程继续
    void detectCarDraw();
//    void threadisalive();
    void setStorepicflag(int value);

    void setPictypeflag(int value);

    void setVidflag(int value);

    void getAvideo();
    void getvideo();
    void getpic();

   int getfilesize(QString filename);



private:
    VideoCapture cap;
    VideoWriter vidwriter;//保存视频
    VideoWriter vidwriter1;//自动保存视频
    Mat  frame;
    double scale;//识别车辆用到
    CascadeClassifier cascade;
    QString vidp;
    int storepicflag;//抓拍标志位
    int pictypeflag;//视频类型　１：入场车　２：出场车　３：停车场
    int vidflag;

    int i,j;
    QMutex m_mutex;//互斥量 暂停继续使用
    bool m_BtnpauseState;//点击暂停 状态1

    QString vdname;
    QString vdtime;
    QString vdpath;
    int vdsize;

signals:
    void emitsendincarinfo();
    void emitsendoutcarinfo();
    void emitsendpkcarinfo();
    void frameVideo(Mat frame);
    void sendvdinfoemit(QString vdname,QString vdtime,QString vdpath,int vdsize,int vdframes);//(视频名字、视频日期、视频路径、视频大小)
    void sendpicincaremit(QString inpicname,QString inpicpath);
    void sendpicoutcaremit(QString outpicname,QString outpicpath);
    void sendpicpkcaremit(QString pkpicname,QString pkpicpath);
};
#endif // PLAYVDTHREAD_H
