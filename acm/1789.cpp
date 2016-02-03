#include <stdio.h>

long long n, s, sum;
int main() {
    sum = 0;
    scanf("%lld", &s);

    for(long long n=1; n<s; n++) {
        sum += n;
        if(sum > s) {
            printf("%lld\n", n-1);
            break;
        } else if(sum == s) {
            printf("%lld\n", n);
            break;
        }
    }

    return 0;
}
