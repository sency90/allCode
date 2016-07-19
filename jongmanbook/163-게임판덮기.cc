#include <stdio.h>
#include <cstring>
using namespace std;
int h,w;
char board[20][21];
int state[][3][2] = {
    {{0,0},{0,1},{1,0}},
    {{0,0},{0,1},{1,1}},
    {{0,0},{1,0},{1,1}},
    {{0,0},{1,0},{1,-1}}};
int cnt=0;
void fill(int x, int y) {
    if(y>=w) fill(x+1,0);
    else if(x>=h) {
        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                if(board[i][j]=='.') return;
            }
        }
        cnt++;
        return;
    }
    if(board[x][y]=='#'||board[x][y]=='*') fill(x,y+1);

    int nx, ny;
    bool isBrk;
    for(int s=0; s<4; s++) {
        isBrk = false;
        for(int i=0; i<3; i++) {
            nx=x+state[s][i][0]; ny=y+state[s][i][1];
            if(nx<0||ny<0||nx>=h||ny>=w||board[nx][ny]!='.') {
                isBrk = true;
                break;
            }
        }
        if(isBrk) continue;

        for(int i=0; i<3; i++) {
            nx=x+state[s][i][0]; ny=y+state[s][i][1];
            board[nx][ny]='*';
        }

        //fill !!!!!
        if(s==0||s==1) fill(x,y+2);
        else fill(x,y+1);

        for(int i=0; i<3; i++) {
            nx=x+state[s][i][0]; ny=y+state[s][i][1];
            if(board[nx][ny]=='*') board[nx][ny]='.';
        }
    }
}
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        cnt=0;
        memset(board, false, sizeof(board));
        scanf("%d%d",&h,&w);
        for(int i=0; i<h; i++) {
            scanf("%s", board[i]);
        }
        fill(0,0);
        printf("%d\n", cnt);
    }
    return 0;
}
