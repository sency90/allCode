#include <stdio.h>
#include <cstring>
using namespace std;
long long cache[21][1<<20];
int n;
long long solve(int pos, int mask) {
    if(pos == n) return 1;
    if(cache[pos][mask]!=-1) return cache[pos][mask];

    long long tmp=0;
    for(int i=0; i<n; i++) {
        if(i!=pos && (mask & (1<<i)) == 0) {
            tmp += solve(pos+1, mask | (1<<i));
        }
    }
    return cache[pos][mask]=tmp;
}
int main() {
    memset(cache, -1, sizeof(cache));
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        printf("%lld", solve(1,n));
    }
}
//long long ans[21] = {0,0,1,2,9,44,265,1854,14833,133496,1334961,14684570,176214841,2290792932,32071101049,481066515734,7697064251745,130850092279664,2355301661033953,44750731559645106,895014631192902121};
