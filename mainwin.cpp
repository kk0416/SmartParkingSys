#include "mainwin.h"
#include "ui_mainwin.h"
MainWin *MainWin::pmainw=nullptr;
MainWin::MainWin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWin)
{
    ui->setupUi(this);
    //窗口居中
    QDesktopWidget *deskdop=QApplication::desktop();
    move((deskdop->width()-this->width())/2, (deskdop->height()-this->height())/2);
    pr.setDetectType(PR_DETECT_CMSER|PR_DETECT_COLOR);
    pr.setMaxPlates(4);
    pr.setResultShow(false);
    //车位初始显示
    this->parksps=333;
    ui->label_22->setText("剩余车位："+QString::number(this->parksps));


    Pc c[] = {{3,4},{1,1},{2,2}};
    size_t len = sizeof(c) / sizeof(c[0]);
    qDebug()<<"-------------------------------------------结构体数组组数为＝"<<len;


    int i=0,Sum=0;
    for(i=0;i<60;i++)
    {
        if(c[i].x!=0)  //99是我设置的X
        {
            Sum++;
        }
    }
    qDebug()<<"-----------结构体数组组数为===========＝"<<Sum;


    //表格控件
    ui->tableWidget->verticalHeader()->setHidden(true);//去除序列号
    ui->tableWidget->horizontalHeader()->setFixedHeight(50); //设置表头的高度

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);  //不可编辑
//    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);



    QStringList header;

//    InfHeader<<tr("序号")<<tr("车牌信息")<<tr("入场时间")<<tr("出场时间")<<tr("入场图片")<<tr("出场图片")<<tr("停车金额");
//    ui->tableWidget_2->setHorizontalHeaderLabels(InfHeader);

    header<<"序号"<<"车牌信息"<<"入场时间"<<"出场时间"<<"入场图片"<<"出场图片"<<"停车金额";
    ui->tableWidget_2->setHorizontalHeaderLabels(header);
    ui->tableWidget_2->verticalHeader()->setHidden(true);//去除序列号
    ui->tableWidget_2->horizontalHeader()->setFixedHeight(45); //设置表头的高度
    // 1、设置所有的列
    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);  //不可编辑
    ui->tableWidget_2->setColumnCount(7);//只设置列数，行数动态中增加






    this->sc=SocketConnect::getInstance();
    this->rt=ReadThread::getInstance(this->sc->getSocketfd());
    this->wt=WriteThread::getInstance(this->sc->getSocketfd());

    connect(this->rt,SIGNAL(sendincarinfo(int)),this,SLOT(recvincarinfo(int)));

    connect(this->rt,SIGNAL(sendphotoinfo(int)),this,SLOT(recvphotoinfo(int)));
    connect(this->rt,SIGNAL(sendvdinfo(int)),this,SLOT(recvdinfo(int)));
    connect(this->rt,SIGNAL(sendvideoinfo(VIDEO*)),this,SLOT(recvideoinfo(VIDEO*)));
    connect(this->rt,SIGNAL(sendoutcarinfo(CAR_INFO*)),this,SLOT(recvoutcarinfo(CAR_INFO*)));
    connect(this->rt,SIGNAL(sendsrccarinfo(CAR_INFO*)),this,SLOT(recvsrcarinfo(CAR_INFO*)));

    //按月＼按日
    connect(ui->radioButton, SIGNAL(toggled( bool)), this, SLOT(radioBtnSlot()));
    connect(ui->radioButton_2, SIGNAL(toggled( bool)), this, SLOT(radioBtnSlot2()));




    //获取当前系统时间://初始化时间和日期显示
    datetime1 = QDateTime::currentDateTime();
    QString dateTime = datetime1.toString("yyyy-MM-dd hh:mm:ss ddd");
    qDebug()<<"datetime="<<dateTime;
    ui->LabCurrentTime->setText("当前系统时间: "+dateTime);
    //创建定时器更新时间
    timer1=new QTimer(this);
    connect(timer1, &QTimer::timeout, this, &MainWin::timeUpdate);
    timer1->start(1000);

    //进入该窗口自动显示入场界面，开启视频播放线程
    this->Btnflag=1;
    ui->stackedWidget->setCurrentIndex(0);

    this->playvdthread = new PlayVdThread("./video/car_input.mp4");
    connect(this->playvdthread,SIGNAL(frameVideo(Mat)),this,SLOT(updateImage(Mat)),Qt::BlockingQueuedConnection);
    this->playvdthread->start();

    connect(this->playvdthread,SIGNAL(sendpicincaremit(QString,QString)),this,SLOT(getinpicslot(QString,QString)));
    connect(this->playvdthread,SIGNAL(sendpicoutcaremit(QString,QString)),this,SLOT(getoutpicslot(QString,QString)));



    connect(this->playvdthread,SIGNAL(emitsendincarinfo()),this,SLOT(sendincarinfo()));
    connect(this->playvdthread,SIGNAL(emitsendoutcarinfo()),this,SLOT(sendoutcarinfo()));


}




