#include <stdio.h>
#include <queue>
#include <cstring>
//NESW
#define N 8
#define E 4
#define S 2
#define W 1
#define T 15
using namespace std;
char d[1000][1001];
int dx[]={0,0,1,0,0,0,0,0,-1};
int dy[]={0,-1,0,0,1,0,0,0,0};
int cnt[1000][1001];
struct Info{
    int x, y, r;
    Info(int xx, int yy, int rr) {
        x=xx; y=yy; r=rr;
    }
};
queue<Info> q;
char state(char c) {
    if(c=='+') return T;
    else if(c=='-') return W+E;
    else if(c=='|') return N+S;
    else if(c=='^') return N;
    else if(c=='>') return E;
    else if(c=='v') return S;
    else if(c=='<') return W;
    else if(c=='L') return T-W;
    else if(c=='R') return T-E;
    else if(c=='U') return T-N;
    else if(c=='D') return T-S;
    else if(c=='*') return 0;
    else return -1;
}
char cwr(char s) {
    return ((s&1)<<3)|(s>>1);
}
char cwr(char s, int cnt) {
    for(int i=0; i<cnt; i++) {
        s = ((s&1)<<3)|(s>>1);
    }
    return s;
}
int main() {
    int n, m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++) {
        scanf("%s", d[i]);
        for(int j=0; j<m; j++) {
            d[i][j] = state(d[i][j]);
        }
    }
    memset(cnt, 0x3f, sizeof(cnt));
    int sx, sy, ex, ey, nx, ny;
    scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
    sx--;sy--;ex--;ey--;
    q.push(Info(sx,sy,0));
    cnt[sx][sy] = 0;
    while(!q.empty()) {
        Info tmp = q.front(); q.pop();
        char t = cwr(d[tmp.x][tmp.y], tmp.r);
        for(char i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
                char s=t&(1<<j);
                if(s) {
                    nx = tmp.x + dx[(int)s];
                    ny = tmp.y + dy[(int)s];
                } else continue;
                if(nx<0||ny<0||nx>=n||ny>=m) continue;
                if(cnt[nx][ny]<=cnt[tmp.x][tmp.y]+i+1) continue;
                //^v -> >< 이렇게 두 방의 입구가 만날 수 있는지를 고려해주는 if문이 필요하다.
                //밑의 if문 처리해줄 것. 아마 이것만 하면 해결될 거 같은데....
                //if(!(cwr(d[nx][ny],tmp.r+i+2)&cwr(t,i)&s)) continue;
                cnt[nx][ny] = cnt[tmp.x][tmp.y]+i+1;
                q.push(Info(nx,ny,tmp.r+i));
            }
            t=cwr(t);
        }
    }
    if(cnt[ex][ey]<1e+9) printf("%d", cnt[ex][ey]);
    else puts("-1");
    return 0;
}
