#ifndef PLAYBACKVDTHREAD_H
#define PLAYBACKVDTHREAD_H
#include <QObject>
#include <QThread>
#include <QDebug>
#include <opencv2/opencv.hpp>
#include <QMutex>
using namespace cv;
using namespace std;
class PlayBackVdThread : public QThread
{
    Q_OBJECT
public:
    PlayBackVdThread(char *videoPath);
    virtual ~PlayBackVdThread() {}
    void run();
    void stopthread();
    void threadPause();//线程暂停
    void threadContin();//线程继续
private:
     VideoCapture cap;
     Mat  frame;
     QMutex m_mutex;//互斥量 暂停继续使用
     bool m_BtnpauseState;//点击暂停 状态1
     QString vidp;
signals:
     void frameVideo(Mat frame);
};

#endif // PLAYBACKVDTHREAD_H
