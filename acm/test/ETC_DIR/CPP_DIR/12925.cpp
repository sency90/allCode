//choiking10 code
#include <map>
#include <iostream>
#include <cstdio>
#include <cmath>
struct eq{
    long long a, b;
    eq operator*(eq e1){
        eq ret;
        ret.a = (a*e1.a + 5 * b*e1.b)%1000;
        ret.b = (a*e1.b + e1.a * b)%1000;
        return ret;
    }
};
eq mpow(eq e,int n){
    if (n == 1) {
        return e;
    }
    auto ret = mpow(e, n/2);
    ret = ret * ret;
    if (n % 2) ret = ret * e;
    return ret;
}
int main(void){
    int T;
    scanf("%d", &T);
    for(int t = 1; t<= T;t++){
        int n;
        scanf("%d", &n);
        eq e;
        e.a = 3; e.b = 1;
        e = mpow(e, n);
        printf("Case #%d: %03lld\n", t, (2 * e.a - 1) % 1000);
    }
}
