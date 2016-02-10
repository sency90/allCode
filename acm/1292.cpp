#include <stdio.h>
 
int main() {
    int stan[1001], x, t, i, j;
    int a, b; scanf("%d %d", &a, &b);
 
    stan[0] = 1;
    x = 1;
    for(i=1; i<46; i++) {
        t = (i*i + i + 2)/2;
        for(j=x; j < t && j < 1001; j++) {
            stan[j] = i;
        }
        x = t;
    }
 
    int sum = 0;
    for(int i=a; i<b+1; i++) {
        sum += stan[i];
    }
 
    printf("%d\n", sum);
    return 0;
}