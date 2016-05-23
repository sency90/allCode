#include <stdio.h>
#include <string.h>
#define RND 100000000000000000 //17 0s
long long d[1001][10][2];
long long *f(short x, char l) {
    long long *temp = new long long[2] {0LL, 0LL};
    if(x == 1) { //base case
        temp[1] = 1LL;
        return temp;
    }
    if(d[x][l][1] > 0) return d[x][l];

    long long *t;
    for(char i=l; i>=0; i--) {
        t = f(x-1, i);
        temp[1] += t[1];
        temp[0] += (temp[1]/RND + t[0]);
        temp[1] = temp[1]%RND;
    }
    d[x][l][0] = temp[0];
    d[x][l][1] = temp[1];
    return d[x][l];
}
int main() {
    memset(d, 0, sizeof(d));
    short n;
    long long sum[2] = {0LL,};

    scanf("%hd", &n);
    long long *t;
    for(char i=0; i<10; i++) {
        t = f(n, i);
        sum[1] += t[1];
        sum[0] += (sum[1]/RND + t[0]);
        sum[1] = sum[1]%RND;
    }
    if(sum[0] != 0LL) {
        printf("%lld", sum[0]);
    }
    printf("%lld\n", sum[1]);
    return 0;
}