void MainWin::paintEvent(QPaintEvent *e)
{

    if(this->Btnflag==1)
    {
        QImage q_image = QImage(frame.data,frame.cols,frame.rows,QImage::Format_RGB888);
        ui->LabInImg->setPixmap(QPixmap::fromImage(q_image));
        ui->LabInImg->setScaledContents(true);
    }
    else if(this->Btnflag==2)
    {

        QImage q_image = QImage(frame.data,frame.cols,frame.rows,QImage::Format_RGB888);
        ui->LabOutImg->setPixmap(QPixmap::fromImage(q_image));
        ui->LabOutImg->setScaledContents(true);

    }
    else if(this->Btnflag==3)
    {

        QImage q_image = QImage(frame.data,frame.cols,frame.rows,QImage::Format_RGB888);
        ui->LabParkimg->setPixmap(QPixmap::fromImage(q_image));
        ui->LabParkimg->setScaledContents(true);

    }
    else if(this->Btnflag==4)//回放视频播放
    {

        QImage q_image = QImage(frame.data,frame.cols,frame.rows,QImage::Format_RGB888);
        ui->label_7->setPixmap(QPixmap::fromImage(q_image));
        ui->label_7->setScaledContents(true);

    }

}

MainWin::~MainWin()
{
    delete ui;
}

MainWin *MainWin::getInstance()
{
    MainWin *mainw;
    if(mainw->pmainw==nullptr)
    {
        mainw->pmainw=new MainWin();
    }
    return  mainw->pmainw;
}

//更新系统时间
void MainWin::timeUpdate(void)
{
    datetime1 = QDateTime::currentDateTime();
    ui->LabCurrentTime->setText("当前系统时间: "+datetime1.toString("yyyy-MM-dd hh:mm:ss ddd"));
}
//发送入场车辆信息给服务器
void MainWin::sendincarinfo()
{

    QString icn=ui->EditInCarNum->text();
    QString ict=ui->EditInTime->text();
//    qDebug()<<"************icn*****************"<<icn;
//    qDebug()<<"************ict*****************"<<ict;
////    const char*InCarnum=icn.toStdString().c_str();
    QByteArray ba = icn.toLocal8Bit();
    char *incarn=ba.data();//车牌号
    char *incart=ict.toLatin1().data();//入场时间

    //注意：不能直接char* chTest = strTest.toLocal8Bit().data()，否则还是会乱码

//    qDebug()<<"************incart*****************"<<incart;
//    qDebug()<<"************incarn*****************"<<incarn;
    memcpy(this->carinfo3.carNum,incarn,sizeof (this->carinfo3.carNum));
    memcpy(this->carinfo3.inDate,incart,sizeof (this->carinfo3.inDate));
    memcpy(this->carinfo3.parkLocation,"north",sizeof (this->carinfo3.parkLocation));
    memcpy(this->carinfo3.inDatePhoto,this->inpicpath.toStdString().c_str(),sizeof (this->carinfo3.inDatePhoto));
    qDebug()<<"*****************************"<<this->inpicpath;
    qDebug()<<"************this->carinfo3.carNum*****************"<<this->carinfo3.carNum;
    qDebug()<<"************this->carinfo3.inDate*****************"<<this->carinfo3.inDate;
    this->carinfo3.isVip=false;
    this->carinfo3.charge=0;
    memcpy(this->carinfo3.outDate,"0",sizeof (this->carinfo3.outDate));
    memcpy(this->carinfo3.outDatePhoto,"0",sizeof (this->carinfo3.outDatePhoto));

    this->head.businessType=3;//入场车辆信息
    this->head.businessLength=sizeof(this->carinfo3);
    this->head.acceptfd=0;


    qDebug()<<"head.businesslength = "<<this->head.businessLength;
    memset(buf,0,sizeof (buf));
    memcpy(this->buf,&(this->head),sizeof(HEAD));//头写进去
    qDebug()<<"sizeof(this->head) = "<<sizeof(this->head);
    qDebug()<<"bufsize1 = "<<sizeof (buf);
    memcpy(this->buf+sizeof(HEAD),&(this->carinfo3),sizeof(this->carinfo3));//指针偏移，存两个结构体
    qDebug()<<"sizeof(this->carinfo) = "<<sizeof(this->carinfo3);
    qDebug()<<"bufsize = "<<sizeof (buf);

    this->wt->setData(&(this->buf),sizeof(this->buf));//要发送的数据传给写线程进行ｗｒｉｔｅ

    //创建发送图片文件线程
    QString inname=this->inpicname.toStdString().c_str();
    QString inpath=this->inpicpath.toStdString().c_str();
    qDebug()<<"inname1 = "<<inname;
    qDebug()<<"inpath1 = "<<inpath;
    this->sdpicflthread=new SendPicFilesThread(1,inname.toLatin1().data(),inpath.toLatin1().data());//const char*转ｃｈａｒ×
    qDebug()<<"inname2 = "<<inname.toLatin1().data();
    qDebug()<<"inpath2 = "<<inpath.toLatin1().data();
    this->sdpicflthread->start();
    qDebug()<<"----－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－ ";

}
//向服务器发送出场车辆信息
void MainWin::sendoutcarinfo()
{
//    const char*outCarnum=ui->EditCarNum->text().toStdString().c_str();//车牌号
//    const char*outCartime=ui->EditOuttime->text().toStdString().c_str();//入场时间

    QString ocn=ui->EditCarNum->text();
    QString oct=ui->EditOuttime->text();

    QByteArray ba = ocn.toLocal8Bit();
    char *ocarn=ba.data();//车牌号
    char *ocart=oct.toLatin1().data();//入场时间


    memcpy(this->carinfo6.carNum,ocarn,sizeof (this->carinfo6.carNum));
    memcpy(this->carinfo6.outDate,ocart,sizeof (this->carinfo6.outDate));
    memcpy(this->carinfo6.parkLocation,"north",sizeof (this->carinfo6.parkLocation));
    memcpy(this->carinfo3.outDatePhoto,this->outpicpath.toStdString().c_str(),sizeof (this->carinfo3.outDatePhoto));
    qDebug()<<"*****************************outCartime="<<ocarn;
    qDebug()<<"*****************************outCarnum="<<ocart;
    qDebug()<<"*****************************this->carinfo6.carNum="<<this->carinfo6.carNum;
    qDebug()<<"*****************************this->carinfo6.outDate="<<this->carinfo6.outDate;
    qDebug()<<"*************this->ｉｓｖｉｐ****************"<<this->isvipp;
    this->carinfo6.isVip=this->isvipp;;
    qDebug()<<"*************this->carinfo6.isVip****************"<<this->isvipp;
    this->carinfo3.charge=0;
    memcpy(this->carinfo6.inDate,"0",sizeof (this->carinfo6.inDate));
    memcpy(this->carinfo3.inDatePhoto,"0",sizeof (this->carinfo3.inDatePhoto));

    this->head.businessType=6;//车辆信息
    this->head.businessLength=sizeof(this->carinfo6);
    this->head.acceptfd=0;

    qDebug()<<"head.businesslength = "<<this->head.businessLength;
    memset(buf,0,sizeof (buf));
    memcpy(this->buf,&(this->head),sizeof(HEAD));//头写进去
    qDebug()<<"sizeof(this->head) = "<<sizeof(this->head);
    qDebug()<<"bufsize1 = "<<sizeof (buf);
    memcpy(this->buf+sizeof(HEAD),&(this->carinfo6),sizeof(this->carinfo6));//指针偏移，存两个结构体
    qDebug()<<"sizeof(this->carinfo) = "<<sizeof(this->carinfo6);
    qDebug()<<"bufsize = "<<sizeof (buf);

    this->wt->setData(&(this->buf),sizeof(this->buf));//要发送的数据传给写线程进行ｗｒｉｔｅ

    this->sdpicflthreado=new SendPicFilesThread(2,outpicname.toLatin1().data(),outpicpath.toLatin1().data());//const char*转ｃｈａｒ×
    qDebug()<<"outpicname = "<<outpicname.toLatin1().data();
    qDebug()<<"outpicpath = "<<outpicpath.toLatin1().data();
    this->sdpicflthreado->start();
    qDebug()<<"----－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－ ";

}
//向服务器发送停车场图片文件
void MainWin::sendpkpicfl()
{
    //创建发送图片文件线程
    QString pkname=this->pkpicname.toStdString().c_str();
    QString pkpath=this->pkpicpath.toStdString().c_str();
    qDebug()<<"pkname1 = "<<pkname;
    qDebug()<<"pkpath1 = "<<pkpath;
    this->sdpicflthreadp=new SendPicFilesThread(5,pkname.toLatin1().data(),pkpath.toLatin1().data());//const char*转ｃｈａｒ×
    qDebug()<<"pkname = "<<pkname.toLatin1().data();
    qDebug()<<"pkpath = "<<pkpath.toLatin1().data();
    this->sdpicflthreadp->start();
    qDebug()<<"----－－－－－－－－－－－－－向服务器发送停车场图片文件－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－ ";
}
//视频列表－按月查询槽函数
void MainWin::radioBtnSlot()
{
    qDebug() << "默认按月查询!!!";
}
//视频列表－按日查询槽函数
void MainWin::radioBtnSlot2()
{
    if (ui->radioButton_2->isChecked())
    {
        ui->treeWidget->expandAll();
        qDebug() << "按日查询!!!";
    }
}
//主界面显示当前登录用户ｉｄ
void MainWin::setUserid(QString value)
{
   ui->label_21->setText("当前用户："+value);
   this->useridd=value.toInt();
   qDebug()<<"useriddddddddddddddddddddddddddddd="<<useridd;
}

