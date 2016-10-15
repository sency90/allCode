#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
int NM[101][101];
int cache[101][101];
bool visit[101][101];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int N, M;
void dfs(int x, int y){
    visit[x][y]=true;
    if(x==N&&y==M) cache[x][y]=1;
    for(int i=0 ; i<4; i++) {
        int nx=x+dx[i], ny=y+dy[i];
        if(nx<1 || nx>N || ny<1 || ny>M) continue;
        if(visit[nx][ny]|| NM[nx][ny]==0)continue;
        cache[x+dx[i]][y+dy[i]] = min(cache[x+dx[i]][y+dy[i]], cache[x][y]+1);
        dfs(x+dx[i], y+dy[i]);
        visit[nx][ny]=false;
    }
    return;
}

int main(){
    scanf("%d %d", &N, &M);
    memset(cache, 0x3f, sizeof(cache));
    for(int x=1; x<=N; x++){
        for(int y=1; y<=M; y++) {
            scanf("%1d",&NM[x][y]);
        }
    }
    dfs(1,1);
    printf("%d\n", cache[1][1]);
    return 0;
}
