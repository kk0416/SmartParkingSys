#include "widget.h"
#include <QApplication>
#include "verificationcodelabel.h"//验证码
#include "animationwin.h"//开机动画
#include "loginwin.h"
#include "settings.h"
#include "rgswin.h"
#include "mainwin.h"
#include "teststacked.h"//测试ｓｔａｃｋｅｄｗｉｄｇｅｔ
#include <qdir.h>
#include <QTextCodec>
int main(int argc, char *argv[])
{
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
    QApplication a(argc, argv);
//    AnimationWin w;
//    LoginWin *w=LoginWin::getInstance();
    RgsWin *r=RgsWin::getInstance();//提前创建好注册类对象
//    r->show();
//    MainWin *w=MainWin::getInstance();
    Settings *s=Settings::getInstance();
//    teststacked w;
//        w.show();
    s->show();
    return a.exec();
}