void MainWin::updateImage(Mat img)
{
    this->frame = img.clone();
    cvtColor(frame,frame,CV_BGR2RGB);
    this->update();
}
//入场车辆信息－读取服务器反馈
void MainWin::recvincarinfo(int flag)
{

}
//出场车辆信息－读取服务器反馈
void MainWin::recvoutcarinfo(CAR_INFO *carinfo)
{
    qDebug()<<"carinfo.isvip"<<carinfo->isVip;
    qDebug()<<"carinfo.inDate"<<carinfo->inDate;
    //设置车费
    if(carinfo->isVip==true)
    {
        qDebug()<<"车费为０";
        ui->LabCharge->setText("0");
//        ui->ckBox_ism->setChecked(true);//月卡打钩

    }
    else {
        qDebug()<<"车费为1carinfo->charge="<<carinfo->charge;
        char* chargec=nullptr;
        sprintf(chargec,"%d",carinfo->charge);
        ui->LabCharge->setText(chargec);
        qDebug()<<"车费为2chargec="<<chargec;
    }
    //入场时间
    ui->LabInTime->setText(carinfo->inDate);
    qDebug()<<"入场时间carinfo->inDate＝"<<carinfo->inDate;
    //停车时长
    QDateTime time1 = QDateTime::fromString(carinfo->inDate);
    QDateTime time2 = QDateTime::fromString(carinfo->outDate);

    qDebug() << "time2 - time1=" << time1.secsTo(time2);
    ui->LabAllTime->setText(tr("%1").arg(time1.secsTo(time2)));

}
//查询车辆信息－读取服务器反馈
void MainWin::recvsrcarinfo(CAR_INFO *carinfo)
{
 qDebug()<<"服务器反馈查询车辆信息ｓｉｚｅ"<<carinfo[0].inDate;
 for(int i=0;i<3;i++)
 {
     ui->tableWidget_2->insertRow(i);//增加一行
     //插入元素
     ui->tableWidget_2->setItem(i,0,new QTableWidgetItem(i+1));
     ui->tableWidget_2->setItem(i,1,new QTableWidgetItem(carinfo[0].carNum));
     ui->tableWidget_2->setItem(i,2,new QTableWidgetItem(carinfo[0].inDate));
     ui->tableWidget_2->setItem(i,3,new QTableWidgetItem(carinfo[0].outDate));
     ui->tableWidget_2->setItem(i,4,new QTableWidgetItem(carinfo[0].inDatePhoto));
     ui->tableWidget_2->setItem(i,5,new QTableWidgetItem(carinfo[0].outDatePhoto));
     ui->tableWidget_2->setItem(i,5,new QTableWidgetItem(carinfo[0].charge));

     qDebug()<<"车牌信息＝"<<carinfo[i].carNum;
     qDebug()<<"入场时间＝"<<carinfo[i].inDate;
     qDebug()<<"出场时间＝"<<carinfo[i].outDate;
     qDebug()<<"入场图片＝"<<carinfo[i].inDatePhoto;
     qDebug()<<"出场图片＝"<<carinfo[i].outDatePhoto;
     qDebug()<<"停车金额＝"<<carinfo[i].charge;
 }
  qDebug()<<"查询车辆数据插入表格数据成功";
// int RowCont;
// RowCont=ui->tableWidget_2->rowCount();
// ui->tableWidget_2->insertRow(RowCont);//增加一行

// //插入元素
// ui->tableWidget_2->setItem(RowCont,0,new QTableWidgetItem("1"));
// ui->tableWidget_2->setItem(RowCont,1,new QTableWidgetItem("KeyWord"));
// ui->tableWidget_2->setItem(RowCont,2,new QTableWidgetItem("PaperBrief"));
}
//从线程获取入场图片名字、路径
void MainWin::getinpicslot(QString inpicname,QString inpicpath)
{
    this->inpicname=inpicname;
    this->inpicpath=inpicpath;
    qDebug()<<"inpicname))))))))))))))))))))))))))))))))"<<this->inpicname;
    qDebug()<<"inpicpath))))))))))))))))))))))))))))))))"<<this->inpicpath;
}
//从线程获取出场图片名字、路径
void MainWin::getoutpicslot(QString outpicname,QString outpicpath)
{
    this->outpicname=outpicname;
    this->outpicpath=outpicpath;
    qDebug()<<"outpicname))))))))))))))))))))))))))))))))"<<this->outpicname;
    qDebug()<<"outpicpath))))))))))))))))))))))))))))))))"<<this->outpicpath;
}
//从线程获取停车场图片名字、路径
void MainWin::getpkpicslot(QString pkpicname, QString pkpicpath)
{
    this->pkpicname=pkpicname;
    this->pkpicpath=pkpicpath;
    qDebug()<<"pkpicname))))))))))))))))))))))))))))))))"<<this->pkpicname;
    qDebug()<<"pkpicpath))))))))))))))))))))))))))))))))"<<this->pkpicpath;
}
//图片信息－读取服务器反馈
void MainWin::recvphotoinfo(int flag)
{
    //在图片文件线程里读取过了
}
//上传视频信息－－读取服务器反馈
void MainWin::recvdinfo(int flag)
{

}
//视频信息－读取服务器反馈
void MainWin::recvideoinfo(VIDEO *videoinf)
{
    int i=this->SumSruct();
//    size_t i = sizeof(videoinf) / sizeof(videoinf[0]);
    qDebug()<<"一共查询到"<<i<<"条视频信息";
    ui->listWidget->clear();
    qDebug()<<"服务器反馈视频信息ｓｉｚｅ"<<videoinf[0].size;

    ui->listWidget->setIconSize(QSize(100, 100));          //设置QListWidget中的单元项的图片大小
    ui->listWidget->setResizeMode(QListView::Adjust);
    ui->listWidget->setViewMode(QListView::IconMode);   //设置QListWidget的显示模式
    ui->listWidget->setMovement(QListView::Static);     //设置QListWidget中的单元项不可被拖动
    ui->listWidget->setSpacing(10);

    for(int nIndex = 0; nIndex < 6; ++nIndex)
    {
          QDir dir;
          QString strPath = QString("./image/1.jpg");//视频封面路径
          QString path = dir.absoluteFilePath(strPath);
          QPixmap objPixmap(path);
          QListWidgetItem *pItem = new QListWidgetItem(QIcon(objPixmap.scaled(QSize(140,140))),videoinf[nIndex].filepath);//视频路径显示到封面下
          pItem->setSizeHint(QSize(140, 160));
          ui->listWidget->insertItem(nIndex, pItem);

          qDebug()<<"视频回放反馈视频名字：videoinf[nIndex].videoname"<<videoinf[nIndex].videoname;
          qDebug()<<"this->videoinfo[0].size"<<videoinf[nIndex].size;
          qDebug()<<"this->videoinfo[0].videoname"<<videoinf[nIndex].videoname;
          qDebug()<<"this->videoinfo[0].uptime"<<videoinf[nIndex].uptime;
          qDebug()<<"this->videoinfo[0].filepath"<<videoinf[nIndex].filepath<<endl;

    }

    //ui->listWidget->currentItem()->text();//获取选中item文本---视频路径
    //以上应该已经显示了视频列表，下面获取视频路径，传给视频播放线程，在播放页面播放－－－创建播放视频线程

//    qDebug()<<""<<i<<"条视频信息";






}

