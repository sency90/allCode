#include <stdio.h>
int main() {
    bool isBrk=false;
    int n, k, cnt=0;
    scanf("%d %d", &n, &k);
    n--;
    for(int i=0; i<k-1; i++) {
        printf("%d\n", n);
        if(n==1) {
            isBrk = true;
            break;
        }
        n++;
        cnt++;
        n=n/2;
    }
    if(isBrk) cnt+=n;
    cnt+=n;
    printf("test n : %d\n", n);
    printf("%d", cnt);
    return 0;
}
