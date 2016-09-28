#include <cstdio>
using namespace std;
const int mod = 9901;
int main() {
    int n;
    scanf("%d",&n);
    int a=2, b=1, tmp;
    for(int i=1; i<n; i++) {
        tmp = (a+2*b)%mod;
        b=(a+b)%mod;
        a=tmp;
    }
    printf("%d\n", (a+b)%mod);
    return 0;
}
