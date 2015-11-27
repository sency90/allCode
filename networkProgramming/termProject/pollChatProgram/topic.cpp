#include "topic.h"
#include "rw_vn.h"

TopicBox::TopicBox() {
    hasErr = false;
    hasMsg = false;
    pub_id = ID_INIT;
    for(int i=0; i<SUB_NUM; i++) {
        sub_id[i] = ID_INIT;
    }
}

TopicBox errHandling(char *errMsg, TopicBox topicBox) {
    printf("%s\n", errMsg);
    strcpy(topicBox.errMsg, errMsg);
    topicBox.hasErr = true;

    return topicBox;
}

int topicRegiSend(int sockfd, int id, char *topicBoxName) {
    char topicId[ID_SIZE];
    sprintf(topicId, "%d", id);

    writevn(sockfd, topicId, sizeof(topicId)); //publisher에서 broker에게 pub_id를 넘겨준다.
    return writevn(sockfd, topicBoxName, strlen(topicBoxName)); //topicBoxName을 넘겨준다.
}

TopicBox topicRegiRecv(int sockfd) {
    TopicBox topicBox;
    char topicId[ID_SIZE];
    char topicBoxName[TOPIC_NAME_SIZE];
    int n; //size for the return of the readvn() function
    int i; //index for loop
    char errMsg[ERR_MSG_SIZE]; //temp error msg variable

    topicBox.hasErr = false;

    /* 1 */
    //topicBox의 ID를 받는 부분
    if((n = readvn(sockfd, topicId, ID_SIZE)) == 0) {
        topicId[n] = '\0';

        sprintf(errMsg, "Error: ID variable has nothing.");
        topicBox = errHandling(errMsg, topicBox);
    }
    else { // n이 -1일때는 readvn()에서 알아서 처리하므로 따로 처리해줄 필요가 없다.
        topicId[n] = '\0';
        int id = atoi(topicId);

        //id값이 pub_id에 해당하는지 확인하는 부분
        if(id>=PUB_START_INDEX && id<=PUB_END_INDEX) {

            //해당 topicBox에 한번도 pub_id가 등록된적이 없다면,
            if(topicBox.pub_id == ID_INIT) {
                topicBox.pub_id = id; //readvn()으로 읽은 id를 pub_id에 집어 넣는다.
            }
            else { //해당 topicBox에 pub_id가 등록된적이 있다면 에러 메세지를 출력한다.
                sprintf(errMsg, "Error: There is no room for publisher.");
                topicBox = errHandling(errMsg, topicBox);
            }
        }
        //id값이 sub_id에 해당하는지 확인하는 부분
        else if(id>=SUB_START_INDEX && id<=SUB_END_INDEX) {
            //topicBox.pub_id = ID_NULL;
            for(i=SUB_START_INDEX; i<=SUB_END_INDEX; i++) {
                if(topicBox.sub_id[i] == ID_INIT) {
                    topicBox.sub_id[i] = id;
                    break;
                }
            }
            //subscriber가 한정된 SUB_NUM만큼 모두 등록되어있다면 error message 출력
            if(i > SUB_NUM) {
                sprintf(errMsg, "Error: There is no room for subscribers.");
                topicBox = errHandling(errMsg, topicBox);
                //exit(-1);
            }
        }
        //publisher ID 형식도 아니고 subscriber ID 형식도 아닌 경우
        else {
            sprintf(errMsg, "Error: ID variable has an error value.");
            topicBox = errHandling(errMsg, topicBox);
            //exit(-1);
        }
    }

    /* 2 */
    //topicBox의 Name을 받는 부분
    if((n = readvn(sockfd, topicBoxName, TOPIC_NAME_SIZE)) == 0) {
        topicBoxName[n] = '\0';
        sprintf(errMsg, "Error: Topic Name variable has nothing.");
        topicBox = errHandling(errMsg, topicBox);
    }
    else {
        topicBoxName[n] = '\0';
        if(topicBox.hasErr == false) { //An error has not occured above.
            strcpy(topicBox.topicBoxName, topicBoxName);
        }
    }

    return topicBox;
}





// client(publisher) -> server(broker)
int topicMsgSend(int sockfd, int pub_id, char *msg) {
    //char msg[MSG_SIZE];
    //strcpy(msg, message);
    char topicId[ID_SIZE];
    sprintf(topicId, "%d", pub_id);

    writevn(sockfd, topicId, sizeof(topicId)); //publisher에서 broker에게 pub_id를 넘겨준다.
    return writevn(sockfd, msg, strlen(msg)); //topicBoxName을 넘겨준다.
}

TopicBox topicMsgRecv(int sockfd) {
    TopicBox topicBox;
    char topicId[ID_SIZE];
    char msg[MSG_SIZE];
    //char topicBoxName[TOPIC_NAME_SIZE];
    int n; //size for the return of the readvn() function
    int i; //index for loop
    char errMsg[ERR_MSG_SIZE]; //temp error msg variable

    topicBox.hasErr = false;

    /* 1 */
    //topicBox의 ID를 받는 부분
    if((n = readvn(sockfd, topicId, ID_SIZE)) == 0) {
        topicId[n] = '\0';

        sprintf(errMsg, "Error: ID variable has nothing.");
        topicBox = errHandling(errMsg, topicBox);
    }
    else { // n이 -1일때는 readvn()에서 알아서 처리하므로 따로 처리해줄 필요가 없다.
        topicId[n] = '\0';
        int id = atoi(topicId);

        if(id>=PUB_START_INDEX && id<=PUB_END_INDEX) { //정상 (publisher가 msg를 보낸 경우)
            if( (n = readvn(sockfd, msg, MSG_SIZE)) == 0 ) {
                msg[n] = '\0';
                //publish하는 msg 껍데기는 왔으나 안에 내용물이 안들어 있었던 경우 아무것도 하지 않는다.
                //do nothing!
                topicBox.hasMsg = false;
            }
            else {
                msg[n] = '\0';
                strcpy(topicBox.msg, msg);
                topicBox.hasMsg = true;

                /*
                for(i=SUB_START_INDEX; i<=SUB_END_INDEX; i++) {
                    if(sub_id[i] != ID_INIT) {

                    }
                }*/ //이 부분을 밖에서 topicBox을 리턴받아 동작시키면 됨.
            }
        }
        else { //비정상 (subscriber가 msg를 보낸 경우 or Error)
            sprintf(errMsg, "Error: Invalid ID");
            topicBox = errHandling(errMsg, topicBox);
        }
    }

    return topicBox;
}
