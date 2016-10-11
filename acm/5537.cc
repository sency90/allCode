#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
using namespace std;
const int mask=(1<<12)-1;
const short ninf=-32768;
int h,w,k;
char v[50][51];
short d[50][50][4][1<<12];
short dx[]={0,1,0,-1}, dy[]={1,0,-1,0};
short MAX(short x, short y) {return (x>y)?x:y;}
short dfs(int x, int y, int l, short b) {
    if(l<0) return ninf;
    short &ret = d[x][y][l][b];
    if(ret!=-1) return ret;
    else ret=ninf;
    if(x==h-1&&y==w-1&&l==0) return ret=0;
    bool visited=false;
    int px=x,py=y;
    for(int i=0; i<2*k; i++) {
        int pbit=(b>>(i*2))&3;
        px-=dx[pbit]; py-=dy[pbit];
        if(px==x&&py==y) {
            visited=true;
            break;
        }
    }
    int soucnt=0;
    if(!visited && isdigit(v[x][y])) soucnt=v[x][y]-'0';
    for(int i=0; i<4; i++) {
        if(l==0&&i>=2) break;
        int nx=x+dx[i], ny=y+dy[i];
        if(nx<0||ny<0||nx>=h||ny>=w||v[nx][ny]=='#') continue;
        ret=MAX(ret, dfs(nx,ny,l-(i>=2),((b<<2)|i)&mask) + soucnt);
    }
    return ret;
}
int main() {
    memset(d,-1,sizeof(d));
    scanf("%d%d%d ",&h,&w,&k);
    for(int i=0; i<h; i++) scanf("%s",v[i]);
    int ans = dfs(0,0,k,0);
    printf("%d", ans<0?0:ans);
    return 0;
}
