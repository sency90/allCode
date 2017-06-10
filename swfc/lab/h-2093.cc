#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
int v[101][101];

template <class T>
class Heap{
public:
    int sz;
    T v[100001];
    Heap():sz(0){}
    void swap(T &x, T &y) { T tmp=x; x=y; y=tmp; }

    void up(int x) {
        if(x<=0) return;
        int p = (x-1)/2;
        if(v[p] > v[x]) {
            swap(v[p],v[x]);
            up(p);
        }
    }
    void push(T x) {
        v[sz] = x;
        up(sz++);
    }

    void down(int p) {
        int l=p*2+1, r=p*2+2, mn=p;
        if(l<sz && v[mn]>v[l]) mn=l;
        if(r<sz && v[mn]>v[r]) mn=r;
        if(mn!=p) {
            swap(v[mn], v[p]);
            down(mn);
        }
    }
    T pop() {
        T tmp = v[0];
        v[0]=v[--sz];
        down(0);
        return tmp;
    }
    bool empty() { return sz==0; }
    int size() { return sz; }
};

struct Info{
    int x,y,dist;
    Info():x(0),y(0),dist(0){}
    Info(int x, int y, int dist):x(x),y(y),dist(dist){}
    bool operator<(const Info &rhs) const {
        return dist<rhs.dist;
    }
    bool operator>(const Info &rhs) const {
        return dist>rhs.dist;
    }
};
int dx[]={0,1,0,-1}, dy[]={1,0,-1,0};
bool chk[101][101];
Heap<Info> mnh;

int main() {
    int n; scanf("%d",&n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%1d", &v[i][j]);
        }
    }

    mnh.push(Info(n-1,n-1,v[n-1][n-1]));
    while(!mnh.empty()) {
        Info tmp = mnh.pop();
        if(tmp.x==0 && tmp.y==0) return 0&printf("%d\n", tmp.dist);
        chk[tmp.x][tmp.y]=true;
        for(int i=0; i<4; i++) {
            int nx = tmp.x+dx[i], ny=tmp.y+dy[i];
            if(nx<0||ny<0||nx>=n||ny>=n) continue;
            if(chk[nx][ny]) continue;
            mnh.push(Info(nx,ny,tmp.dist+v[nx][ny]));
        }
    }
    return 0;
}
