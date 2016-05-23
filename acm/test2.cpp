#include <stdio.h>
long long d[1001];
long long f(int x) {
    //base case
    if(x==1) return 1;
    else if(x==2) return 2;
    if(d[x]>0) return d[x];
    return d[x] = (f(x-1)+f(x-2))%10007;
}
int main() {
    int n;
    scanf("%d", &n);
    printf("%lld", f(n)%10007);
    return 0;
}

