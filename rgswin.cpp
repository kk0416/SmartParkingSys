#include "rgswin.h"
#include "ui_rgswin.h"
RgsWin *RgsWin::pRgswin=nullptr;
RgsWin::RgsWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RgsWin)
{
    ui->setupUi(this);

    //窗口居中
    QDesktopWidget *deskdop=QApplication::desktop();
    move((deskdop->width()-this->width())/2, (deskdop->height()-this->height())/2);

    ui->Editusrid->setPlaceholderText("长度6~8位(英文字母、数字和下划线)");
    ui->Editusrname->setPlaceholderText("长度6~8位(中英文、数字)");
    ui->Editusrpwd->setPlaceholderText("长度6~10位(英文字母、数字和下划线)");
//    ui->Editusrpwd->setEchoMode(QLineEdit::PasswordEchoOnEdit);//密文输入,编辑时显示，但下次输入会直接覆盖
    ui->Editusrpwd->setEchoMode(QLineEdit::Password);//密文输入
    ui->Editusrpwd1->setEchoMode(QLineEdit::Password);

    QRegExp regxid("^[0-9a-zA-Z_]{6,8}$");//正则表达式只能输入英文字母数字和下划线
    QValidator *validatorid = new QRegExpValidator(regxid, ui->Editusrid );
    ui->Editusrid->setValidator(validatorid);
//^[a-zA-Z0-9_\u4e00-\u9fa5]+$
    QRegExp regxnm("^[a-zA-Z0-9_\u4e00-\u9fa5]{6,8}");//正则表达式只能输入中英文、字母、数字
    QValidator *validatornm = new QRegExpValidator(regxnm, ui->Editusrid );
    ui->Editusrname->setValidator(validatornm);

    QRegExp regxpwd("^[0-9a-zA-Z_]{6,10}$");//正则表达式只能输入英文字母数字和下划线
    QValidator *validatorpwd = new QRegExpValidator(regxpwd, ui->Editusrid );
    ui->Editusrpwd->setValidator(validatorpwd);

    //密码框小眼睛
    ui->label->setAlignment(Qt::AlignCenter);
    ui->label->setPixmap(QPixmap("./image/eye.png").scaled(20, 20));
    ui->label->installEventFilter(this);

    //密码框小眼睛
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_2->setPixmap(QPixmap("./image/eye.png").scaled(20, 20));
    ui->label_2->installEventFilter(this);

    //初始化单例类对象\聊天窗口\数组\信号和槽
    this->sc=SocketConnect::getInstance();
    this->rt=ReadThread::getInstance(this->sc->getSocketfd());
    this->wt=WriteThread::getInstance(this->sc->getSocketfd());


    memset(this->buf,0,sizeof(this->buf));


    connect(this->rt,SIGNAL(SendRgs(int)),this,SLOT(FmRgsres(int)));
    logw=LoginWin::getInstance();
    connect(logw,SIGNAL(emitLoginSignal()),this,SLOT(acceptloginSlot()));//登录界面隐藏，该界面显示

}

RgsWin::~RgsWin()
{
    delete ui;
}

RgsWin *RgsWin::getInstance()
{
    RgsWin *rgswn;
    if(rgswn->pRgswin==nullptr)
    {
        rgswn->pRgswin=new RgsWin();
    }
    return rgswn->pRgswin;
}

void RgsWin::FmRgsres(int flag)
{
    if(flag==0)//注册成功
    {
       QMessageBox::information(NULL,"title","注册成功！立即登录");
       this->hide();
       logw->show();

    }
    else if(flag==1)//用户已存在
    {
       QMessageBox::information(NULL,"title","用户已存在，请重新输入！");
       ui->Editusrid->clear();
       ui->Editusrpwd1->clear();
       ui->Editusrpwd->clear();
    }

}

void RgsWin::on_BtnOK_clicked()
{



//    this->hide();

//    logw->show();

    qDebug()<<"rrr111"<<endl;
    //临时变量接收用户帐号密码，后续转为ｃｈａｒ型
    QString usrid=ui->Editusrid->text();
    QString usrname=ui->Editusrname->text();
    QString usrpwd=ui->Editusrpwd->text();
    QString usrpwd1=ui->Editusrpwd1->text();
    qDebug()<<"usrid"<<usrid;
    qDebug()<<"usrname"<<usrname;
    qDebug()<<"usrpwd"<<usrpwd;
    qDebug()<<"usrpwd1"<<usrpwd1;
    if(usrname==0||usrpwd==0||usrpwd1==0||usrid==0)//输入为空
     {
        qDebug()<<"rrr2121"<<endl;
         QMessageBox::information(this,"输入为空","输入不能为空");
     }
    else if(QString::compare(usrpwd,usrpwd1)!=0)//密码不一致
    {
        qDebug()<<"rrr2323"<<endl;
        QMessageBox::information(this,"密码不一致","两次密码输入不一致，请重新输入！");
    }
    else
    {   qDebug()<<"rrr23"<<endl;
        const char *pusrname=usrname.toStdString().c_str();
        const char *pusrid=usrid.toStdString().c_str();
        const char *pusrpwd=usrpwd.toStdString().c_str();
         qDebug()<<"pusrname"<<pusrname;
          qDebug()<<"pusrid"<<pusrid;
           qDebug()<<"pusrpwd"<<pusrpwd;

        qDebug()<<"rrr333"<<endl;
        //赋给用户信息结构体属性
        memcpy(this->regist.username,pusrname,sizeof (this->regist.username));
        memcpy(this->regist.passward,pusrpwd,sizeof (this->regist.passward));
        memcpy(this->regist.userid,pusrid,sizeof (this->regist.userid));
qDebug()<<"rrr444"<<endl;
        qDebug()<<"regist.username = "<<regist.username;
        qDebug()<<"regist.password = "<<regist.passward;
        qDebug()<<"sizeof(head.businesslen) = "<< sizeof(this->regist);

        this->pro.businessType=2;//登录
        this->pro.businessLength=sizeof (this->regist);//登录结构体的长度
        this->pro.acceptfd=0;

        qDebug()<<"pro.businesslength = "<<this->pro.businessLength;
        memset(buf,0,sizeof (buf));
        memcpy(this->buf,&(this->pro),sizeof(HEAD));//头写进去
        qDebug()<<"sizeof(this->pro) = "<<sizeof(this->pro);
        qDebug()<<"bufsize1 = "<<sizeof (buf);
        memcpy(this->buf+sizeof(HEAD),&(this->regist),sizeof(this->regist));//指针偏移，存两个结构体
        qDebug()<<"sizeof(this->regist) = "<<sizeof(this->regist);
        qDebug()<<"bufsize = "<<sizeof (buf);
        this->rt->start();
        this->wt->start();
        this->wt->setData(&(this->buf),sizeof(this->buf));//要发送的数据传给写线程进行ｗｒｉｔｅ


    }
}

void RgsWin::acceptloginSlot()
{
    this->show();
    ui->Editusrid->clear();
    ui->Editusrname->clear();
    ui->Editusrpwd1->clear();
    ui->Editusrpwd->clear();
    qDebug()<<"acceptloginSlot";

}
bool RgsWin::eventFilter(QObject *watched, QEvent *event)
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

void RgsWin::on_BtnCancel_clicked()
{
    this->hide();
    LoginWin *logw1=LoginWin::getInstance();
    logw1->show();
}
