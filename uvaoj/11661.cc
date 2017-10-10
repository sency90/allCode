#include <iostream>
#include <algorithm>
using namespace std;
char s[2000001];
const int inf=0x3f3f3f3f;
int main() {
    while(true) {
        int n;
        scanf("%d",&n);
        if(n==0) return 0;
        else scanf("%s", s);
        int druglast=-1, restlast=-1, ans=inf;
        for(int i=0; i<n; i++) {
            if(s[i]=='R') {
                if(druglast>=0) ans=min(ans,i-druglast);
                restlast=i;
            } else if(s[i]=='D') {
                if(restlast>=0) ans=min(ans,i-restlast);
                druglast=i;
            } else if(s[i]=='Z') {
                ans=0;
                break;
            }
        }
        if(ans==inf) puts("0");
        else printf("%d\n", ans);
    }
    return 0;
}
