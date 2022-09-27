#include <cstdio>
using namespace std;
typedef pair<int,int> pii;
pii hole;
char m[11][11];
bool chk[11][11];
const int inf = 0x3f3f3f3f;
int mn = inf;
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
bool go(pii &red, pii &blue, int dir) {
    int rx = red.first, ry = red.second;
    int bx = blue.first, by = blue.second;
    int rnx = rx + dx[dir], rny = ry + dy[dir];
    int bnx = bx + dx[dir], bny = by + dy[dir];
    for(int i=1; i<=10; i++) {
        if(m[rnx][rny]=='.') {
            m[rnx][rny] = m[rx][ry];
            m[rx][ry] = '.';
            rx+=dx[dir], ry+=dy[dir];
            rnx+=dx[dir], rny+=dy[dir];
        }
        if(m[bnx][bny]=='.') {
            m[bnx][bny] = m[bx][by];
            m[bx][by] = '.';
            bx+=dx[dir], by=dy[dir];
            bnx+=dx[dir], bny+=dy[dir];
        }
    }
}
void dfs(int x, pii red, pii blue) {
    if(x==0) return;
    for(int dir=0; dir<4; dir++) {
        pii oRed=red, oBlue=blue;
        if(!go(red, blue, dir)) return;

        if(isPass(red, nRed)) {
            if(!isPass(blue, nBlue)) mn = min(10-x+1, mn);
            return;
        }
        dfs(x-1, nRed, nBlue);
    }
}
int main() {
    pii red, blue;
    int n, m; scanf("%d%d", &n,&m);
    for(int i=0; i<n; i++) {
        scanf("%s", m[i]);
        for(int j=0; j<m; j++) {
            if(m[i][j]=='B') blue = pii(i,j);
            else if(m[i][j]=='R') red = pii(i,j);
            else if(m[i][j]=='0') hole = pii(i,j);
        }
    }

    dfs(10, red, blue);
    return 0;
}
