#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int main() {
    int n,k,ans=0,t=0;
    scanf("%d%d",&n,&k);
    for(int i=1; i<=n; i++) {
        if(240>=i*5+k+t) {
            t+=i*5;
            ans=i;
        } else break;
    }
    printf("%d", ans);
    return 0;
}
