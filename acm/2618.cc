#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define A 1
#define B 2
vector<pair<int,int> > v;
int n,w;
int d[1001][1001], path[1001][1001];
int abs(int x) { return x<0?-x:x; }
int dist(pair<int,int> a, pair<int,int> b) {
    return abs(a.first-b.first) + abs(a.second-b.second);
}
int f(int a, int b) {
    if(a==w || b==w) return d[a][b]=0;
    int &ret = d[a][b];
    if(ret!=-1) return ret;

    int next = max(a,b)+1;
    int t1, t2;
    if(b==0) t1 = f(a,next) + dist(make_pair(n,n),v[next]);
    else t1 = f(a,next) + dist(v[b],v[next]);
    if(a==0) t2 = f(next,b) + dist(make_pair(1,1),v[next]);
    else t2 = f(next,b) + dist(v[a],v[next]);

    ret = min(t1,t2);
    if(t1==ret) path[a][b] = B;
    else path[a][b] = A;
    return ret;
}
int main() {
    int x,y;
    scanf("%d%d",&n,&w);
    v.resize(w+1);
    memset(d, -1, sizeof(d));
    for(int i=1; i<=w; i++) {
        scanf("%d%d",&x,&y);
        v[i] = make_pair(x,y);
    }
    printf("%d\n", f(0,0));
    int a=0, b=0;
    for(int i=1; i<=w; i++) {
        printf("%d\n", path[a][b]);
        if(path[a][b] == A) a=i;
        else b=i;
    }
    return 0;
}
