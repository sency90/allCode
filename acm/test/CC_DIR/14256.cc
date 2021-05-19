#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
int n,m;
int mx, mn;
int cnt(int x) {
    if(x==1) return 1;
    int ret=2;
    for(int i=2; i*i<=x; i++) {
        if(x%i == 0) {
            int t = x/i;
            if(i<=mn&&t<=mn) {
                if(i*i==x) ret++;
                else ret+=2;
            } else if(i<=mn&&t<=mx) {
                ret++;
            }
        }
    }
    return ret;
}
int main() {
    scanf("%d%d",&n,&m);
    int lim = (n+m)/2, ans=0;
    mx=max(n,m); mn=min(n,m);
    for(int i=1; i<=sqrt(double(n+m)/2); i++) ans+=cnt(i);
    printf("%d", ans);
    return 0;
}
