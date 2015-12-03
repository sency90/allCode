#include "topic.h"

void initTopicMsg(struct TopicMsg *tMsg) {
	strcpy(tMsg->msg, '\0');
	time(&(tMsg->tStamp));
	timeinfo = localtime(&(tMsg->tStamp));
}

void initTopicBox(struct TopicBox *tBox) {
	tBox->isActive = false;
	tBox->hasMsg = false;

	for(int i=0; i<SUB_NUM; i++) {
		(tBox->clientId).subfd[i] = INIT;
	}
	(tBox->clientId).pubfd = INIT;
	(tBox->clientId).tBoxNum = INIT;

	initTopicMsg(&(tBox->tMsg));
}

void err(const char *str) {
	printf("Error: %s\n", str);
}