//停车场－入场
void MainWin::on_BtnIn_clicked()
{
    this->Btnflag=1;
    ui->stackedWidget->setCurrentIndex(0);

    //判断当前是否有线程在运行
   if(this->playvdthreadp->isFinished()==false)//在运行，结束它，开启下个新线程
   {

       this->playvdthreadp->threadPause();

//       qDebug()<<"isFinished="<<this->playvdthreadp->isFinished();


   }
   qDebug()<<"isFinished11="<<this->playvdthreadp->isFinished();

   this->playvdthread->threadContin();
}

//停车场－出场模式
void MainWin::on_BtnOut_5_clicked()
{
   this->Btnflag=2;
   ui->stackedWidget->setCurrentIndex(1);

   //判断当前是否有线程在运行
  if(this->playvdthreadp->isFinished()==false)//在运行，结束它，开启下个新线程
  {

      this->playvdthreadp->threadPause();

//      qDebug()<<"isFinished="<<this->playvdthreadp->isFinished();

  }
  qDebug()<<"isFinished11="<<this->playvdthreadp->isFinished();

  this->playvdthread->threadContin();


}

//出场－＞车牌
void MainWin::on_BtnOGetCarNum_clicked()
{
//    qDebug()<<"c11111";
    this->parksps++;
    ui->label_22->setText("剩余车位："+QString::number(this->parksps));

    this->playvdthread->setStorepicflag(1);
    this->playvdthread->setPictypeflag(2);
    //出场时间
    QDateTime datetime3 = QDateTime::currentDateTime();
    QString Intime=datetime3.toString("yyyy-MM-dd hh:mm:ss");
    ui->EditOuttime->setText(Intime);

    Mat car_number;

    int result = pr.plateRecognize(this->frame,plateVec);
    qDebug()<<"result ="<<result;
    if(result == 0)
    {

        plate =plateVec.at(0);  //car info
        plateMat = plate.getPlateMat(); // car number;
        cvtColor(plateMat,car_number,CV_BGR2RGB);
        cvtColor(car_number,car_number,CV_BGR2RGB);
        QImage q_image = QImage(car_number.data,car_number.cols,car_number.rows,QImage::Format_RGB888);
        //保存车牌
        QString fileName="CN_O-"+ QDateTime::currentDateTime().toString("MM-dd-HH-ss")  + ".jpg";//通过时间命名文件
        imwrite("./pic/carnum/"+fileName.toStdString(),car_number);

        ui->LabOCarNumimg->setPixmap(QPixmap::fromImage(q_image));
        ui->LabOCarNumimg->setScaledContents(true);

        string  str_car_num = plateVec[0].getPlateStr();
        QString q_str = QString::fromLocal8Bit(str_car_num.c_str());
        ui->EditCarNum->clear();
        ui->EditCarNum->insert(q_str);
//        sendoutcarinfo();
/*        QString ONumpath="./pic/carnum/"+fileName;
        this->sdpicflthreadob=new SendPicFilesThread(4,fileName.toLatin1().data(),ONumpath.toLatin1().data());//const char*转ｃｈａｒ×
        qDebug()<<"fileName = "<<fileName.toLatin1().data();
        qDebug()<<"ONumpath = "<<ONumpath.toLatin1().data();
        this->sdpicflthreadob->start();
        qDebug()<<"----－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－ ";
 */   }
    plateVec.clear();
}
//入场车牌
void MainWin::on_BtnInGetCarNum_clicked()
{
    this->parksps--;
    ui->label_22->setText("剩余车位："+QString::number(this->parksps));

    this->playvdthread->setStorepicflag(1);
    this->playvdthread->setPictypeflag(1);


    QDateTime datetime2 = QDateTime::currentDateTime();
    QString Intime=datetime2.toString("yyyy-MM-dd-hh-mm-ss");
    ui->EditInTime->setText(Intime);
    Mat car_number;

    int result = pr.plateRecognize(this->frame,plateVec);
    qDebug()<<"result ="<<result;
    if(result == 0)
    {
        plate =plateVec.at(0);  //car info
        plateMat = plate.getPlateMat(); // car number;
        cvtColor(plateMat,car_number,CV_BGR2RGB);
        cvtColor(car_number,car_number,CV_BGR2RGB);
        QImage q_image = QImage(car_number.data,car_number.cols,car_number.rows,QImage::Format_RGB888);
        //保存车牌
        QString fileName="CN_IN-"+ QDateTime::currentDateTime().toString("MM-dd-HH-ss")  + ".jpg";//通过时间命名文件
        imwrite("./pic/carnum/"+fileName.toStdString(),car_number);

        ui->LabInCarNumImg->setPixmap(QPixmap::fromImage(q_image));
        ui->LabInCarNumImg->setScaledContents(true);

        string  str_car_num = plateVec[0].getPlateStr();
        QString q_str = QString::fromLocal8Bit(str_car_num.c_str());
        ui->EditInCarNum->clear();
        ui->EditInCarNum->insert(q_str);
        qDebug()<<"EditInCarNum1 ="<<ui->EditInCarNum->text();
//        sendincarinfo();//向服务器发送入场信息

        QString Inumpath="./pic/carnum/"+fileName;

        this->sdpicflthreadib=new SendPicFilesThread(3,fileName.toLatin1().data(),Inumpath.toLatin1().data());//const char*转ｃｈａｒ×
        qDebug()<<"fileName = "<<fileName.toLatin1().data();
        qDebug()<<"Inumpath = "<<Inumpath.toLatin1().data();
        this->sdpicflthreadib->start();
        qDebug()<<"----－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－ ";

    }
    plateVec.clear();
}
//入场修改车牌
void MainWin::on_BtnInChangeNum_clicked()
{

}
//出场－入场
void MainWin::on_BtnIn_2_clicked()
{
    this->Btnflag=1;
    ui->stackedWidget->setCurrentIndex(0);

    //判断当前是否有线程在运行
   if(this->playvdthreadp->isFinished()==false)//在运行，结束它，开启下个新线程
   {

       this->playvdthreadp->threadPause();

//       qDebug()<<"isFinished="<<this->playvdthreadp->isFinished();


   }
   qDebug()<<"isFinished11="<<this->playvdthreadp->isFinished();

   this->playvdthread->threadContin();
}
//入场－出场
void MainWin::on_BtnOut_6_clicked()
{

    this->Btnflag=2;

    ui->stackedWidget->setCurrentIndex(1);

}
//出场　停车场
void MainWin::on_BtnMngParkn_7_clicked()
{
    this->Btnflag=3;
    ui->stackedWidget->setCurrentIndex(2);

    //判断当前是否有线程在运行
   if(this->playvdthread->isFinished()==false)//在运行，结束它，开启下个新线程
   {

       this->playvdthread->threadPause();

       qDebug()<<"isFinisheddd="<<this->playvdthread->isFinished();
   }

       playvdthreadp = new PlayVdThread("./video/parking1.mp4");
       connect(this->playvdthreadp,SIGNAL(frameVideo(Mat)),this,SLOT(updateImage(Mat)),Qt::BlockingQueuedConnection);
       this->playvdthreadp->start();
       qDebug()<<"isRunning="<<this->playvdthreadp->isRunning();

       connect(this->playvdthreadp,SIGNAL(sendpicpkcaremit(QString,QString)),this,SLOT(getpkpicslot(QString,QString)));
       connect(this->playvdthreadp,SIGNAL(emitsendpkcarinfo()),this,SLOT(sendpkpicfl()));
}
//入场　停车场
void MainWin::on_BtnMngParkn_6_clicked()
{
    this->Btnflag=3;
    ui->stackedWidget->setCurrentIndex(2);

    //判断当前是否有线程在运行
   if(this->playvdthread->isFinished()==false)//在运行，结束它，开启下个新线程
   {
       this->playvdthread->threadPause();

       qDebug()<<"isFinished="<<this->playvdthread->isFinished();
   }
   qDebug()<<"isFinished11="<<this->playvdthread->isFinished();
   //开始下个线程，进场车辆车牌的检测
   playvdthreadp = new PlayVdThread("./video/parking1.mp4");
   connect(this->playvdthreadp,SIGNAL(frameVideo(Mat)),this,SLOT(updateImage(Mat)),Qt::BlockingQueuedConnection);
   this->playvdthreadp->start();

   connect(this->playvdthreadp,SIGNAL(sendpicpkcaremit(QString,QString)),this,SLOT(getpkpicslot(QString,QString)));
   connect(this->playvdthreadp,SIGNAL(emitsendpkcarinfo()),this,SLOT(sendpkpicfl()));

}
//停车场抓拍
void MainWin::on_pushButton_5_clicked()
{
     this->playvdthreadp->setStorepicflag(1);//保存图片
     this->playvdthreadp->setPictypeflag(3);//类型　停车场
}
//停车场，手动录制视频
void MainWin::on_pushButton_4_clicked()
{
//    qDebug()<<"00000000000手动录制视频";
    this->playvdthreadp->setVidflag(1);
//    qDebug()<<"11111111111手动录制视频";
    connect(this->playvdthreadp,SIGNAL(sendvdinfoemit(QString,QString,QString,int,int)),this,SLOT(getvdimfpslot(QString,QString,QString,int,int)));
//    qDebug()<<"22222222222手动录制视频";

}
//入场　设置
void MainWin::on_BtnSettings_6_clicked()
{

    emit emitosetw();
}

