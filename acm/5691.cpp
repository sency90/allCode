#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
    long long a, b, c;
    while(1) {
        scanf("%lld %lld", &a, &b);
        if(a==0 && b==0) return 0;
        c = min(min(2*a-b, 2*b-a), (a+b)/2);
        printf("%lld\n", c);
    }
    return 0;
}
