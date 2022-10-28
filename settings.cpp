#include "settings.h"
#include "ui_settings.h"
Settings *Settings::psetwin=nullptr;

/*
 用户在界面上选择设置菜单。
 客户端进入设置界面。
 可在此界面修改设备要连接的服务器IP 地址和端口信息。
 车牌图片保存地址，使用文件路径选择器选择保存图片的地址（编辑框禁止输入）
 视频录制存地址，使用文件路径选择器选择保存视频的地址（编辑框禁止输入）
 退出 后，要立即保存到配置文件中。
 可以设置本地系统默认存储空间大小，用于保存采集到的视频数据，如果视频大小
不够或超出大小，则系统从本地存储数据的最早时间开始 自动删除 ，直到新的采集数据可以
保存为止。
 连接服务器成功与否，需要有友好提示。
*/

Settings::Settings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    this->connectflag=0;

    socketconnect=SocketConnect::getInstance();


    //窗口居中
    QDesktopWidget *deskdop=QApplication::desktop();
    move((deskdop->width()-this->width())/2, (deskdop->height()-this->height())/2);
    //编辑框不可编辑
    ui->EditPicAdrs->setFocusPolicy(Qt::NoFocus);
    ui->EditVdAdrs->setFocusPolicy(Qt::NoFocus);
    getippfmt();

    //获取指定目录的磁盘情况,直接设置路径即可
    QStorageInfo SD;
    SD.setPath(QDir::currentPath());
    SD.refresh();  //获得最新磁盘信息
    ui->EditStore->setText(QString("%1").arg(SD.bytesAvailable()/1024/1024/1024));

    this->islogin=false;

    mainw=MainWin::getInstance();
    connect(mainw,SIGNAL(emitosetw()),this,SLOT(slotmaintoset()));

//    connect(socketconnect,SIGNAL(emitisconnect(int)),this,SLOT(slotisconnect(int)));


}





Settings::~Settings()
{
    delete ui;
}

Settings *Settings::getInstance()
{
    Settings *setwin;
    if(setwin->psetwin==nullptr)
    {
        setwin->psetwin=new Settings();
    }
    return setwin->psetwin;
}
/*
QString Settings::getip()
{

    QString str=ui->EditIP->text().toStdString().c_str();
    return str;
}

QString Settings::getport()
{
    QString str=ui->EditPort->text().toStdString().c_str();
    return str;
}
*/

void Settings::on_BtnOK_clicked()
{
    //未使用
//    emit connectgetipp(ui->EditIP->text().toStdString().c_str(),ui->EditPort->text().toStdString().c_str());//发送信号到连接类








    storeippt();

    //将编辑框ｉｐ＼ｐｏｒｔ传给连接类
    QString str=ui->EditPort->text().toStdString().c_str();
    socketconnect->setIp(ui->EditIP->text().toStdString().c_str());
    socketconnect->setPort(str.toInt());
    qDebug()<<"connectflag1="<<this->connectflag;
    socketconnect->CreateConnect();

    if(this->connectflag==1)
    {
        QMessageBox::information(NULL,"title","与服务器连接失败，请重新连接！");
        qDebug()<<"与服务器连接失败，请重新连接！"<<this->connectflag;
    }
    else if (this->connectflag==2) {
        QMessageBox::information(NULL,"title","与服务器连接成功！");
        qDebug()<<"与服务器连接成功！"<<this->connectflag;
    }
    qDebug()<<"connectflag2="<<this->connectflag;

     qDebug()<<"thisip="<<ui->EditIP->text().toStdString().c_str();
     qDebug()<<"thisport="<<str.toInt();

//    this->islogin=true;
//    this->hide();
//    LoginWin *Logw=LoginWin::getInstance();
//    Logw->show();

     //返回主界面
     if(this->islogin==true)//登录了，返回界面
     {
         this->hide();

     }
     else {//登录

         this->islogin=true;
         this->hide();
         LoginWin *Logw=LoginWin::getInstance();
         Logw->show();

     }

}

void Settings::on_BtnReturn_clicked()
{
    //返回主界面
    if(this->islogin==true)//登录了，返回界面
    {
        this->hide();
//        mainw->show();
    }
    else {//退出程序

        exit(0);
    }
}

void Settings::on_BtnPicAdrs_clicked()
{
    PathName = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                 "./",
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks);

    ui->EditPicAdrs->setText(PathName);    //文件名称显示
}

void Settings::on_BtnVdAdrs_clicked()
{
    PathName = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                 "./",
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks);

    ui->EditVdAdrs->setText(PathName);    //文件名称显示
}
//住界面进设置界面槽函数
void Settings::slotmaintoset()
{
    qDebug()<<"33333333333333333333333333333333333333333333333333=";
    this->show();
}

void Settings::slotisconnect(int a)
{
    this->connectflag=a;
    qDebug()<<"33333333333333333333333333333333333333333333333333this->connectflag==="<<this->connectflag<<"a==="<<a;
}

void Settings::storeippt()
{

    int writefd = 0;
    int readfd = 0;
    int res = 0;
    char buf[50] ={} ;
    char rebuf[50] ={} ;
    sprintf(buf,"%s",(ui->EditIP->text().toStdString()+"\n"+ui->EditPort->text().toStdString()).c_str());//String字符串拼接在转换成ｃｈａｒ＊
    qDebug()<<"txtbuf="<<buf;
    umask(0);

    //文件不存在则创建，否则打开，并以只写方式打开，
    writefd = open("./doc/iport1.txt", O_CREAT | O_WRONLY, 0777);

    if (writefd < 0)//文件打开失败，返回-1
    {
        perror("open file error");
    }
    else
    {
        res = write(writefd, buf, strlen(buf));
    }

}

void Settings::getippfmt()
{

    QFile file("./doc/iport1.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QString line;
        QTextStream in(&file);  //用文件构造流
        int i=0;
        while(i<2)//字符串有内容
        {
            line=in.readLine();//循环读取下行
            qDebug() << line;
            switch (i) {
            case 0:
                ui->EditIP->setText(line);
            case 1:
                ui->EditPort->setText(line);
//            case 2:
//                ui->lineEdit_3->setPlaceholderText(line);
//            case 3:
//                ui->lineEdit_5->setPlaceholderText(line);

            }
            i++;

        }
    }
    file.close();

}

