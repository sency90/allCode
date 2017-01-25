#include <cstdio>
using namespace std;
typedef unsigned long long ull;
ull gcd(ull b, ull s) { return (s==0)?b:gcd(s,b%s); }
int main() {
    ull x,y; scanf("%llu%llu",&x,&y);
    ull res=gcd(x,y);
    for(int i=0; i<res; i++) putchar('1');
    return 0;
}
