#include <iostream>
using namespace std;
template <class T>
class Queue{
public:
    int r=0, f=0;
    T arr[1501*1501];
    Queue():r(0),f(0){}
    void push(T x) { arr[r++]=x; }
    T front() { return arr[f]; }
    void pop() { f++; }
    bool empty() { return f==r; }
    void init() { r=f=0; }
};
struct Info{
    int x, y, level;
    Info(){}
    Info(int x, int y, int level):x(x),y(y),level(level){}
    bool operator<(const Info &rhs) const {
        return level < rhs.level;
    }
};
Queue<Info> q;
char s[1501];
int v[1501][1501], vis[1501][1501];
int sx=-1,sy,ex,ey,n,m;
const int inf = 0x3f3f3f3f;
int dx[]={-1,0,1,0}, dy[]={0,1,0,-1};
int T=1;

bool judge(int base) {
    q.init();

    q.push(Info(sx,sy,0));
    vis[sx][sy]=++T;
    while(!q.empty()) {
        Info tmp = q.front(); q.pop();
        if(tmp.x==ex && tmp.y==ey) return true;
        for(int i=0; i<4; i++) {
            int nx=tmp.x+dx[i], ny=tmp.y+dy[i];
            if(nx<0||ny<0||nx>=n||ny>=m) continue;
            if(vis[nx][ny]==T) continue;
            vis[nx][ny]=T;
            if(v[nx][ny] > base) continue;
            q.push(Info(nx,ny,tmp.level+1));
        }
    }
    return false;
}
int main() {
    //freopen("input.txt", "r", stdin);

    //input
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++) {
        scanf("%s", s);
        for(int j=0; j<m; j++) {
            if(s[j] == '.') {
                v[i][j]=0;
                q.push(Info(i,j,0));
            } else if(s[j] =='L') {
                v[i][j]=0;
                q.push(Info(i,j,0));
                if(sx<0) sx=i,sy=j;
                else ex=i,ey=j;
            } else {
                v[i][j]=inf;
            }
        }
    }

    while(!q.empty()) {
        Info tmp = q.front(); q.pop();
        for(int i=0; i<4; i++) {
            int nx=tmp.x+dx[i], ny=tmp.y+dy[i];
            if(nx<0||ny<0||nx>=n||ny>=m) continue;
            if(v[nx][ny] == inf) {
                v[nx][ny] = tmp.level+1;
                q.push(Info(nx,ny,tmp.level+1));
            }
        }
    }

    q.init();
    int lo=0, hi=1500;
    while(lo<=hi) {
        int mid = (lo+hi)/2;
        if(judge(mid)) hi=mid-1;//hi+1이 답이었을 것이다.
        else lo=mid+1;
    }
    printf("%d\n", hi+1);
    return 0;
}
