#include <cstdio>
#include <map>
using namespace std;
typedef unsigned int uint;
#define r2 (r<<1)
#define mm ((s+e)>>1)
map<uint,int> dp;

//interval: [s,e)
const int lim = 1<<23;
int seg[1<<21];
int d[lim];
const int ss=0,ee=1<<20;

int max(int x,int y){ return x>y?x:y; }
int update(int r,int s,int e,int at,int by) {
    if(e<=s) return 0;
    else if(at<s||e<=at) return seg[r];
    else if(s==at && s+1==e) return seg[r]=by;
    else return seg[r]=max(update(r2,s,mm,at,by),update(r2+1,mm,e,at,by));
}

//interval: [s,e) [i,j)
int query(int r,int s,int e,int i,int j) {
    if(e<=i||j<=s||s>=e) return 0;
    else if(i<=s && e<=j) return seg[r];
    else return max(query(r2,s,mm,i,j),query(r2+1,mm,e,i,j));
}
int f(uint x) {
    if(x == 1U) return 1;
    if(x<lim) { if(d[x]) return d[x]; }
    else { if(dp.count(x)) return dp[x]; }

    if(x & 1U) {
        if(x<lim) return d[x] = f(x*3+1)+1;
        else return dp[x] = f(x*3+1)+1;
    } else {
        if(x<lim) return d[x] = f(x>>1)+1;
        else return dp[x] = f(x>>1)+1;
    }
}

int main() {
    for(int i=1; i <= 1000000; i++) {
        if(d[i]==0) update(1,ss,ee,i,f(i));
        else update(1,ss,ee,i,d[i]);
    }
    int l,r;
    while(scanf("%d%d",&l,&r)!=EOF) {
        if(l<r) printf("%d %d %d\n",l,r,query(1,ss,ee,l,r+1));
        else printf("%d %d %d\n",l,r,query(1,ss,ee,r,l+1));
    }
    return 0;
}
