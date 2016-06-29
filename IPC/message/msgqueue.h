//-------------------头文件msgqueue.h ------------------
#ifndef _MAGQUEUE_H_
#define _MAGQUEUE_H_
#include <sys/ipc.h> //包含ftok
#include <sys/msg.h>
#include <sys/types.h>

//消息队列的读 写模式掩码
#define MSG_W 0200
#define MSG_R 0400

//定义众所周知的消息队列键
#define MQ_KEY1 128L

#define DATA_SIZE 512

typedef struct msgbuf
{
    int mtype;
    char mdata[DATA_SIZE];
}mymsg_t;

#endif
