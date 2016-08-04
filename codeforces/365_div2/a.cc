#include <stdio.h>
int main() {
    int n,mcnt=0,ccnt=0,a,b;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d%d", &a,&b);
        if(a>b) mcnt++;
        else if(a<b) ccnt++;
    }
    if(mcnt==ccnt) puts("Friendship is magic!^^");
    else if(mcnt>ccnt) puts("Mishka");
    else puts("Chris");
    return 0;
}
