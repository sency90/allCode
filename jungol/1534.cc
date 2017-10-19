#include <stdio.h>
char binary[1<<14];
int main() {
    int n,c;
    scanf("%d%d",&n,&c);
    if(c==16) printf("%X",n);
    else if(c==8) printf("%o",n);
    else {
        register int i=0;
        for(;n;i++) {
            binary[i]=n&1;
            n>>=1;
        }
        if(c==2) {
            for(int j=i-1; j>=0; j--) {
                printf("%d",binary[j]);
            }
        }
    }
    return 0;
}
