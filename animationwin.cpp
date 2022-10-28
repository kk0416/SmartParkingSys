#include "animationwin.h"
#include "ui_animationwin.h"

AnimationWin::AnimationWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AnimationWin)
{
     ui->setupUi(this);
     //窗口居中
     QDesktopWidget *deskdop=QApplication::desktop();
     move((deskdop->width()-this->width())/2, (deskdop->height()-this->height())/2);
    //去掉系统自带标题栏，但不能移动拖动窗口
     this->setWindowFlags(Qt::FramelessWindowHint);
     connect(&theTimer, &QTimer::timeout, this, &AnimationWin::updateImage);
     //视频
     if(videoCap.open("./video/O.mp4"))
     {
         srcImage = Mat::zeros(videoCap.get(CV_CAP_PROP_FRAME_HEIGHT), videoCap.get(CV_CAP_PROP_FRAME_WIDTH), CV_8UC3);
         theTimer.start(13);
     }
     //设置显示视频用的Label
     imageLabel = new QLabel(this);
     ui->verticalLayout->addWidget(imageLabel);
   }
AnimationWin::~AnimationWin()
{
    delete ui;
}

void AnimationWin::paintEvent(QPaintEvent *e)
{
    //显示方法一
  /*  QPainter painter(this);
    QImage image1 = QImage((uchar*)(srcImage.data), srcImage.cols, srcImage.rows, QImage::Format_RGB888);
    painter.drawImage(QPoint(20,20), image1);*/
    //显示方法二
    QImage image2 = QImage((uchar*)(srcImage.data), srcImage.cols, srcImage.rows, QImage::Format_RGB888);
    image2=image2.scaled(imageLabel->width(),imageLabel->height());   //视频与ｌａｂｅｌ自适应
    imageLabel->setPixmap(QPixmap::fromImage(image2));
    imageLabel->resize(image2.size());
    imageLabel->show();
}

void AnimationWin::updateImage()
{
    videoCap>>srcImage;
    if(srcImage.data)
    {
        cvtColor(srcImage, srcImage, CV_BGR2RGB);//Qt中支持的是RGB图像, OpenCV中支持的是BGR
        this->update();  //发送刷新消息
    }
    else {
        this->hide();//视频播放完毕后该窗口关闭
        Settings *setWin=Settings::getInstance();
        setWin->show();
    }
}

