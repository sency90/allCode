#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
int arr[4][4];
bool isRight[4][4] = {false,};
bool validCol[4], validRow[4];
struct Info{
    int roc, cnt, move;
    void scan(int _roc, int _cnt, int _move) {
        roc = _roc;
        cnt = _cnt;
        move = _move;
    }
}info[7];
void movefunc( bool isRow, int line, int move ) {
    int temp[4], idxTemp;
    if(isRow) {
        validRow[line] = true;
        for(int j=0; j<4; j++) {
            temp[(j+move)%4] = arr[line][j];
        }
        for(int j=0; j<4; j++) {
            isRight[line][j] = true;
            arr[line][(j+move)%4] = temp[j];
        }
    } else {
        validCol[line] = true;
        for(int i=0; i<4; i++) {
            temp[(i+move)%4] = arr[i][line];
        }
        for(int i=0; i<4; i++) {
            isRight[i][line] = true;
            arr[(i+move)%4][line] = temp[i];
        }
    }
}
void rowRefresh() {
    for(int i=0; i<4; i++) {
        if(arr[i][0] == 4*i+1) validRow[i] = true;
        else validRow[i] = false;
    }
}
void colRefresh() {
    for(int j=0; j<4; j++) {
        if(arr[0][j] == j+1) validCol[j] = true;
        else validCol[j] = false;
    }
}
int main() {
    int cnt = 0;
    memset(validCol, true, sizeof(validCol));
    memset(validRow, true, sizeof(validRow));
    //memset(isRight, false, sizeof(isRight));
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            scanf("%d", &arr[i][j]);
            if(4*i+1 <= arr[i][j] && arr[i][j] <= 4*(i+1)) {
                if(arr[i][j]%4 == (i+1)%4) {
                    isRight[i][j] = true;
                } else validCol[j] = false;
            } else validRow[i] = false;
        }
    }

    queue<Info> q;
    //row, col check
    bool doAgain;
    int move;
    do{
        doAgain = false;
        for(int i=0; i<4; i++) {
            if(cnt > 7) return -1;
            if(validRow[i]) {
                if(!isRight[i][0]) {
                    doAgain = true;
                    move = arr[i][0] - (4*i+1);
                    info[cnt++].scan(1, i, move);
                    movefunc(true, i, move);
                    colRefresh();
                }
            }
            if(validCol[i]) {
                if(!isRight[0][i]) {
                    doAgain = true;
                    move = (arr[0][i] - (i+1))/4;
                    info[cnt++].scan(2, i, move);
                    movefunc(false, i, move);
                    rowRefresh();
                }
            }
        }
    } while(doAgain);
    printf("%d\n", cnt);
    for(int i=0; i<cnt; i++) {
        printf("%d %d %d\n", info[i].roc, info[i].cnt, info[i].move);
    }
    return 0;
}
