#ifndef TOPIC_H
#define TOPIC_H

#include <stdio.h>
#include <string.h> //for strlen()
#include <stdlib.h> //for atoi()

#define TOPIC_NAME_SIZE 30
#define MSG_SIZE 300
#define ID_SIZE 5

#define NOTHING "__No_MSG__"
#define SUB_NUM 3
#define PUB_NUM 3
//#define PUB_INIT 0
#define PUB_START_INDEX 1 //PUB_INIT+1
#define PUB_END_INDEX 3 //PUB_INIT+PUB_NUM
//#define SUB_INIT 4 //PUB_END
#define SUB_START_INDEX 5 // SUB_INIT+1
#define SUB_END_INDEX 7 // SUB_INIT+SUB_NUM
#define ID_INIT 0

#define ERR_MSG_SIZE 100

struct topicMsg_ID1 {
    char msg[MSG_SIZE];
};

struct topicMsg_ID2 {
    char topic
    char msg[MSG_SIZE];

};

class TopicBox {
public:
    TopicBox(); //creator
    ~TopicBox(); //destructor

public:
    bool hasErr;
    bool hasMsg;
    char errMsg[ERR_MSG_SIZE];

    char topicBoxName[TOPIC_NAME_SIZE];
    int pub_id;
    int sub_id[SUB_NUM]; //ID_INIT이 0이기 때문에 다음과 같이 쓰는것이 가능.

    topicMsg msg[MSG_SIZE];
    //char msg[MSG_SIZE];
};

//topic을 등록하는 대상이 Publisher인지 subscriber인지는 id값으로 판별한다.
//id가 1,2,3이면 publisher이고, 5,6,7이면 subscriber이다.
int topicRegiSend(int sockfd, int id, char *topicBoxName);
TopicBox topicRegiRecv(int sockfd);


int topicMsgSend(int sockfd, int pub_id, char *msg);
TopicBox topicMsgRecv(int sockfd);

#endif