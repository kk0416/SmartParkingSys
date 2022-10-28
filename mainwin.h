#ifndef MAINWIN_H
#define MAINWIN_H
#include <QImage>
#include <QWidget>
#include <QDebug>
#include <opencv2/opencv.hpp>
#include <QTimer>
#include <QPaintEvent>
#include <QPainter>
#include <QPixmap>
#include "playvdthread.h"//播放视频（摄像头）线程
#include <easypr.h>
#include <QDateTime>
#include <QDesktopWidget>
#include "readthread.h"
#include "writethread.h"
#include "socketconnect.h"
#include "protocol.h"
#include <QMessageBox>
#include "sendpicfilesthread.h"
#include <QTreeWidgetItem>
#include <QListWidgetItem>
#include "playbackvdthread.h"

using namespace std;
using namespace cv;
using namespace easypr;
namespace Ui {
class MainWin;
}

class MainWin : public QWidget
{
    Q_OBJECT

public:
     ~MainWin();
    static MainWin *getInstance();
    void timeUpdate(void);//更新系统时间

    void setUserid(QString value);//从登录界面获取当前登录用户ｉｄ
    int SumSruct(void)
    {
        int i=0,Sum=0;
        for(i=0;i<50;i++)
        {
            if(videoinf[i].size!=0&&videoinf[i].allFrames!=0)  //99是我设置的X
            {
                Sum++;
                qDebug()<<"Sum＝＝＝)"<<Sum;

            }
        }
        return Sum;         //返回长度
    }

public slots:
    void updateImage(Mat img);
    void recvincarinfo(int flag);//入场车辆信息－读取服务器反馈
    void recvphotoinfo(int flag);//图片信息－读取服务器反馈
    void recvdinfo(int flag);//上传视频信息－－读取服务器反馈
    void recvideoinfo(VIDEO *videoinf);//视频信息－读取服务器反馈
    void recvoutcarinfo(CAR_INFO *carinfo);//出场车辆信息－读取服务器反馈
    void recvsrcarinfo(CAR_INFO *carinfo);//查询车辆信息－读取服务器反馈
    void getinpicslot(QString inpicname,QString inpicpath);//从线程获取入场图片信息
    void getoutpicslot(QString outpicname,QString outpicpath);//从线程获取出场图片信息
    void getpkpicslot(QString pkpicname,QString pkpicpath);//从线程获取停车场图片信息
    void getvdimfpslot(QString vdname,//接收线程发过来的视频信息
                       QString vdtime,QString vdpath,
                       int vdsize,
                       int vdframes);
    void sendincarinfo();//向服务器发送入场车辆信息
    void sendoutcarinfo();//向服务器发送出场车辆信息
    void sendpkpicfl();//向服务器发送停车场图片文件

    void radioBtnSlot();
    void radioBtnSlot2();
private slots:

    void on_BtnIn_clicked();//停车场－＞入场

    void on_BtnOut_5_clicked();//停车场－＞出场模式

    void on_BtnOGetCarNum_clicked();//出场车牌

    void on_BtnInGetCarNum_clicked();//入场车牌

    void on_BtnInChangeNum_clicked();//入场修改车牌

    void on_BtnIn_2_clicked();//出场－＞入场

    void on_BtnOut_6_clicked();//入场－＞出场

    void on_BtnMngParkn_7_clicked();//出场－＞停车场

    void on_BtnMngParkn_6_clicked();//入场－＞停车场

    void on_pushButton_5_clicked();//停车场抓拍

    void on_pushButton_4_clicked();//停车场，手动录制视频

    void on_BtnSettings_6_clicked();//入场－＞设置

    void on_BtnSettings_7_clicked();//出场－＞设置

    void on_BtnSettings_5_clicked();//停车场－＞设置

    void on_checkBox_stateChanged(int arg1);//停车场checkbox－自动录制视频

    void on_ckBox_ism_stateChanged(int arg1);//出场checkbox－是否是月卡

    void on_pushButton_clicked();//停车场－>监控回放

    void on_pushButton_2_clicked();//监控回放－>停车场

    void on_pushButton_12_clicked();//监控列表－>播放视频测试１

    void on_pushButton_20_clicked();//视频回放界面－>监控视频列表



    void on_BtnGo_clicked();//放行

    void on_BtnQueryCar_5_clicked();//停车场－>查询车辆信息

    void on_BtnQueryCar_7_clicked();//出场－>查询车辆信息

    void on_BtnQueryCar_6_clicked();//入场－>查询车辆信息

    void on_BtnSerchCarinfo_clicked();//查询车辆信息按钮槽函数

    void on_BtnRetnMain_clicked();//车辆信息查询－＞入场
    //上传服务器－－查找日期对应视频信息－树形布局－－视频日期目录
    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);
    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_pushButton_19_clicked();//回放视频暂停槽函数

private:
    Ui::MainWin *ui;
    explicit MainWin(QWidget *parent = nullptr);
    static MainWin *pmainw;

    PlayBackVdThread *playbackkvdthread;//视频回放线程对象
    QString vdbackpath;
    PlayVdThread *playvdthread;//出入场视频线程对象
    PlayVdThread *playvdthreadp;//停车场视频线程对象
    SendPicFilesThread *sdpicflthread;
    SendPicFilesThread *sdpicflthreadp;
    SendPicFilesThread *sdpicflthreado;
    SendPicFilesThread *sdpicflthreadib;
    SendPicFilesThread *sdpicflthreadob;
    CPlateRecognize pr;
    CPlate plate;
    vector<CPlate>plateVec;
    Mat  plateMat;

    Mat frame;

    int Btnflag;//判断点击哪个按钮　切换到哪个界面播放哪个视频显示到界面

    QDateTime datetime1;
    QTimer *timer1;

    SocketConnect *sc;
    ReadThread * rt;
    WriteThread * wt;
    HEAD head;

    //入场车辆信息结构体
    CAR_INFO carinfo3;
    char buf[sizeof (HEAD)+sizeof (CAR_INFO)];
    bool isvipp;
    //出场车辆信息结构体
    CAR_INFO carinfo6;
    CAR_INFO carinfo7; //查询车辆信息结构体

    QString inpicpath;
    QString outpicpath;
    QString inpicname;
    QString outpicname;
    QString pkpicpath;
    QString pkpicname;

    //视频结构体
    VIDEO videoinfo;
    const char* vdname;
    const char* vdtime;
    const char* vdpath;
    int vdsize;
    int useridd;
    int vdframes;
    //图片文件
    PHOTO photo;

    int parksps;//停车场车位

    QString sdvdatetime;//日期目录名
    VIDEO videoinf[50];

    Pc aa[10];//测试结构体数组

protected:
    void paintEvent(QPaintEvent *e);//更新画面
signals:
    void emitosetw();
};


#endif // MAINWIN_H
