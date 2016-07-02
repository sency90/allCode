#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
unsigned long long d[300000];
int mn[1140];
bool chk[64];
unsigned long long f(unsigned long long x) {
    if(x==1) return 0LLU;
    if(d[x]>0) return d[x];

    if(x%2==0) d[x] = f(x/2)+1LLU;
    else d[x] = f(x*3+1)+1LLU;
    return d[x];
}
int main() {
    for(unsigned long long i=1; i<=1138; i++) f(i);
    memset(mn, 0x3f, sizeof(mn));
    for(int i=1; i<=1138; i++) {
        mn[d[i]] = min(mn[d[i]], i);
    }
    int t, n;
    scanf("%d", &t);
    for(int z=1; z<=t; z++) {
        printf("Case #%d\n", z);
        scanf("%d", &n);
        printf("%d %llu\n", mn[n], 1LLU<<n);
    }
    return 0;
}
