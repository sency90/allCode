#ifndef TOPIC_H
#define TOPIC_H

#include <stdio.h>
#include <string.h> //for strlen()
#include <stdlib.h> //for atoi()
#include <time.h> //for timestamp
#include <sys/poll.h> //for pollfd

/*
#include <boost/archive/text_oarchieve.hpp>
#include <boost/archive/text_iarchieve.hpp>
#include <iostream>
#include <sstream>
*/

#define TOPICBOX_NAME_SIZE 20
#define ERR_MSG_SIZE 300
#define MSG_SIZE 300
#define TIMEINFO_SIZE 200
#define ID_SIZE 5

#define NOTHING "__No_MSG__"
#define SUB_NUM 3
#define PUB_NUM 3
#define TOPIC_NUM 3
//#define PUB_INIT 0
#define PUB_START_INDEX 1 //PUB_INIT+1
#define PUB_END_INDEX 3 //PUB_INIT+PUB_NUM
//#define SUB_INIT 4 //PUB_END
#define SUB_START_INDEX 5 // SUB_INIT+1
#define SUB_END_INDEX 7 // SUB_INIT+SUB_NUM
#define ID_INIT 0
#define FAKE_ID -1



class TopicMsg {
public:
	TopicMsg();
	TopicMsg(int topicId);

public:
	int topicBoxId;
	char msg[MSG_SIZE];

	time_t tStamp; //for timestamp
	struct tm *timeinfo;
	char chTimeInfo[TIMEINFO_SIZE];
/*
private:
	friend class boost::serialization::access;

	template <typename Archive>
	void serialize(Archive &ar, const unsigned int version) {
		ar & topicBoxId;
		ar & msg;
	}
*/
};

class TopicBox {
public:
	TopicBox();

public:
	char topicBoxName[TOPIC_NUM + 1][TOPICBOX_NAME_SIZE]; //const variable
	int topicBoxId; // topicBox Identification

	bool hasErr;
	char errMsg[ERR_MSG_SIZE];

	//bool hasTopicMsg;
	TopicMsg topicMsg;

	//ahems tBoxdpeogks wjdqhfmf ekarh dlTek.
	int pubId[TOPIC_NUM]; //It will be set from the broker to the publisher
	int subId[TOPIC_NUM][SUB_NUM]; //It will be set from the broker to the publisher

	bool isPub;

public:
	void recordErr(const char *errMsg);

	int createPubId(int sockfd);
	int createSubId(int sockfd);

	//return: issuedId from the broker
	int sendTopicRegi(int sockfd, bool isPub, int topicBoxId);
	void recvTopicRegi(int sockfd);

	//int sendTopicMsg(int sockfd, bool isPub, int topicBoxId);
	//int sendTopicMsgForPub(int sockfd, int id, TopicMsg *tMsg);
	void sendTopicMsgForPub(int sockfd, int id, TopicMsg tMsg);
	void recvTopicMsgForBro(struct pollfd *pollfds, int *n_pub, int *n_sub);
	void recvTopicMsgForSub(int sockfd);

	const char* btoa(bool b);
	bool atob(char* str);

};

#endif


/*
//The topic ID of this class is 1
class TopicMsgTID1 : public TopicMsg {
public:
	//super();
	TopicMsgTID1();
	~TopicMsgTID1();

public:
	//char msg[MSG_SIZE];
	//int timestamp;

	//other values of this topic (There isn't any meaning on them)
	int just_nothing1;
	char just_nothing2;
	bool just_nothing3;
};

//The topic ID of this class is 2
class TopicMsgTID2 : public TopicMsg {
public:
	TopicMsgTID2();
	~TopicMsgTID2();

public:
	//char msg[MSG_SIZE];
	//int timestamp;

	//other values of this topic (There isn't any menaing on them)
	char just_nothing1[10];
	char* just_nothing2;
};

//The topic ID of this class is 3
class TopicMsgTID3 : public TopicMsg {
public:
	TopicMsgTID3();
	~TopicMsgTID3();

public:
	//char msg[MSG_SIZE];
	//int timestamp;

	//other values of this topic (There isn't any meaning on it)
	int just_nothing1[100];
};
*/
