#include <stdio.h>
#include <algorithm>
using namespace std;
int gcd(int b, int l) {
    if(b%l!=0) return gcd(l,b%l);
    else return l;
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    if(n<m) swap(n,m);
    printf("%d", n+m-gcd(n,m));
    return 0;
}
