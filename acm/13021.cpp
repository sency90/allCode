#include <stdio.h>
#include <map>
using namespace std;
map<int, bool> chk;
int ball[1001];
int main() {
    int n,m,l,r;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=m; i++) {
        scanf("%d%d",&l,&r);
        for(int j=l; j<=r; j++) {
            ball[j]=i;
        }
    }
    long long cnt=0;
    for(int i=1; i<=n; i++) {
        if(ball[i]==0) continue;
        if(chk.count(ball[i])>0) continue;
        chk[ball[i]]=true;
        cnt++;
    }
    printf("%lld", 1LL<<cnt);
    return 0;
}
