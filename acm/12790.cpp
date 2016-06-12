#include <stdio.h>
int d[8];
int main() {
    int t;
    scanf("%d",&t);
    int a,b,c,e;
    while(t--) {
        for(int i=0; i<8; i++) {
            scanf("%d", &d[i]);
        }
        if(d[0]+d[4]<1) a=1;
        else a=d[0]+d[4];
        if(d[1]+d[5]<1) b=1;
        else b=d[1]+d[5];
        if(d[2]+d[6]<0) c=0;
        else c=d[2]+d[6];
        e=d[3]+d[7];
        printf("%d\n",a+5*b+2*c+2*e);
    }
    return 0;
}
