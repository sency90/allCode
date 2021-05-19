#include <stdio.h>
#include <string.h>
#define RND 1000000000
int d[100][10][4], n;
int f(int m, int x, int bit) {
    if(d[m][x][bit]) return d[m][x][bit];
    if(m == n) {
        if(bit==3) return d[m][x][bit] = 1;
        else return d[m][x][bit] = 0;
    }

    int r = 0;
    if(x==8) r = (r + f(m+1, x+1, bit|2) + f(m+1, x-1, bit))%RND;
    else if(x==1) r = (r + f(m+1, x-1, bit|1) + f(m+1, x+1, bit))%RND;
    else if(x==0) r = (r + f(m+1, x+1, bit))%RND;
    else if(x==9) r = (r + f(m+1, x-1, bit))%RND;
    else r = (r + f(m+1, x-1, bit) + f(m+1, x+1, bit))%RND;
    return d[m][x][bit] = r%RND;
}
int main() {
    memset(d, 0, sizeof(d));
    scanf("%d", &n); n--;

    int sum = 0;
    for(int i=1; i<10; i++) {
        sum += f(0, i, i==9 ? 2:0);
        sum %= RND;
    }
    printf("%d", sum);
    return 0;
}
