#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define RND 1000000000
int a[55];
int d[101][10][1<<10]; //1
int bi[10] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
int f(int n, int x, int bit) {
    if(n==0) return 0;
    if(bit==0) return 0;
    if(d[n][x][bit] > 0) return d[n][x][bit];

    int temp = 0;
    for(int i=1; i<55; i++) {
        if(a[i] > bit) break;
        if((a[i]|bi[x]) == bit) {
            if(x == 0) temp = (temp + f(n-1, x+1, a[i]))%RND;
            else if(x==9) temp = (temp + f(n-1, x-1, a[i]))%RND;
            else temp = (temp + f(n-1, x-1, a[i]) + f(n-1, x+1, a[i]))%RND;
        }
    }
    return d[n][x][bit] = temp%RND;
}
int main() {
    memset(d, 0, sizeof(d));
    memset(a, 0, sizeof(a));
    for(int i=1; i<10; i++) {
        d[1][i][bi[i]] = 1;
    }

    int x = 0;
    for(int i=0; i<10; i++) {
        for(int j=i; j<10; j++, x++) {
            for(int k=i; k<=j; k++) {
                a[x] += bi[k];
            }
        }
    }
    sort(a, a+55);
    int n; scanf("%d", &n);
    int sum = 0;
    for(int i=0; i<10; i++) {
        sum = (sum + f(n, i, 1023)) % RND;
    }
    printf("%d", sum);
    return 0;
}
