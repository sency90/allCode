#include "topic.h"
#include "rw_vn.h"

//TopicMsg constructor
TopicMsg::TopicMsg() {
    topicBoxId = ID_INIT;

    /*
    time( &(this->tStamp) );
    timeinfo = localtime( &tStamp );
    sprintf(chTimeInfo, "%s", asctime(timeinfo));
    */
}

TopicMsg::TopicMsg( int tBoxId ) {
    topicBoxId = tBoxId;

    time( &(this->tStamp) );
    timeinfo = localtime( &tStamp );
    sprintf(chTimeInfo, "%s", asctime(timeinfo));
}

//initialize variables
TopicBox::TopicBox() {
    hasErr = false;
    //hasTopicMsg = false;
    /*
    for(int i=0; i<SUB_NUM; i++) {
        
        //pubId[i] = ID_INIT;
    }
    for(int i=0; i<TOPIC_NUM; i++) {
        for(int j=0; j<SUB_NUM; j++) {
            subId[i][j] = ID_INIT;
        }
    }

    topicBoxId = 0;

    sprintf(topicBoxName[0], "InvalidTopic");
    sprintf(topicBoxName[1], "TopicMsgTID1");
    sprintf(topicBoxName[2], "TopicMsgTID2");
    sprintf(topicBoxName[3], "TopicMsgTID3");
    */
    clientId.tBoxId = ID_INIT;
    clientId.pubfd = ID_INIT;
    for(int i=0;i<SUB_NUM; i++) {
        clientId.subfd[i] = ID_INIT;
    }

}

const char* TopicBox::btoa(bool b) {
    if(b) return "1"; //true
    else return "0"; //false
}

bool TopicBox::atob(char* str) {
    if(strcmp(str,"1")) return true;
    else return false;
}

//record an error in TopicBox
void TopicBox::recordErr(const char *errMsg) {
    printf("Error: %s\n", errMsg);
    this->hasErr = true;
    strcpy(this->errMsg, errMsg);
    //strcpy((*topicBox).errMsg, errMsg);
    //(*topicBox).hasErr = true;
}

//request to register a TopicBox to server(broker) from clients(pub or sub)
int TopicBox::sendTopicRegi(int sockfd, bool isPub, int topicBoxId) {

    //참고로 topicBoxId가 1이라는 것은 clients(pub or sub)가 나중에
    //TopicMsg의 topicBoxId를 1로 보내겠다는 뜻이다.
    this->hasErr = false;
    char tBoxId[ID_SIZE];
    sprintf(tBoxId, "%d", topicBoxId);
    writevn(sockfd, tBoxId, strlen(tBoxId));

    char isPublisher[5];
    strcpy(isPublisher, btoa(isPub));
    writevn(sockfd, isPublisher, sizeof(isPublisher));
    char issuedId[ID_SIZE];


    readvn(sockfd, issuedId, sizeof(issuedId));
    if(atoi(issuedId) == ID_INIT) {
        //발행된 ID가 0(ID_INIT)이면 Error이다. /////////////////////////////////////////////////////////////////////
        exit(-1);
    }

    return atoi(issuedId);
}

