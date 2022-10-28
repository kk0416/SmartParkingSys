#ifndef SETTINGS_H
#define SETTINGS_H
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <QWidget>
#include <QDesktopWidget>
#include "loginwin.h"
#include<QFile>
#include<QTextStream>
#include <QMessageBox>
#include<QFileDialog>
#include<iostream>
#include <fstream>
#include<QStorageInfo>
//#include "socketconnect.h"
using namespace std;
namespace Ui {
class Settings;
}

class Settings : public QWidget
{
    Q_OBJECT

public:

    ~Settings();
    static Settings *getInstance();
    QFile filetxt;
//    QString getip();
//    QString getport();

private slots:
void on_BtnOK_clicked();

    void on_BtnReturn_clicked();

    void on_BtnPicAdrs_clicked();

    void on_BtnVdAdrs_clicked();

    void slotmaintoset();

    void slotisconnect(int a);
    void storeippt();
    void getippfmt();

private:
    Ui::Settings *ui;
    explicit Settings(QWidget *parent = nullptr);
    static Settings *psetwin;
    QString PathName;
    SocketConnect *socketconnect;

    bool islogin;
    int connectflag;

    MainWin *mainw;




signals:
    void connectgetipp(QString ip,QString port);
    void emitinmainwin();
};

#endif // SETTINGS_H
