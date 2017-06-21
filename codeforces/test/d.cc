#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define r2 (r<<1)
#define m2 ((s+e)>>1)
using namespace std;
struct Line{
    int x1,x2,h,v;
    Line(){} Line(int x1, int x2, int h, int v):x1(x1),x2(x2),h(h),v(v){}
    bool operator<(const Line &rhs) const { return h<rhs.h; }
};
int s,e,lim;
vector<int> cover, tree;
void update(int r, int s, int e, int qs, int qe, int v) {
    if(qe<s||e<qs) return;
    else if(qs<=s&&e<=qe) {
        cover[r]+=v;
        if(cover[r]) tree[r]=e-s+1;
        else {
            if(s==e) tree[r]=0;
            else tree[r]=tree[r2]+tree[r2+1];
        }
    } else {
        update(r2,s,m2,qs,qe,v);
        update(r2+1,m2+1,e,qs,qe,v);
        if(cover[r]==0) tree[r]=tree[r2]+tree[r2+1];
    }
}
vector<Line> line;
int main() {
    freopen("input.txt", "r", stdin);
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if(x1>x2) swap(x1,x2);
        if(y1>y2) swap(y1,y2);
        line.emplace_back(Line(x1,x2,y1,1));
        line.emplace_back(Line(x1,x2,y2+1,-1));
        e=max(e,x2+1);
    }
    int ph=line[0].h;
    stable_sort(line.begin(), line.end());
    for(s=0;(1<<s)<=n;s++) lim=1<<(s+1);
    cover.resize(lim,0); tree.resize(lim,0);
    s=1;
    int area=0;
    for(int i=0; i<line.size(); i++) {
        printf("[Line] x:%d x':%d h:%d v:%d\n", line[i].x1, line[i].x2, line[i].h, line[i].v);
        int tmp = (line[i].h-ph)*tree[1];
        printf("addede area: %d\n", tmp);
        area += tmp;
        printf("tree[1]: %d\n", tree[1]);
        //printf("query: %d\n",query(1,s,e,s,e));
        update(1,s,e,line[i].x1,line[i].x2,line[i].v);
        ph = line[i].h;
    }
    printf("%d\n", area);
    return 0;
}
