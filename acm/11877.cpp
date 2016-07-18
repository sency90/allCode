#include <stdio.h>
#include <vector>
#include <map>
using namespace std;
map<long long, bool> chk;
bool ans[1000001];
vector<long long> v;
void makeNum(int n, long long x) {
    if(x<=n) {
        ans[n+1-x]=true;
        return;
    }
    for(int i=n; i>=1; i--) {
        if(x-i > 0) {
            if(chk.count(i)>0) continue;
            x-=i;
            chk[i]=true;
            ans[n+1-i]=true;
        } else if(x-i == 0) {
            if(chk.count(i)>0) continue;
            ans[n+1-i]=true;
            return;
        } else i=x+1;
    }
}
int main() {
    long long n, x;
    scanf("%lld%lld",&n,&x);
    if(n<3LL) {
        if(x!=0LL) puts("-1");
        else for(int i=1; i<=n; i++) printf("%d ", i);
        return 0;
    }

    long long base = (n-2)*(n-1)/2;
    if(base < x) {
        puts("-1");
        return 0;
    }

    makeNum(n-2,x);
    for(int i=1; i<=n-2; i++) {
        if(!ans[i]) printf("%d ", i);
    }
    printf("%lld ", n);
    for(int i=1; i<=n-2; i++) {
        if(ans[i]) printf("%d ", i);
    }
    printf("%lld", n-1);

    return 0;
}
