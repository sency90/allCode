#include "topic2.h"
#include "rw_vn.h"

//TopicMsg constructor
TopicMsg::TopicMsg() {
    //TID = -1;
    tid = ID_INIT;
}

TopicMsg::TopicMsg( int topicId ) {
    tid = topicId;
}

//TopicMSGTID1 constructor
TopicMsgTID1::TopicMsgTID1() {
    TopicMsg(1);
}

TopicMsgTID2::TopicMsgTID2() {
    TopicMsg(2);
}

TopicMsgTID3::TopicMsgTID3() {
    TopicMsg(3);
}



//initialize variables
TopicBox::TopicBox() {
    hasErr = false;
    hasTopicMsg = false;
    pubId = ID_INIT;
    for(int i=0; i<SUB_NUM; i++) {
        subId[i] = ID_INIT;
    }

    topicBoxId = 0;

    sprintf(topicBoxName[0], "InvalidTopic");
    sprintf(topicBoxName[1], "TopicMsgTID1");
    sprintf(topicBoxName[2], "TopicMsgTID2");
    sprintf(topicBoxName[3], "TopicMsgTID3");

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

//create the publisher's ID
int TopicBox::createPubId(int sockfd) {
    if(this->pubId == ID_INIT) {
        this->pubId = sockfd;
        return this->pubId;
    } else {
        recordErr("Only one publisher can be registered to a topic. Another publisher has already been registered.");
        return -1;
    }
}

//create the subscriber's ID
int TopicBox::createSubId(int sockfd) {
    int i; //index for loop

    for(i=0; i<SUB_NUM; i++) {
        if(this->subId[i] == ID_INIT) {
            this->subId[i] = sockfd;
            return this->subId[i];
        }
    }

    //There is no room for this sub if 'i' is 4.
    //i가 4라면 위의 반복문들 모두 돌고 나온 것이므로 sub를 등록할 자리가 없다는 뜻.
    if(i == 4) {
        recordErr("The number limit of subscribers which can be registered to this topic has already been exceeded.");
        return -1;
    }
}

//request to register a TopicBox to server(broker) from clients(pub or sub)
int TopicBox::sendTopicRegi(int sockfd, bool isPub, int topicBoxId) {
    char isPublisher[2];
    strcpy(isPublisher, btoa(isPub));
    writevn(sockfd, isPublisher, sizeof(isPublisher));
    char issuedId[ID_SIZE];

    //참고로 topicBoxId가 1이라는 것은 clients(pub or sub)가 나중에
    //TopicMsg를 TopicMsgTID1로 보내겠다는 뜻이다.
    char tBoxId[ID_SIZE];
    sprintf(tBoxId, "%d", topicBoxId);
    writevn(sockfd, tBoxId, strlen(tBoxId));

    readvn(sockfd, issuedId, sizeof(issuedId));

    return atoi(issuedId);
}

//recieve the request, which is to register a TopicBox from clients(pub or sub)
void TopicBox::recvTopicRegi(int sockfd) {
    //store the initial TopicBox object
    TopicBox tBox = *this;

    char isPublisher[2];
    char errMsg[ERR_MSG_SIZE];
    int n;
    int issuedId = -1; //pub or sub ID
    TopicMsg *topicMsg;

    /* 1 */
    //receive 'isPub' variable
    if( (n = readvn(sockfd, isPublisher, sizeof(isPublisher))) == 0) {
        isPublisher[n]='\0';
        recordErr("read nothing (isPub)");
        //sprintf(errMsg, "read nothing (isPub)");
        //recordErr(errMsg, &tBox);
    } else {
        isPublisher[n]='\0';
        this->isPub = atob(isPublisher);
        //recognize pub or sub
        if(this->isPub) { //if the sender had been a publisher
            issuedId = createPubId(sockfd);
        } else { //if the sender had been a subscriber
            issuedId = createSubId(sockfd);
        }
    }

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
        this->topicBoxId = atoi(tBoxId);

        switch(this->topicBoxId) {

            case 1:
                topicMsg = new TopicMsgTID1();
                break;
            case 2:
                topicMsg = new TopicMsgTID2();
                break;
            case 3:
                topicMsg = new TopicMsgTID3();
                break;
            default:
                recordErr("invalid topicBoxId");
                //sprintf(errMsg, "invalid topicBoxId");
                //recordErr(errMsg, &tBox);
                break;
        }
    }


    //Undo all if an error has been occured.
    if(this->hasErr) {
        (*this) = tBox;
        printf("Since the error was occured, Nothing has been changed.\n");
    } else {
        char issId[ID_SIZE];
        sprintf(issId, "%d", issuedId);
        writevn(sockfd, issId, strlen(issId));
    }
}





/* TO DO */
int TopicBox::sendTopicMsg(int sockfd, int id, TopicMsg tMsg) {
    char issId[ID_SIZE];
    sprintf(issId, "%d", id);
    writevn(sockfd, issId, strlen(issId));
    writevn(sockfd, tMsg, sizeof(tMsg)); //TopicMsg전용 writevn이 필요.
}

void TopicBox::recvTopicMsg(int sockfd) {
    char issId[ID_SIZE];
    readvn(sockfd, issId, sizeof(issId));

    if()
}
