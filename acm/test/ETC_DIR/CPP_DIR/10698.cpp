#include <stdio.h>
int main() {
    int n,a,b,res;
    char oc[2], g[2];
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        scanf("%d%s%d%s%d",&a,oc,&b,g,&res);
        printf("Case %d: ", i);
        if(oc[0]=='+') {
            if(a+b==res) puts("YES");
            else puts("NO");
        } else {
            if(a-b==res) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}