//recieve the request, which is to register a TopicBox from clients(pub or sub)
void TopicBox::recvTopicRegi(int sockfd) {
    //store the initial TopicBox object
    this->hasErr = false;
    TopicBox tBox = *this;

    char isPublisher[5];
    char errMsg[ERR_MSG_SIZE];
    int n;
    int issuedId = ID_INIT; //pub or sub ID
    int intTBoxId = ID_INIT;
    TopicMsg *topicMsg;

    /* 2 */
    //receive 'topicBoxId' variable
    char tBoxId[ID_SIZE];
    if( (n = readvn(sockfd, tBoxId, sizeof(tBoxId))) == 0) {
        tBoxId[n] = '\0';
        recordErr("read nothing (topicBoxId)");
        //sprintf(errMsg, "read nothing (topicBoxId)");
        //recordErr(errMsg, &tBox);
    } else {
        tBoxId[n] = '\0';
        int temp = atoi(tBoxId);
        if(temp == 1 || temp == 2 || temp == 3) {
            this->topicBoxId = temp;
            intTBoxId = temp;
        } else {
            recordErr("invalid topicBoxId");
        }
    }

    //intTBoxId가 0(ID_INIT)이면 무조건 에러군.

    /* 1 */
    //receive 'isPub' variable
    if( (n = readvn(sockfd, isPublisher, sizeof(isPublisher))) == 0) {
        isPublisher[n]='\0';
        recordErr("read nothing (isPub)");
        //sprintf(errMsg, "read nothing (isPub)");
        //recordErr(errMsg, &tBox);
    } else {
        isPublisher[n]='\0';
        printf("test- isPublisher: %s\n", isPublisher);
        this->isPub = atob(isPublisher);
        //recognize pub or sub
        if(this->isPub) { //if the sender had been a publisher
            //pubId를 발행(issue)한다.
            //pubId가 connfd값으로 설정됨.
            printf("test- pubId를 발행한다\n");
            issuedId = sockfd;
            if(this->pubId[intTBoxId] == ID_INIT) {
                this->pubId[intTBoxId] = issuedId;
            }
            else {
                recordErr("Only one publisher can be registered to a topic.\nAnother publisher has already been registered.");
            }
        } else { //if the sender had been a subscriber
            int i; //index for loop
            //subId[]를 발행(issue)한다.
            //subId[]가 connfd값으로 설정됨.
            printf("test- subId를 발행한다\n");
            issuedId = sockfd;
            for(i=0; i<SUB_NUM; i++) {
                if(this->subId[intTBoxId][i] == ID_INIT) {
                    this->subId[intTBoxId][i] = issuedId;
                    break;
                }
            }

            if(i == 4) {
                recordErr("The number limit of subscribers which can be registered to this topic has already been exceeded.");
            }
        }
    }


    //Undo all if an error has occured.
    if(this->hasErr) {

        //이전 상태로 되돌린다.
        (*this) = tBox;

        char issId[ID_SIZE];
        //error가 발생한 경우 ID_INIT값을 issued ID값으로 보낸다.
        sprintf(issId, "%d", ID_INIT);
        writevn(sockfd, issId, strlen(issId));
        printf("%s\n", tBox.errMsg);
        printf("Nothing has been changed since the error was occured.\n");
    } else {
        char issId[ID_SIZE];
        sprintf(issId, "%d", issuedId);
        writevn(sockfd, issId, strlen(issId));
    }
}





/* TO DO */
//for publishers
void TopicBox::sendTopicMsgForPub(int sockfd, int id, TopicMsg tMsg) {
    this->hasErr = false;
    /*
       TopicMsgTID1 *tMsg1;
       TopicMsgTID2 *tMsg2;
       TopicMsgTID3 *tMsg3;
       */

    char issId[ID_SIZE];
    sprintf(issId, "%d", id);

    char tBoxId[ID_SIZE];
    sprintf(tBoxId, "%d", tMsg.topicBoxId);

    //broker로 부터 할당받은 publisher의 ID를 보낸다.
    writevn(sockfd, issId, strlen(issId));
    writevn(sockfd, tBoxId, strlen(tBoxId));
    writevn(sockfd, tMsg.msg, strlen(tMsg.msg));
    writevn(sockfd, tMsg.chTimeInfo, strlen(tMsg.chTimeInfo));

}

