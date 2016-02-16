#include <stdio.h>
#include <string.h>
#define RND 1000000000
unsigned int d[100][10];
unsigned int f(char x, char s) {
    if(x == 0) return 1;
    if(d[x][s] > 0) return d[x][s];

    if(0 == s) d[x][s] = f(x-1, 1);
    else if(9 == s) d[x][s] = f(x-1, 8);
    else d[x][s] = (f(x-1, s-1) + f(x-1, s+1)) % RND;
    return d[x][s];
}
int main() {
    char n, i;
    unsigned int sum = 0;
    memset(d, 0, sizeof(d));

    scanf("%hhd", &n);
    for(i=1; i<10; i++) {
        sum = (sum + f(n-1,i)) % RND;
    }

    printf("%u\n", sum);
    return 0;
}
