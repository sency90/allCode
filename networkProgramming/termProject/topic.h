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

struct TopicMsg {
	char msg[MSG_SIZE];
	char timeInfo[TIME_INDEX_SIZE]; //save timestamp as character
};

struct TopicBox {
	struct clientInfo clientId;
	TopicMsg tMsg;
	bool hasMsg;
	bool isActive;
};

void initTopicMsg(struct TopicMsg *tMsg);
void initTopicBox(struct TopicBox *tBox);
void err(const char *str);

#endif