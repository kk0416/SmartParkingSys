#ifndef PROTOCOL_H
#define PROTOCOL_H

typedef struct protocolhead
{
    int businessType;//业务类型，登录1，注册2 入场信息３　图片信息４ 视频信息５出场信息６　查询车辆信息７
    int businessLength;//业务长度，登录40字节，聊天140字节
    int acceptfd;
}HEAD;
// 反馈
typedef struct feedback {
    int businesstype;
    int businesslen;
    int flag;//如果是登录（0-成功；1-账号不存在或者账号错误；2-密码错误）；注册（0-成功；1-重复注册）
    int acceptfd;
    int model;
}FEEDBACK;
//通信协议体==业务数据
typedef struct login
{
    char userid[10];
    char username[20];
    char passward[12];
}LOGIN;
typedef struct regist
{
    char userid[10];
    char username[20];
    char passward[12];
}REG;
//心跳
typedef struct heart
{
    int heartbeat_time;//心跳时长
    int time_span;//间隔时间
    int required_time;//规定时长
}HEART;
typedef struct videos
{
    char videoname[30];//文件名
    char uptime[30];//上传时间
    int userid;
    char filepath[40];//路径
    long size;//文件大小
    int showrecord;//播放时长
    int allFrames;//视频总帧数
}VIDEO;
typedef struct photos
{
    int type;//1-车牌，2-车辆 3-抓拍
    int all_size;//总长度
    int AllNum;//一共有几个包
    int NowNum;//当前是第几个包
    int currentSize;//当前包的长度
    char file_name[30];//文件名
    char block_data[1028];//碎片文件数据
}PHOTO;

typedef struct car_info
{
    bool isVip;//是否有月卡
    double charge;//费用
    char carNum[20];//车牌
    char parkLocation[20];//停车地点
    char inDate[25];//入场日期
    char outDate[25];//出场日期
    char inDatePhoto[50];
    char outDatePhoto[50];
}CAR_INFO;

typedef struct Pi {
    int x;
    int y;
} Pc;
#endif // PROTOCOL_H
