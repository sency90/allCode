#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;

#define MAX_SCREEN_AREA 100
#define SIZE 10

bool chk[SIZE+1][SIZE+1];
int shape[SIZE+1][SIZE+1];
bool hasAns;

struct Coord{
    int x, y;
    Coord(int xx, int yy) {
        x=xx; y=yy;
    }
};
vector<Coord> v;
int gotoxy(int x, int y);
void dfs(int x, int y, int &xe, int &ye, int s, int prevDir);
void printscreen(vector<Coord> &v);
void flushscreen();
void printboard();

int main() {
    int x, y, s, xe, ye, state;
    int cnt=0;

    //input
    while(true) {
        scanf("%d", &x);
        if(x==-1) break;
        else scanf("%d%d",&y,&s);
        v.push_back(Coord(x,y));
        shape[x][y] = s;
        cnt++;
    }

    //game start
    while(true) {
        printscreen(v);
        if(cnt == 0) {
            gotoxy(SIZE+2,0);
            puts("WIN!!");
            return 0;
        }

        gotoxy(SIZE+2,0);
        puts("출발지점을 입력하세요");
        scanf("%d%d",&x,&y);
        printf("Strat: (%d, %d): %d\n", x, y, shape[x][y]);
        if(shape[x][y] == 0) continue;

        puts("도착지점을 입력하세요");
        scanf("%d%d",&xe,&ye);
        printf("End: (%d, %d): %d\n", x, y, shape[x][y]);
        if(shape[x][y]!=shape[xe][ye]) continue;

        hasAns = false;
        memset(chk, false, sizeof(chk));
        dfs(x,y,xe,ye,-1,-1);
        if(hasAns) {
            shape[x][y]=0;
            shape[xe][ye]=0;
            cnt-=2;
        }
    }
    return 0;
}

int dx[]={0,0,1,-1}, dy[]={1,-1,0,0}, nx,ny,ns;
void dfs(int x, int y, int &xe, int &ye, int s, int prevDir) {
    chk[x][y] = true;
    printf("%d %d\n", x, y);
    if(x==xe && y==ye) {
        hasAns = true;
        return;
    }

    for(int i=0; i<4; i++) {
        if(hasAns) return;
        nx = x + dx[i];
        ny = y + dy[i];
        if(prevDir==i) ns=s;
        else ns=s+1;
        if(ns>2) continue;

        if(nx<1||ny<1||nx>SIZE||ny>SIZE) continue;
        if(chk[nx][ny]) continue;
        if(shape[nx][ny]!=0) { //if block exists
            if(nx==xe && ny==ye) {
                dfs(nx,ny,xe,ye,ns,i);
                return;
            } else continue;
        } else {
            dfs(nx,ny,xe,ye,ns,i);
        }
    }
}

void printscreen(vector<Coord>& v) {
    flushscreen();
    printboard();
    gotoxy(0,0);

    for(int i=0; i<v.size(); i++) {
        gotoxy(v[i].x, v[i].y);
        if(shape[v[i].x][v[i].y]) printf("%d",shape[v[i].x][v[i].y]);
        else putchar(' ');
    }
}

void printboard() {
    gotoxy(0,0);
    for(int i=0; i<SIZE+2; i++) {
        putchar('#');
    } puts("");
    for(int i=0; i<SIZE; i++) {
        putchar('#');
        for(int j=0; j<SIZE; j++) {
            putchar(' ');
        }
        puts("#");
    }
    for(int i=0; i<SIZE+2; i++) {
        putchar('#');
    } puts("");
}

void flushscreen() {
    gotoxy(0,0);
    for(int i=0; i<2*SIZE; i++) {
        for(int j=0; j<2*SIZE; j++) {
            putchar(' ');
        }
        puts("");
    }
}

int gotoxy(int x, int y) {
    char essq[MAX_SCREEN_AREA]={0};
    sprintf(essq, "\033[%d;%df", x+1, y+1);
    printf("%s", essq);
    return 0;
}
