#include "socketconnect.h"
#include<string>
SocketConnect * SocketConnect::sc=nullptr;//静态变量初始化
//编写socket函数，定义socketfd
SocketConnect::SocketConnect()
{
    //初始化变量
    this->socketfd=socket(AF_INET, SOCK_STREAM, 0);
    this->length=sizeof (this->s_addr);

    this->ip=nullptr;
    this->port=0;

//    connect()
}

void SocketConnect::setIp(const char *value)
{
    ip = value;
    qDebug()<<"ip--"<<ip;
}

void SocketConnect::setPort(int value)
{
    port = value;
    qDebug()<<"port--"<<port;
}

////带参槽函数获取ｉｐ\port（未使用）
//void SocketConnect::getipp(QString ip,QString port)
//{
//    this->port=port.toInt();
//    this->ip=ip.toStdString().c_str();
//}


//静态函数：用来获取对象
SocketConnect *SocketConnect::getInstance()
{
    if(SocketConnect::sc==nullptr)
    {
        SocketConnect::sc=new SocketConnect();
    }
    return  SocketConnect::sc;
}

//用来准备客户端网络连接
void SocketConnect::CreateConnect()
{

    qDebug()<<"ip是"<<this->ip;
    qDebug()<<"ｐｏｒｔ是"<<this->port;
    int res_connect=4;
    //判断初始化网络是否成功
    if(this->socketfd==-1)
    {
        perror("socket error");
        qDebug()<<"socket error";
    }
    else {
        //协议
        this->s_addr.sin_family=AF_INET;
        //端口号
        this->s_addr.sin_port=htons(this->port);
        //ｉｐ
        this->s_addr.sin_addr.s_addr=inet_addr(this->ip);//服务器

        //地址长度
        this->length=sizeof (this->s_addr);

//        res_connect=::connect(this->socketfd,(struct sockaddr*)&(this->s_addr),this->length);
        if(connect(this->socketfd,(struct sockaddr*)&(this->s_addr),this->length)==-1)
        {
            perror("connect error");
            qDebug()<<"connect error";
//            emit emitisconnect(1);//失败
        }
        else {
            qDebug()<<"connect success";
//            emit emitisconnect(2);//连接成功
        }

    }
}
//关闭socketfd
void SocketConnect::Close(){
    if(this->socketfd==-1)
    {
        perror("socket error");
    }
    else
    {
        close(this->socketfd);
    }
}
//
int SocketConnect::getSocketfd() const
{
    return this->socketfd;
}
//
void SocketConnect::setSocketfd(int value)
{
    this->socketfd = value;
}

