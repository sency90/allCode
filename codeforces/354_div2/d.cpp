#include <stdio.h>
#include <queue>
#include <iostream>
#include <cstring>
#define N 8
#define E 4
#define S 2
#define W 1
#define TOTAL 15
using namespace std;
//state NESW
char d[1000][1001];
struct Info{
    int x, y, r, cnt;
    Info(int xx, int yy, int rr, int c) {
        x=xx;y=yy;r=rr;cnt=c;
    }
};
queue<Info> q;
int chk[1000][1000];
int dx[]={0,1,0,-1}, dy[]={-1,0,1,0};
char interpret(char x);
char cwr(char s, int rotateCnt) {
    rotateCnt %= 4;
    if(rotateCnt==0) return s;
    if(rotateCnt==1) return ((s&1)<<3)+(s>>1);
    if(rotateCnt==2) return ((s&3)<<2)+(s>>2);
    else return ((s&7)<<1)+(s>>3);
}
//방이 서로 연결되어있는지 확인하는 함수
char chkState(char x, char y) {
    return cwr(x,2)&y;
}
int main() {
    int n, m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++) {
        scanf("%s", d[i]);
        for(int j=0; j<m; j++) {
            d[i][j] = interpret(d[i][j]);
        }
    }
    int sx,sy,ex,ey,nx,ny,ans=0x3f3f3f3f;
    scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
    sx--;sy--;ex--;ey--;
    q.push(Info(sx,sy,0,0));
    memset(chk, 0x3f, sizeof(chk));
    chk[sx][sy] = 0;
    while(!q.empty()) {
        Info cur = q.front(); q.pop();
        printf("(%d,%d), r:%d, cnt:%d\n",cur.x, cur.y, cur.r, cur.cnt);
        if((cur.x==ex) && (cur.y==ey)) {
            printf("%d\n", chk[cur.x][cur.y]);
            if(ans>cur.r+cur.cnt) ans = cur.r+cur.cnt;
        }
        int i;
        char s;
        bool good = false;
        s=cwr(d[cur.x][cur.y],cur.r);
        for(i=0; i<4; i++) {
            //printf("s:%hhd\n", s);
            if((1<<i)&s) {
                good = true;
                break;
            }
        }
        printf("i:%d\n",i);
        if(!good) {
            puts("-1");
            return 0;
        }
        for(int k=0; k<4; k++) {
            i=(k+i)%4;
            nx=cur.x+dx[i]; ny=cur.y+dy[i];
            if(nx<0||ny<0||nx>=n||ny>=m) continue;
            if(chk[nx][ny]<=chk[cur.x][cur.y]) continue;
            if(chkState(d[cur.x][cur.y], d[nx][ny])==0) continue;
            chk[nx][ny] = cur.r + k + cur.cnt + 1;
            printf("cur.r:%d k:%d\n", cur.r, k);
            q.push(Info(nx,ny, cur.r+k, cur.cnt+1));
        }
    }
    if(ans==0x3f3f3f3f) puts("-1");
    else printf("%d", ans);
    return 0;
}
char interpret(char x) {
    if(x=='+') return N+E+S+W;
    else if(x=='-') return E+W;
    else if(x=='|') return N+S;
    else if(x=='^') return N;
    else if(x=='>') return E;
    else if(x=='v') return S;
    else if(x=='<') return W;
    else if(x=='L') return TOTAL-W;
    else if(x=='R') return TOTAL-E;
    else if(x=='U') return TOTAL-N;
    else if(x=='D') return TOTAL-S;
    else if(x=='*') return 0;
    else return -1;
}

