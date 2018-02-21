#include <stdio.h>
int v[101], ans[101],n;
int main() {
    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%d",&v[i]);
    int idx=0;
    for(int i=0; i<n; i++) {
        while(ans[idx]) idx=(idx+1)%n;
        ans[idx]=v[i];
        idx=(idx+v[i])%n;
    }
    printf("%d\n",n);
    for(int i=0; i<n; i++) printf("%d ",ans[i]);
    return 0;
}
