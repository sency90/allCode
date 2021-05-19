#include <stdio.h>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;
priority_queue<pair<int,int> > mxhcnt;
priority_queue<int> mxh;
int cnt[8001];
int main() {
    memset(cnt, 0, sizeof(cnt));
    int n, mx, sum=0, d, mxcnt=0, mn=0x3f3f3f3f;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &d);
        sum += d;
        mxh.push(d);
        if(mn > d) mn=d;
        d+=4000;
        cnt[d]++;
        if(mxcnt<cnt[d]) {
            while(!mxhcnt.empty()) mxhcnt.pop();
            mxhcnt.push(make_pair(cnt[d],-d));
            mxcnt = cnt[d];
        } else if(mxcnt==cnt[d]){
            mxhcnt.push(make_pair(cnt[d],-d));
        }
    }
    mx = mxh.top();
    int len = n/2;
    for(int i=0; i<len; i++) {
        mxh.pop();
    }
    if(mxhcnt.size()>=2) mxhcnt.pop();
    printf("%.lf\n%d\n%d\n%d\n", floor((double)sum/n+0.5), mxh.top(), -4000-(mxhcnt.top().second), mx-mn);
    return 0;
}
