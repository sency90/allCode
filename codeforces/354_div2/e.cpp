#include <stdio.h>
int main() {
    char c;
    int n, k, ans=-1;
    bool hasAns = false;
    scanf("%d%d",&n,&k);
    for(int i=0; i<n; i++) {
        scanf(" %c", &c);
        if(!hasAns) {
            if(c=='?') {
                ans=i;
                hasAns = true;
            }
        }
    }
    if(ans==-1) {
        puts("YES");
    } else {
        if(ans%2) puts("YES");
        else puts("NO");
    }
    return 0;
}
