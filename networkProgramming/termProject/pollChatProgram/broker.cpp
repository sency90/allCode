#include "commonHeader.h"
#include "topic2.h"
#include <sys/poll.h>
#define NUMPOLL 7
#define LIMIT_FD 5

void err_quit(const char* str) {
    perror(str);
    exit(1);
}

int main(int argc, char **argv) {
    char server_id[7] = "broker";

    int i, n, maxi, listenfd, connfd;
    int nready = 0;
    ssize_t n_message;
    ssize_t n_id;
    int n_conn = 0; //connection 개수
    int n_pub = 0, n_sub = 0;
    //fd_set rset, allset;
    struct pollfd pollfds[PUB_NUM + SUB_NUM];
    bool _isPub[PUB_NUM + SUB_NUM];

    //NUMPOLL 개수만큼 id저장 가능, 각각의 ID size는 ID_SIZE 크기를 넘지 못함.
    char user_id[NUMPOLL][ID_SIZE];
    char line[BUFFER_SIZE];
    char temp_id[ID_SIZE];

    socklen_t clilen;
    struct sockaddr_in cliaddr, servaddr;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    bind(listenfd, (sockaddr*)&servaddr, sizeof(servaddr));
    listen(listenfd, LISTENQ);

    //maxfd = listenfd; //initialize
    maxi = -1; //index into client[] array

    pollfds[0].fd = listenfd;
    pollfds[0].events = POLLIN;
    pollfds[0].revents = 0;
    for(i=1; i<NUMPOLL; i++) {
        pollfds[i].fd = -1;
    }

    TopicBox tempTBox;
    TopicBox tBox[PUB_NUM+1];

    //FD_ZERO(&allset); //set all bits of 'allset' as 0
    //FD_SET(listenfd, &allset); //register listenfd to 'allset'

    int tBoxId = ID_INIT;

    while(1) {
        if((nready = poll(pollfds, NUMPOLL, -1)) < 0) {
            perror("poll failed");
            exit(3);
        }


        /* 1 */
        //accepting clients which requested to connect to this server(broker)
        if(pollfds[0].revents == POLLIN) { //request connection from new client
            clilen = sizeof(cliaddr);
            connfd = accept(listenfd, (sockaddr*)&cliaddr, &clilen);

            //recvTopicRegi()함수를 호출하면,
            //"tBox.isPub", "tBox.topicBoxId", "pubId[토픽박스번호] (or) subId[토픽박스번호][subscriber]" 값이 update된다.
            tempTBox.recvTopicRegi(connfd);

            tBoxId = tempTBox.topicBoxId;

            if(tempTBox.isPub) { //publisher가 topic을 등록한 경우

                n_pub++;

                tBox[tBoxId].pubId[tBoxId] = tempTBox.pubId[tBoxId];
                tBox[tBoxId].isPub = tempTBox.isPub;
                tBox[tBoxId].topicBoxId = tBoxId;

                for(int i=1; i < (SUB_NUM + PUB_NUM); i++) {
                    if(pollfds[i].fd == -1) {
                        pollfds[i].fd = connfd;
                        pollfds[i].events = POLLIN;
                        pollfds[i].revents = 0;
                        _isPub[i] = tBox[tBoxId].isPub;
                        break;
                    }
                }
            } else { //subscriber가 topic을 등록한 경우

                n_sub++;

                for(int i=0; i<SUB_NUM; i++) {
                    //subscriber가 구독을 새로 신청한 경우.
                    if(tBox[tBoxId].subId[tBoxId][i] == ID_INIT && tempTBox.subId[tBoxId][i] != ID_INIT) {
                        tBox[tBoxId].subId[tBoxId][i] = tempTBox.subId[tBoxId][i];
                        _isPub[i] = tBox[tBoxId].isPub;
                    }
                    //subscriber가 구독을 해제한 경우.
                    else if(tBox[tBoxId].subId[tBoxId][i] != ID_INIT && tempTBox.subId[tBoxId][i] == ID_INIT) {
                        tBox[tBoxId].subId[tBoxId][i] = tempTBox.subId[tBoxId][i];
                    }
                }
                tBox[tBoxId].isPub = tempTBox.isPub; //필요없지만 일단은 등록해둔다.
                tBox[tBoxId].topicBoxId = tBoxId;
            }

            //if(connfd > maxfd) maxfd = connfd; //for select
            if(i > maxi) maxi = i; //max index in client[] array
            if(--nready <= 0) continue; //no more readable descriptors
        }

        /* 2 */
        //handling messages which were sent by some clients
        for(i=1; i<=maxi; i++) { //check all clients for data
            switch(pollfds[i].revents) {
                case 0: break; //no events
                case POLLIN:
                        //publisher로 부터 TopicMsg를 받고 subscriber에게 전달한다.
                        tempTBox.recvTopicMsgForBro( &pollfds[i], &n_pub, &n_sub );
                        break;
                default:
                        perror("error event");
                        close(pollfds[i].fd);
                        pollfds[i].fd = -1;
                        pollfds[i].revents = 0;
                        break;

            } //end switch
        } //end for(i)
    }
}
