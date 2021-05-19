#include <stdio.h>
int a[1001], d[1001];
int f(int x) {
    if(x==0) return 0;
    if(d[x]>0) return d[x];
    int tmp;
    for(int i=1; i<=x; i++) {
        tmp = f(x-i) + a[i];
        if(tmp > d[x]) d[x] = tmp;
    }
    return d[x];
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", a+i);
    }
    printf("%d", f(n));
    return 0;
}