//for broker
void TopicBox::recvTopicMsgForBro(struct pollfd *pollfds, int *n_pub, int *n_sub) {
    this->hasErr = false;
    TopicBox tBox = *this;

    int n;
    bool hasMsg;

    char recvdPubId[ID_SIZE];
    //이 부분으로 sub도 들어올 수 있음. 음... 왜? 브로커에서 이부분으로 넘겨줬기 때문.
    if( (n = readvn((*pollfds).fd, recvdPubId, sizeof(recvdPubId))) == 0 ) {
        recvdPubId[n] = '\0';
        this->recordErr("[pubId] hasn't been received.");

        printf("publisher[%d] closed connection.\n", pollfds->fd);
        close(pollfds->fd);
        pollfds->fd = -1;
        pollfds->revents = 0;
        (*n_pub)--;
    }
    else {
        recvdPubId[n] = '\0';
        if( atoi(recvdPubId) != this->pubId[this->topicBoxId] ){
            this->recordErr("mismatch between received publisher's ID and the issued pubId");
        }
    }


    //receive tMsg.topicBoxId
    char tBoxId[ID_SIZE];
    if( (n = readvn(pollfds->fd, tBoxId, sizeof(tBoxId))) == 0 ) {
        tBoxId[n] = '\0';
        this->recordErr("[topicBoxId] hasn't been received.");
    }
    else {
        tBoxId[n] = '\0';
        (this->topicMsg).topicBoxId = atoi(tBoxId);
        if(this->topicMsg.topicBoxId != this->topicBoxId) {
            this->recordErr("Received topic is not for this Topic Box.");
        }
    }

    if((n = readvn(pollfds->fd, this->topicMsg.msg, MSG_SIZE)) == 0) {
        hasMsg = false;
    } else {
        hasMsg = true;
        this->topicMsg.msg[n] = '\0';
    }

    n = readvn(pollfds->fd, this->topicMsg.chTimeInfo, TIMEINFO_SIZE);
    this->topicMsg.chTimeInfo[n] = '\0';








    //if received msgs from a publisher and doesn't have any error from the above process
    if(this->hasErr) {

        // 이거 개소리 ->//error가 났지만 write와 read에서 쿵짝을 맞추기 위해 쓰레기값들을 보낸다. ********************************
        //writevn(pollfds->fd, tBoxId, strlen(tBoxId));
        //writevn(sockfd, this->errMsg, strlen(this->errMsg)); //errMsg를 실어서 보낸다.
        //writevn(sockfd, this->topicMsg.chTimeInfo, strlen(this->topicMsg.chTimeInfo));

        //이전 상태로 되돌린다.
        (*this) = tBox;

        printf("Since the error was occured, Nothing has been changed.\n");
    } else if(hasMsg) {
        //message를 제대로 받았으므로 이제 여기서 subscribe 한다.
        printf("[broker]: Subscribe complete from publisher[%d]!!\n", atoi(recvdPubId));
        for(int i=0; i<SUB_NUM; i++) {
            if(this->subId[i] != ID_INIT) {
                writevn(this->subId[this->topicBoxId][i], tBoxId, strlen(tBoxId));
                writevn(this->subId[this->topicBoxId][i], this->topicMsg.msg, strlen(this->topicMsg.msg));
                writevn(this->subId[this->topicBoxId][i], this->topicMsg.chTimeInfo, strlen(this->topicMsg.chTimeInfo));
                printf("[broker]: Publish complete to subscriber[%d]!!\n", this->subId[this->topicBoxId][i]);
            }
        }
    }
    else {
        //error는 발생하지 않았으나 message가 없는경우 아무것도 하지 않는다.
    }

}

void TopicBox::recvTopicMsgForSub(int sockfd) {
    char tBoxId[ID_SIZE];
    char tMsg[MSG_SIZE];
    char chTimeInfo[TIMEINFO_SIZE];
    //readvn(sockfd, issId, sizeof(issId));


    readvn(sockfd, tBoxId, ID_SIZE);
    readvn(sockfd, tMsg, MSG_SIZE);
    readvn(sockfd, chTimeInfo, TIMEINFO_SIZE);

    if(strlen(tBoxId) == 0) {
        close(sockfd);
        printf("Error: %s\n", tMsg);
        printf("[Force Quit] Bye Bye~.\n");
        exit(-1);
    }

    printf("--------------------------------------------------------------------\n");
    printf("Message received from publisehr[%d]\n", sockfd);
    printf("Topic: %s\n", tBoxId);
    printf("Message: %s\n", tMsg);
    printf("Timestamp: %s\n", chTimeInfo);
    printf("--------------------------------------------------------------------\n");
    printf("\n");

}