#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int c[101], w[101], d[101][10001];
bool chk[101][10001];
const int inf=0x3f3f3f3f;
int n,m,ans=inf;
int f(int idx, int co) {
    if(idx==0) return 0;
    else if(idx==1) {
        if(co == 0) {
            if(c[idx]==0) return w[idx];
            else return 0;
        } else if(co >= c[idx]) return w[idx];
        else return d[idx][co] = f(idx, co-1);
    }

    if(chk[idx][co]) return d[idx][co];
    chk[idx][co]=true;

    int &ret = d[idx][co];
    if(co - c[idx]>=0) {
        ret = max(f(idx-1,co), f(idx-1, co-c[idx]) + w[idx]);
    } else ret = f(idx-1,co);

    if(ret>=m) ans=min(ans,co);
    return ret;
}
int main() {
    //freopen("input.txt", "r", stdin);
    
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++) {
        scanf("%d", &w[i]);
    }
    int sum=0;
    for(int i=1; i<=n; i++) {
        scanf("%d", &c[i]);
        sum += c[i];
    }
    for(int i=0; i<=sum; i++) f(n,i);
    printf("%d", ans);
    return 0;
}
