#include <stdio.h>
#include <cstring>
using namespace std;
#define RND 1000000000
unsigned long long d[101][10];
unsigned long long f(int n, int x) {
    //base case
    if(n==1) {
        if(x==0) return 0;
        else return 1;
    }
    if(d[n][x]!=-1) return d[n][x];
    if(x==0) d[n][x] = f(n-1,x+1);
    else if(x==9) d[n][x] = f(n-1,x-1);
    else d[n][x] = (f(n-1,x-1) + f(n-1,x+1))%RND;
    return d[n][x];
}
int main() {
    memset(d, -1, sizeof(d));
    int n; scanf("%d", &n);
    unsigned long long sum=0;
    for(int i=0; i<10; i++) {
        sum = (sum + f(n,i))%RND;
    }
    printf("%llu", sum);
    return 0;
}
