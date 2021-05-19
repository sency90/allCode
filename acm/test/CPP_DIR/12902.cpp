#include <stdio.h>
#include <algorithm>
using namespace std;
int gcd(int b, int l) {
    if(b<l) swap(b,l);
    if(b%l==0) return l;
    else return gcd(l, b%l);
}
int main() {
    int n, r, mx, d;
    scanf("%d", &n);
    scanf("%d", &d);
    r = d; mx=d;
    for(int i=1; i<n; i++){
        scanf("%d", &d);
        r = gcd(d, r);
        if(d>mx) mx=d;
    }
    printf("%s\n", ((int)(mx/r)-n)%2LL?"Alice":"Bob");
    return 0;
}
