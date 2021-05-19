#include <stdio.h>
#include <limits.h>
#include <string.h>
//d[i]는 i부터 맨 오른쪽 인덱스까지 몇 번 점프해야 도달하는지를 기록함.
int inf = INT_MAX/2;
int v[1000], d[1000], n;
int f(int x) {
    if(x > n-1) return 0;
    if(x == n-1) return 1;
    if(d[x]!=-1) return d[x];

    int min = inf, tmp, len = x+v[x];
    for(int i=x+1; i<=len && i<n; i++) {
        if( min > (tmp = f(i)) && tmp!=0) min = tmp;
    }
    if(min==inf) return d[x] = 0;
    else return d[x] = min+1;
}
int main() {
    scanf("%d", &n);
    memset(d, -1, sizeof(d));
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    int tmp;
    if((tmp = f(0)) == 0) puts("-1");
    else printf("%d", tmp-1);
    return 0;
}
