#include <stdio.h>
int main() {
    int v[5], sum=0;
    for(int i=0; i<5; i++) {
        scanf("%d", &v[i]);
        sum +=v[i];
    }
    if(sum==0) puts("-1");
    else if(sum%5==0) printf("%d", sum/5);
    else puts("-1");
    return 0;
}
