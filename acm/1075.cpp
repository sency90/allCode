#include <stdio.h>
int main() {
    int n, f;
    scanf("%d%d",&n,&f);
    n=n/100*100;
    for(int i=0; i<100; i++) {
        if((n+i)%f==0) {
            printf("%02d",i);
            return 0;
        }
    }
    return 0;
}
