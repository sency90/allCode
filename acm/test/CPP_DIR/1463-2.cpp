#include <stdio.h>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
int d[1000001];
int f(int x) {
    if(x==1) return 0;
    else if(x<1) return INF;
    if(d[x]>0) return d[x];
    int mn = INF;
    if(x%3==0) mn = f(x/3);
    if(x%2==0) mn = min(mn, f(x/2));
    return d[x] = min(mn, f(x-1)) + 1;
}
int main() {
    int n;
    scanf("%d", &n);
    printf("%d", f(n));
    return 0;
}
