#ifndef LOGINWIN_H
#define LOGINWIN_H
#include <string.h>
#include <QMessageBox>
#include <QWidget>
#include "protocol.h"
#include <QDebug>
#include "socketconnect.h"
#include "readthread.h"
#include "writethread.h"
#include "verificationcodelabel.h"
#include "mainwin.h"
#include <QDesktopWidget>
#include <QString>
namespace Ui {
class LoginWin;
}

class LoginWin : public QWidget
{
    Q_OBJECT

public:

    ~LoginWin();
    static LoginWin *getInstance();
    bool eventFilter(QObject *watched, QEvent *event);

private:
    Ui::LoginWin *ui;
    explicit LoginWin(QWidget *parent = nullptr);
    static LoginWin *plogw;

    SocketConnect *sc;
    ReadThread * rt;
    WriteThread * wt;
    HEAD pro;
    LOGIN logusr;
    char buf[sizeof (HEAD)+sizeof (LOGIN)];
    VerificationCodeLabel *LabYanZhengMa;
public slots:
    void Fmres(int flag);//读线程自定义信号对应的槽
private slots:
    void on_BtnOK_clicked();

    void on_BtnRgs_clicked();

    void on_BtnCancel_clicked();
signals:
    void emitLoginSignal();
};

#endif // LOGINWIN_H
