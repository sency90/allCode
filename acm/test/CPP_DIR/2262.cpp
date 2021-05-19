#include <stdio.h>
#include <cstring>
#include <queue>
using namespace std;
int idx[257], a[257];
bool chk[257];
struct Info{
    int d, x, y;
    Info(int dd, int xx, int yy) {
        d=dd; x=xx; y=yy;
    }
    bool operator<(const Info &rhs) const{
        return d > rhs.d;
    }
};
priority_queue<Info> mnh;
int main() {
    int n, sum=0, t;
    memset(chk, false, sizeof(chk));
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
        idx[a[i]]=i;
        if(i!=0) {
            if(a[i]>a[i-1]) mnh.push(Info(a[i]-a[i-1],a[i-1],a[i]));
            else mnh.push(Info(a[i-1]-a[i],a[i-1],a[i]));
        }
    }
    Info info(0,0,0);
    for(int k=0; k<n-1; k++) {
        info = mnh.top(); mnh.pop();
        //sum += info.d;
        printf("%d: %d %d %d\n",k, info.d, info.x, info.y);
        if(mnh.empty()) break;
        if(info.x < info.y) {
            //if(chk[info.x]) continue;
            chk[info.x] = true;
            if(idx[info.x]<1) continue;
            t = a[idx[info.x]-1];
            if(chk[t]) continue;
            if(t > info.y) mnh.push(Info(t-info.y, t, info.y));
            else mnh.push(Info(info.y-t, t, info.y));
        } else {
            //if(chk[info.y]) continue;
            chk[info.y] = true;
            if(idx[info.y]>=n) continue;
            t = a[idx[info.y]+1];
            if(chk[t]) continue;
            if(t > info.x) mnh.push(Info(t-info.x, info.x, t));
            else mnh.push(Info(info.x-t, info.x, t));
        }
        sum += info.d;
    }
    printf("%d", sum);
    return 0;
}
