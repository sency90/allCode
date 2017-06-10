#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
struct Info{
    int area, h, w,idx;
    Info(){} Info(int area, int h, int w, int idx):area(area),h(h),w(w),idx(idx){}
    bool operator<(const Info &rhs) const{
        return area<rhs.area && h<=rhs.h && w<=rhs.w;
    }
    void print() {
        printf("h:%d w:%d area:%d idx:%d\n",h,w,area,idx);
    }
};
bool cmp(const Info &lhs, const Info &rhs) {
    return lhs.area < rhs.area;
}
stack<int> s;
int d[101], p[101];
Info v[101];
int main() {
    //freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        int area,h,w;
        scanf("%d%d%d",&area,&h,&w);
        v[i] = Info(area,h,w,i);
    }
    sort(v+1,v+1+n,cmp);
    for(int i=0; i<=n; i++) p[i]=i;

    d[0]=v[0].h;
    int last=0, mx=0;
    for(int i=1; i<=n; i++) {
        int mxh = 0;
        for(int j=i-1; j>=0; j--) {
            if(v[i].w > v[j].w) {
                if(mxh <= d[j]) {
                    mxh = d[j];
                    p[i]=j;
                }
            }
        }
        d[i] = mxh + v[i].h;
        if(mx < d[i]) {
            mx = d[i];
            last = i;
        }
    }
    for(int i=last; p[i]!=i; i=p[i]) {
        s.push(v[i].idx);
    }

    printf("%lu\n", s.size());
    while(!s.empty()) {
        printf("%d\n", s.top()); s.pop();
    }
}
