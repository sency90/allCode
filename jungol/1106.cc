#include <stdio.h>
struct Info{
    int x,y;
    Info(){}
    Info(int x,int y):x(x),y(y){}
};
template <typename T>
struct Queue{
    T v[1000001];
    int f,r;
    Queue():f(0),r(0){}
    inline void push(T x) { v[f++]=x; }
    inline void pop() { r++; }
    inline bool empty() { return f<=r; }
    inline int size() { return f-r; }
    inline T front() { return v[r]; }
    void init() { f=r=0; }
};
bool chk[101][101];
Queue<Info> q;
int dx[]={-2,-1,1,2,2,1,-1,-2},dy[]={1,2,2,1,-1,-2,-2,-1};
int main() {
    int n,m; scanf("%d%d",&n,&m);
    int sx,sy,ex,ey; scanf("%d%d%d%d",&sx,&sy,&ex,&ey);

    q.push(Info(sx,sy));
    chk[sx][sy]=true;
    int cnt=0;
    while(!q.empty()) {
        int sz=q.size();
        for(int z=0; z<sz; z++) {
            Info t = q.front(); q.pop();
            if(t.x==ex && t.y==ey) return 0&printf("%d",cnt);
            for(int i=0; i<8; i++) {
                int nx=t.x+dx[i],ny=t.y+dy[i];
                if(nx>=n||ny>=m||nx<0||ny<0) continue;
                if(chk[nx][ny]) continue;
                chk[nx][ny]=true;
                q.push(Info(nx,ny));
            }
        }
        cnt++;
    }
    return 0;
}