//chu场　设置
void MainWin::on_BtnSettings_7_clicked()
{
     emit emitosetw();
}
//tingche　设置
void MainWin::on_BtnSettings_5_clicked()
{
    emit emitosetw();
}
//自动录制视频
void MainWin::on_checkBox_stateChanged(int arg1)
{
    bool status =ui->checkBox->isChecked();
    qDebug()<<"status"<<status;
    if(status == true)
    {
        this->playvdthreadp->setVidflag(2);
      qDebug()<<"每隔３０ｓ，自动录制视频";
      connect(this->playvdthreadp,SIGNAL(sendvdinfoemit(QString,QString,QString,int,int)),this,SLOT(getvdimfpslot(QString,QString,QString,int,int)));


    }
    else if(status == false)
    {
      this->playvdthreadp->setVidflag(0);
      qDebug()<<"！！！自动录制视频结束";
    }

}
//是否是月卡
void MainWin::on_ckBox_ism_stateChanged(int arg1)
{

    bool status =ui->ckBox_ism->isChecked();
    qDebug()<<"status"<<status;
    if(status == true)
    {
      qDebug()<<"月卡　收费金额为０";
      ui->LabCharge->setText("0");
      this->isvipp=true;

    }
    else if(status == false)
    {
      qDebug()<<"照常收费";
    }
}
//停车场－>监控回放
void MainWin::on_pushButton_clicked()
{
    this->Btnflag=4;
    ui->stackedWidget->setCurrentIndex(3);

    this->playvdthreadp->threadPause();//停车场线程暂停
}
//监控回放－>停车场
void MainWin::on_pushButton_2_clicked()
{
    this->Btnflag=3;
    ui->stackedWidget->setCurrentIndex(2);
}
//监控列表－>播放视频测试１
void MainWin::on_pushButton_12_clicked()
{
    this->Btnflag=5;
    ui->stackedWidget->setCurrentIndex(4);
}
//视频回放界面－>监控视频列表
void MainWin::on_pushButton_20_clicked()
{
    this->Btnflag=4;
    ui->stackedWidget->setCurrentIndex(3);
}
//从线程获取视频信息槽函数:直接在这里将视频信息发给服务器
void MainWin::getvdimfpslot(QString vdname, QString vdtime, QString vdpath, int vdsize,int vdframes)
{
//    this->vdname=vdname.toStdString().c_str();
//    this->vdpath=vdpath.toStdString().c_str();
//    this->vdtime=vdtime.toStdString().c_str();
    this->vdsize=vdsize;
    this->vdframes=vdframes;
    qDebug()<<"*****************************vdsize="<<this->vdsize;
    qDebug()<<"*****************************vdframes="<<vdframes;
    qDebug()<<"*****************************vdname"<<vdname;
    const char *vdnm=vdname.toStdString().c_str();
    char *vdpth=vdpath.toLatin1().data();
//    char *vdtim=vdtime.toLatin1().data();

    qDebug()<<"*****************************vdpth="<<vdpth;
    qDebug()<<"*****************************vdnm"<<vdnm;
    qDebug()<<"*111this->videoinfo.videoname="<<this->videoinfo.videoname;

    memset(this->videoinfo.videoname,0,sizeof(this->videoinfo.videoname));
    memset(this->videoinfo.filepath,0,sizeof(this->videoinfo.filepath));
    memset(this->videoinfo.uptime,0,sizeof(this->videoinfo.uptime));
    qDebug()<<"*111222this->videoinfo.videoname="<<this->videoinfo.videoname;

    memcpy(this->videoinfo.videoname,vdname.toLatin1().data(),sizeof(this->videoinfo.videoname));
    memcpy(this->videoinfo.filepath,vdpth,sizeof(this->videoinfo.filepath));
    memcpy(this->videoinfo.uptime,vdtime.toStdString().c_str(),sizeof(this->videoinfo.uptime));
    this->videoinfo.userid=this->useridd;
    qDebug()<<"*****************************this->userid="<<this->useridd;
    this->videoinfo.size=this->vdsize;
    this->videoinfo.allFrames=this->vdframes;
    qDebug()<<"*****************************this->videoinfo.size="<<this->videoinfo.size;
    qDebug()<<"*****************************this->videoinfo.allFrames="<<this->videoinfo.allFrames;
    qDebug()<<"*****************************this->videoinfo.userid="<<this->videoinfo.userid;

    this->videoinfo.showrecord=0;

    qDebug()<<"*********33333***this->videoinfo.videoname="<<this->videoinfo.videoname;
    qDebug()<<"*****************************filepath="<<this->videoinfo.filepath;
    qDebug()<<"*****************************uptime"<<this->videoinfo.uptime;
    qDebug()<<"************vdname.toLatin1().data()***************this->carinfo6.outDate="<<vdname.toLatin1().data();


    this->head.businessType=5;//视频信息
    this->head.businessLength=sizeof (this->videoinfo);
    this->head.acceptfd=0;

    qDebug()<<"head.businesslength = "<<this->head.businessLength;
    memset(buf,0,sizeof (buf));
    memcpy(this->buf,&(this->head),sizeof(HEAD));//头写进去
    qDebug()<<"sizeof(this->head) = "<<sizeof(this->head);
    qDebug()<<"bufsize1 = "<<sizeof (buf);
    memcpy(this->buf+sizeof(HEAD),&(this->videoinfo),sizeof(this->videoinfo));//指针偏移，存两个结构体
    qDebug()<<"sizeof(this->videoinfo) = "<<sizeof(this->videoinfo);
    qDebug()<<"bufsize = "<<sizeof (buf);

    this->wt->setData(&(this->buf),sizeof(this->buf));//要发送的数据传给写线程进行ｗｒｉｔｅ
}
//放行
void MainWin::on_BtnGo_clicked()
{
    QMessageBox::information(NULL,"title","车辆可以离开");
}
//停车场－>查询车辆信息
void MainWin::on_BtnQueryCar_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}
//出场－>查询车辆信息
void MainWin::on_BtnQueryCar_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}
//入场－>查询车辆信息
void MainWin::on_BtnQueryCar_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}
//查询车辆信息按钮槽函数---发送查询条件给服务器
void MainWin::on_BtnSerchCarinfo_clicked()
{
    qDebug()<<"  查询车辆信息按钮槽函数---发送查询条件给服务器";
    //发送编辑框数据给服务器
    QString srcarnum=ui->Editsrchcarnum->text();
    QString srintime=ui->Editsrchintime->text();
    QString sroutime=ui->Editserchoutime->text();


    //判断编辑框是否为空
    if(srcarnum==0&&srintime==0&&sroutime==0)
    {
        QMessageBox::information(NULL,"title","输入不能为空！");

    }
    else
    {
//        const char *psrcarnum=srcarnum.toStdString().c_str();
//        const char *psrintime=srintime.toStdString().c_str();
//        const char *psroutime=sroutime.toStdString().c_str();



        memcpy(this->carinfo7.carNum,srcarnum.toLatin1().data(),sizeof (this->carinfo7.carNum));
        memcpy(this->carinfo7.inDate,srintime.toLatin1().data(),sizeof (this->carinfo7.inDate));
        memcpy(this->carinfo7.outDate,sroutime.toLatin1().data(),sizeof (this->carinfo7.outDate));

        memcpy(this->carinfo3.inDatePhoto,"0",sizeof (this->carinfo3.inDatePhoto));
        memcpy(this->carinfo3.outDatePhoto,"0",sizeof (this->carinfo3.outDatePhoto));
        memcpy(this->carinfo7.parkLocation,"0",sizeof (this->carinfo7.parkLocation));
        this->carinfo7.isVip=false;
        this->carinfo3.charge=0;

        qDebug()<<"*****************************this->carinfo7.carNum="<<this->carinfo7.carNum;
        qDebug()<<"*****************************this->carinfo7.inDate"<<this->carinfo7.inDate;
        qDebug()<<"this->carinfo7.outDate="<<this->carinfo7.outDate;


        this->head.businessType=7;//查询车辆信息
        this->head.businessLength=sizeof(this->carinfo7);
        this->head.acceptfd=0;

        memset(buf,0,sizeof (buf));
        memcpy(this->buf,&(this->head),sizeof (HEAD));
        memcpy(this->buf+sizeof(HEAD),&(this->carinfo7),sizeof (CAR_INFO));

        this->wt->setData(&(this->buf),sizeof (this->buf));

    }
 qDebug()<<"  发送完毕－－查询车辆信息按钮槽函数---发送查询条件给服务器";
}
//车辆信息查询－＞入场
void MainWin::on_BtnRetnMain_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    this->playvdthread->threadContin();
}
//树形布局－－视频日期目录－－上传服务器－－查找日期对应视频信息
void MainWin::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{

    QString itemtext=item->text(column);//获取点击到的节点名--->日期传给服务器
    int row=ui->treeWidget->currentIndex().row();//获取点击到的节点的行数
    qDebug()<<"row="<<row<<"   itemtext="<<itemtext;
    if(item->parent())
    {
        qDebug()<<"  有父节点"<<item->parent()->text(column);

    }

    if(itemtext=="2022-06"||itemtext=="2022-07")
    {
//        ui->stackedWidget_2->setCurrentIndex(3);//显示对应的页面
    }
    else
    {
        int row=ui->treeWidget->currentIndex().row();//获取点击到的节点的行数
//        ui->stackedWidget_2->setCurrentIndex(row);//显示对应的页面
        qDebug()<<"row="<<row<<"   itemtext="<<itemtext;
    }



    //上传服务器－－查找日期对应视频信息
    memcpy(this->videoinfo.videoname,"0",sizeof(this->videoinfo.videoname));
    memcpy(this->videoinfo.filepath,"0",sizeof(this->videoinfo.filepath));
    memcpy(this->videoinfo.uptime,itemtext.toStdString().c_str(),sizeof(this->videoinfo.uptime));
    this->videoinfo.size=0;
    this->videoinfo.allFrames=0;
    this->videoinfo.showrecord=0;
//    qDebug()<<"itemtext.toStdString().c_str()"<<itemtext.toStdString().c_str();
//    qDebug()<<"itemtext"<<itemtext;

    qDebug()<<"上传服务器视频日期－videoinfo.uptim"<<this->videoinfo.uptime;

    this->head.businessType=8;//视频信息
    this->head.businessLength=sizeof (this->videoinfo);
    this->head.acceptfd=0;

    qDebug()<<"head.businesslength = "<<this->head.businessLength;
    memset(buf,0,sizeof (buf));
    memcpy(this->buf,&(this->head),sizeof(HEAD));//头写进去
    qDebug()<<"sizeof(this->head) = "<<sizeof(this->head);
    qDebug()<<"bufsize1 = "<<sizeof (buf);
    memcpy(this->buf+sizeof(HEAD),&(this->videoinfo),sizeof(this->videoinfo));//指针偏移，存两个结构体
    qDebug()<<"sizeof(this->videoinfo) = "<<sizeof(this->videoinfo);
    qDebug()<<"bufsize = "<<sizeof (buf);

    this->wt->setData(&(this->buf),sizeof(this->buf));//要发送的数据传给写线程进行ｗｒｉｔｅ

}

