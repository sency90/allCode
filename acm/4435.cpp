#include <stdio.h>
int p[][7] = {{1,2,3,3,4,10,0},{1,2,2,2,3,5,10}};
int main() {
    int t, sum[2], x;
    scanf("%d", &t);
    for(int j=0; j<t; j++) {
        for(int k=0; k<2; k++) {
            sum[k] = 0;
            for(int i=0; i<7; i++) {
                if(k==0 && i==6) break;
                scanf("%d", &x);
                sum[k] += x*p[k][i];
            }
        }
        printf("Battle %d: ", j+1);
        if(sum[0] > sum[1]) puts("Good triumphs over Evil");
        else if(sum[0] == sum[1]) puts("No victor on this battle field");
        else puts("Evil eradicates all trace of Good");
    }
    return 0;
}
