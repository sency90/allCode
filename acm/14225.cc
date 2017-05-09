#include <cstdio>
#include <cstring>
using namespace std;
int v[21], d[21];
bool chk[2000001];
void f(int x, int ans) {
    if(x==0) {
        chk[ans]=true;
        return;
    }
    f(x-1,ans+v[x]);
    f(x-1,ans);
}
int main() {
    int n,sum=0;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &v[i]);
        sum+=v[i];
    }
    memset(chk,false,sizeof(chk));
    f(n,0);
    for(int i=1; i<=sum+1; i++) {
        if(!chk[i]) return 0&printf("%d\n", i);
    }
    return 0;
}
