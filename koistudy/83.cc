#include <stdio.h>
int main() {
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    for(int i=0; i<a; i++) {
        for(int j=0; j<b; j++) {
            for(int k=0; k<c; k++) {
                printf("%d %d %d\n",i, j, k);
            }
        }
    }
    printf ("%d\n",a*b*c);
}
