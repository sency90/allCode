#include "topic.h"

void initTopicBox(struct TopicBox *tBox) {
	tBox->isActivePub = false;
	tBox->hasMsg = false;

	for(int i=0; i<SUB_NUM; i++) {
		(tBox->clientId).subfd[i] = -1;
	}
	(tBox->clientId).pubfd = -1;
	(tBox->clientId).tBoxNum = -1;
}

void err(const char *str) {
	printf("Error: %s\n", str);
}
