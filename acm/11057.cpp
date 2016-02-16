#include <stdio.h>
#include <string.h>
short d[1000][10];
short f(short x, char s) {
    if(x == 0) return 1;
    if(d[x][s] > 0) return d[x][s];

    for(char i=s; i<10; i++) {
        d[x][s] = (d[x][s] + f(x-1,i))%10007;
    }
    return d[x][s];
}

int main() {
    memset(d, 0, sizeof(d));
    short n, sum = 0;

    scanf("%hd", &n);
    for(char i=0; i<10; i++) {
        sum = (sum + f(n-1,i))%10007;
    }
    printf("%hd\n", sum);
    return 0;
}
