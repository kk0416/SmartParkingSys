#ifndef RGSWIN_H
#define RGSWIN_H

#include <string.h>
#include <QMessageBox>
#include <QWidget>
#include "protocol.h"
#include <QDebug>
#include "socketconnect.h"
#include "readthread.h"
#include "writethread.h"
#include "loginwin.h"
namespace Ui {
class RgsWin;
}

class RgsWin : public QWidget
{
    Q_OBJECT

public:
    ~RgsWin();
    static RgsWin* getInstance();
public slots:
    void FmRgsres(int flag);//读线程自定义信号对应的槽
private:
    Ui::RgsWin *ui;
    explicit RgsWin(QWidget *parent = nullptr);
    static RgsWin* pRgswin;

    LoginWin *logw;
    REG regist;
    SocketConnect *sc;
    ReadThread * rt;
    WriteThread * wt;
    HEAD pro;
    LOGIN logusr;
    char buf[sizeof (HEAD)+sizeof (REG)];
private slots:
    void on_BtnOK_clicked();
    void acceptloginSlot();
    bool eventFilter(QObject *watched, QEvent *event);
    void on_BtnCancel_clicked();
};
#endif // RGSWIN_H
