#ifndef ANIMATIONWIN_H
#define ANIMATIONWIN_H
#include <QPaintEvent>
#include <QPainter>
#include <QPixmap>
#include <QLabel>
#include <QImage>
#include <QWidget>
#include <QDebug>
#include <opencv2/opencv.hpp>
#include <QTimer>
#include <QDesktopWidget>
#include "settings.h"
#include "loginwin.h"
using namespace std;
using namespace cv;
namespace Ui {
class AnimationWin;
}

class AnimationWin : public QWidget
{
    Q_OBJECT

public:
    explicit AnimationWin(QWidget *parent = nullptr);
    ~AnimationWin();
public slots:
    void updateImage();
private:

    QTimer theTimer;
    Mat srcImage;
    VideoCapture videoCap;
    QLabel *imageLabel;

    Ui::AnimationWin *ui;

protected:
    void paintEvent(QPaintEvent *e);


};

#endif // ANIMATIONWIN_H
