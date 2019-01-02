#include <stdio.h>
long long ABS(long long x) {
    return x<0LL?-x:x;
}
int main() {
    long long a,b;
    scanf("%lld %lld",&a,&b);
    printf("%lld\n",a+b);
    printf("%lld\n",ABS(a-b));
    printf("%lld\n",a*b);
    printf("%lld\n",a/b);
    printf("%lld\n",a%b);
    printf("%.2lf\n",double(a)/b);
    return 0;
}

