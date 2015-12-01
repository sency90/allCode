#include "publisher.h"
//#include "rw_vn.h"
#include "topic2.h"
int thisPubId;
TopicBox tBox;

void* createMsg(void *arg) {
    pthread_detach(pthread_self());

    char tempMsg[MSG_SIZE];

    //무한반복 하진 않고 100개만 돌려보자.
    for(int n = 1; n<100 ;n++) {
        //message를 생성할 때 4번중 한번은 아무 메세지도 생성하지 않도록 한다.
        if(n%4 == 0) {
            tempMsg[0]='\0';
        }
        else {
            sprintf(tempMsg, "Publisher[%d]의 %d번째 Message!", thisPubId, n);
        }
        //start mutex
        strcpy(tBox.topicMsg.msg, tempMsg);
        //end mutex

    }

}

void* sendMsg(void *connfd) {

}

int main(int argc, char** argv) {

    struct sockaddr_in clientAddr;
    clientAddr.sin_family = AF_INET;
    //clientAddr.sin_addr.s_addr = inet_addr(argv[1]);
    clientAddr.sin_addr.s_addr = inet_addr(LOCAL_IP);
    clientAddr.sin_port = htons(PORT);

    int topicId = atoi(argv[1]);

    if(topicId == 1 || topicId == 2 || topicId == 3) {
        printf("This Publisher can publish only [%d]TOPIC\n", topicId);
    }

    printf("Wating for creating a publisher socket...\n");
    //int *connfd = (int*)malloc(sizeof(int));
    int connfd = socket(AF_INET, SOCK_STREAM, 0);
    printf("The socket was created successfully!!\n");

    printf("Waiting for connection to the broker...\n");
    if( connect(connfd, (struct sockaddr*)&clientAddr, sizeof(clientAddr)) < 0 ) {
        printf("Error: Cannot connect with the broker.\n");
        exit(-1);
    }
    else {
        TopicBox tBox;
        thisPubId = tBox.sendTopicRegi(connfd, true, topicId);

        if(thisPubId == ID_INIT) {
            printf("Error: The broker has too many publishers. (LIMIT: %d)\n", PUB_NUM);
            return -1;
        }

        /*
        pthread_t tid_createMsg;
        pthread_t tid_sendMsg;

        pthread_create(&tid_createMsg, NULL, createMsg, NULL);
        pthread_create(&tid_sendMsg, NULL, sendMsg, connfd);

        pthread_join(tid_createMsg, NULL);
        pthread_join(tid_sendMsg, NULL);
        */

        char tempMsg[MSG_SIZE];
        bool hasMsg = false;

        //무한반복 하진 않고 100개만 돌려보자.
        for(int n = 1; n<100 ;n++) {
            //message를 생성할 때 4번중 한번은 아무 메세지도 생성하지 않도록 한다.
            sleep(2000);
            if(n%4 == 0) {
                tempMsg[0]='\0';
                hasMsg = false;
            }
            else {
                sprintf(tempMsg, "Publisher[%d]의 %d번째 Message!", thisPubId, n);
                hasMsg = true;
            }
            //start mutex
            strcpy(tBox.topicMsg.msg, tempMsg);

            if(hasMsg) {
                printf("Created Msg: %s\n", tempMsg);
                tBox.sendTopicMsgForPub(connfd, thisPubId, tBox.topicMsg);
            } else {
                printf("Any msg wasn't created at this moment\n");
            }

            //end mutex
        }
    }

    //free(connfd);
}
