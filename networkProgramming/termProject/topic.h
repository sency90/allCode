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
#define CLI_NUM ((SUB_NUM * TBOX_NUM) + PUB_NUM + 1)

#define MSG_SIZE 300
#define TBOXNUM_INDEX_SIZE 3
#define FD_INDEX_SIZE 5
#define INIT 0
#define PUB "1"
#define SUB "2"

struct clientInfo {
	int subfd[SUB_NUM];
	int pubfd;
	int tBoxNum;
};

struct TopicMsg {
	char msg[MSG_SIZE];
	time_t tStamp;
	struct tm *timeinfo;
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