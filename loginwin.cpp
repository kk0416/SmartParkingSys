#include "loginwin.h"
#include "ui_loginwin.h"
LoginWin *LoginWin::plogw=nullptr;
LoginWin::LoginWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWin)
{
    ui->setupUi(this);

    //窗口居中
    QDesktopWidget *deskdop=QApplication::desktop();
    move((deskdop->width()-this->width())/2, (deskdop->height()-this->height())/2);

    QRegExp regx("^[0-9a-zA-Z_]{1,}$");//正则表达式只能输入英文字母\数字和下划线
    QValidator *validator = new QRegExpValidator(regx, ui->Editusrid );
    ui->Editusrid->setValidator(validator);

    ui->EditVfcd->clear();
    ui->Editusrid->clear();
    ui->Editusrpwd->clear();


    ui->Editusrpwd->setEchoMode(QLineEdit::Password);//密文输入
    LabYanZhengMa=new VerificationCodeLabel;
    //密码框小眼睛
    ui->label->setAlignment(Qt::AlignCenter);
    ui->label->setPixmap(QPixmap("./image/eye.png").scaled(20, 20));
    ui->label->installEventFilter(this);

    //初始化单例类对象\聊天窗口\数组\信号和槽
    this->sc=SocketConnect::getInstance();
    this->rt=ReadThread::getInstance(this->sc->getSocketfd());
    this->wt=WriteThread::getInstance(this->sc->getSocketfd());


    memset(this->buf,0,sizeof(this->buf));

    connect(this->rt,SIGNAL(SendSign(int)),this,SLOT(Fmres(int)));


}

void LoginWin::Fmres(int flag)
{
    if(flag==0)//登录成功
    {
        QMessageBox::information(NULL,"title","登录成功！");
//        const char *userid=ui->Editusrid->text().toStdString().c_str();
        //主界面
        MainWin *mainw=MainWin::getInstance();
        mainw->setUserid(ui->Editusrid->text());//ｕｓｅｒｉｄ传过去
        mainw->show();

        this->hide();

    }
    else if(flag==1)//账号不存在
    {

        QMessageBox::information(NULL,"title","账号不存在");
    }
    else if(flag==2)//密码错误
    {

        QMessageBox::information(NULL,"title","密码错误，请重新输入");
    }
    else if(flag==3)//重复登录
    {

        QMessageBox::information(NULL,"title","账号重复登录");
    }

}

LoginWin *LoginWin::getInstance()
{
    LoginWin *Logw;
    if(Logw->plogw==nullptr)
    {
        Logw->plogw=new LoginWin();
    }
    return Logw->plogw;
}

LoginWin::~LoginWin()
{
    delete ui;
}

void LoginWin::on_BtnOK_clicked()
{
    //临时变量接收用户帐号密码，后续转为ｃｈａｒ型
    QString usrname=ui->Editusrid->text();
    QString usrpwd=ui->Editusrpwd->text();
    QString yzm=ui->EditVfcd->text();
    if(usrname==0||usrpwd==0)
     {
         QMessageBox::information(this,"输入为空","输入不能为空");
     }
    else if (QString::compare(yzm,ui->LabVfcd->v)!=0)
    {
        qDebug()<<"验证码错误"<<endl;
        qDebug()<<"验证码："<<LabYanZhengMa->v;
        //弹出消息框
        QMessageBox::information(this,"验证码错误","验证码错误"); QMessageBox::information(this,"验证码错误","验证码错误");
        ui->EditVfcd->clear();
    }






    else if(usrname.length()>0&&usrpwd.length()>0)
    {
        const char *pusrname=usrname.toStdString().c_str();
        const char *pusrpwd=usrpwd.toStdString().c_str();
        //赋给用户信息结构体属
        memcpy(this->logusr.userid,pusrname,sizeof (pusrname));
        memcpy(this->logusr.passward,pusrpwd,sizeof (pusrpwd));
        memcpy(this->logusr.username,"",3);
        this->pro.businessType=1;//登录
        this->pro.businessLength=sizeof (this->logusr);//登录结构体的长度
        this->pro.acceptfd=0;
        qDebug()<<"pro.businesslength = "<<this->pro.businessLength;
        memset(buf,0,sizeof (buf));
        memcpy(this->buf,&(this->pro),sizeof(HEAD));//头写进去
        qDebug()<<"sizeof(this->pro) = "<<sizeof(this->pro);
        qDebug()<<"bufsize1 = "<<sizeof (buf);
        memcpy(this->buf+sizeof(HEAD),&(this->logusr),sizeof(this->logusr));//指针偏移，存两个结构体
        qDebug()<<"sizeof(this->logusr) = "<<sizeof(this->logusr);
        qDebug()<<"bufsize = "<<sizeof (buf);

//        this->sc->CreateConnect();//初始化网络
        this->rt->start();
        this->wt->start();
        this->wt->setData(&(this->buf),sizeof(this->buf));//要发送的数据传给写线程进行ｗｒｉｔｅ

}
//    MainWin *mainw=MainWin::getInstance();
//    mainw->setUserid(ui->Editusrid->text());//ｕｓｅｒｉｄ传过去
//    mainw->show();

//    this->hide();
}
void LoginWin::on_BtnRgs_clicked()
{
    qDebug()<<"emitLoginSignal1 ";
    emit emitLoginSignal();
    this->hide();
}

void LoginWin::on_BtnCancel_clicked()
{
    this->close();
}
bool LoginWin::eventFilter(QObject *watched, QEvent *event)
{
    switch (event->type()) {
        case QEvent::Enter:
            ui->Editusrpwd->setEchoMode(QLineEdit::Normal);  //显示密码
            break;
        case QEvent::Leave:
            ui->Editusrpwd->setEchoMode(QLineEdit::Password);//隐藏密码
            break;
        default:
            break;
    }
    return QWidget::eventFilter(watched, event);
}
