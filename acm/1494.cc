#include <stdio.h>
long long calc(long long f, long long s, long long n) {
    if(n==0) return f;
    else if(n==1) return s;
    else if(n==2) return f>s?f-s:s-f;
    else {
        if(f < s) return calc(s,s-f,n-1);
        else if(f==s || s==0) {
            if(n%3 == 0) return f;
            else if(n%3 == 1) return s;
            else return f-s;
        } else {
            long long x = 2*s;
            if(f >= x) {
                long long y = f/x;
                if(n >= 3*y) return calc(f-x*y,s,n-3*y);
                else return calc(f-(n/3)*x,s,n-3*(n/3));
            } else return calc(s,f>s?f-s:s-f,n-1);
        }
    }
}
int main() {
    long long f, s, d, n;
    scanf("%lld %lld %lld", &f, &s, &n);
    for(int i=0; i<n; i++) {
        scanf("%lld", &d);
        printf("%lld\n", calc(f,s,d));
    }
    return 0;
}
