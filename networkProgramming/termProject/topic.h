#ifndef TOPIC_H
#define TOPIC_H

#include <stdio.h>
#include <string.h> //for strlen()
#include <stdlib.h> //for atoi()
#include <time.h> //for timestamp
#include <sys/poll.h> //for pollfd

#define SUB_NUM 3
#define PUB_NUM 3
#define TBOX_NUM 3
#define CLI_NUM 13

#define MSG_SIZE 300
#define TBOXNUM_INDEX_SIZE 3
#define FD_INDEX_SIZE 5
#define TIME_INDEX_SIZE 30
#define INIT 0
#define PUB 1
#define SUB 2

//#define test(x) printf("%s\n", x);

struct clientInfo {
	int subfd[SUB_NUM];
	int pubfd;
	int tBoxNum;
};

//문제 < c-i >
//구조체로 정의한 Topic Message 부분이다.
struct TopicMsg {
	char msg[MSG_SIZE]; //message
	//문제 < c-iii >
	//문제에서 요구한대로 각 메세지에는 마지막에 timestamp를 포함하도록 하였다.
	char timeInfo[TIME_INDEX_SIZE]; //save timestamp as character
};

struct TopicBox {
	struct clientInfo clientId;
	TopicMsg tMsg;
	bool hasMsg;
	bool isActivePub;
};

void initTopicMsg(struct TopicMsg *tMsg);
void initTopicBox(struct TopicBox *tBox);
void err(const char *str);

#endif