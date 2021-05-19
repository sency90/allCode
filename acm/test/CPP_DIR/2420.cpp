#include <stdio.h>

int main() {

    long long a, b, c;
    scanf("%lld %lld", &a, &b);

    c = b-a;
    if(c < 0) c = -c; 
    printf("%lld\n", c);

    return 0;
}