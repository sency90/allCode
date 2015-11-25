#define TOPIC_A struct topicA;
#define MSG_SIZE 300

struct topic_A {
    char topicName[8] = "topic_A";
    char topicMsg[MSG_SIZE];
}

struct topic_B {
    char topicName[8] = "topic_B";
    char topicMsg[MSG_SIZE];
}

struct topic_C {
    char topicName[8] = "topic_C";
    char topicMsg[MSG_SIZE];
}

void topicMsgStore(char *msg);
void topicMsgSend(int id, char *topic_name, char *msg);
void topicMsgRecieve(int id, char);
