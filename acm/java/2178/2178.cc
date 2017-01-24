#include <cstdio>
#include <queue>
using namespace std;
int v[101][101],dx[]={0,0,1,-1},dy[]={1,-1,0,0};
bool chk[101][101];
queue<pair<int,int> > q;
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%1d",&v[i][j]);
        }
    }
    int ans=1;
    chk[0][0]=true;
    q.push(make_pair(0,0));
    while(!q.empty()) {
        int sz=q.size(); //queue 사이즈를 체크해줍니다. 반드시 따로 변수를 두고 쓰셔야 합니다.
        for(int z=0; z<sz; z++) { //for(int z=0; z<q.size(); z++) 이런식으로 쓰지 말아야 하겠죠? ^^? 이유는 좀만 생각해보면 알 수 있어요. queue 사이즈는 계속 변하니까...
            int x=q.front().first, y=q.front().second; q.pop();
            if(x==n-1&&y==m-1) return 0&printf("%d", ans); //도착점을 만나면 바로 답을 출력하고 프로그램을 종료해요.
            for(int i=0; i<4; i++) {
                int nx=x+dx[i], ny=y+dy[i];
                if(nx<0||ny<0||nx>=n||ny>=m) continue;
                if(chk[nx][ny] || !v[nx][ny]) continue;
                chk[nx][ny]=true;
                q.push(make_pair(nx,ny));
            }
        }
        ans++; //아까 측정했던 큐 사이즈만큼 다 돌고나면 탐색 깊이(level)를 1만큼 증가시켜줍니다.
    }
    return 0;
}