//视频列表点击某一封面　槽函数
void MainWin::on_listWidget_itemClicked(QListWidgetItem *item)
{
    ui->stackedWidget->setCurrentIndex(4);//视频播放界面
    this->Btnflag=4;//视频回放界面
    qDebug()<<"点击某一封面，视频名为=="<<ui->listWidget->currentItem()->text();



    vdbackpath=(ui->listWidget->currentItem()->text()).toStdString().c_str();
    this->playbackkvdthread=new PlayBackVdThread(this->vdbackpath.toLatin1().data());
    qDebug()<<"回放视频路径－－this->vdbackpath.toLatin1().data()"<<this->vdbackpath.toLatin1().data();
    connect(this->playbackkvdthread,SIGNAL(frameVideo(Mat)),this,SLOT(updateImage(Mat)),Qt::BlockingQueuedConnection);
    this->playbackkvdthread->start();
    qDebug()<<"回放视频start";
}
//回放视频暂停槽函数
void MainWin::on_pushButton_19_clicked()
{
    //如何获取按钮的名字
    QPushButton *btntemp=(QPushButton *)sender();
    qDebug()<<btntemp->text();
    if(QString::compare(btntemp->text(),"暂停")==0)
    {
        this->playbackkvdthread->threadPause();
        ui->pushButton_19->setText("继续");
    }
    else if (QString::compare(btntemp->text(),"继续")==0) {
        this->playbackkvdthread->threadContin();
        ui->pushButton_19->setText("暂停");
    }

}
