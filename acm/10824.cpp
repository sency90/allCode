#include <stdio.h>
int ten(int x) {
    int sum = 1;
    while(x--) {
        sum *= 10;
    }
    return sum;
}

long long makeNum(long long f, long long e){
    char i;
    for(i=6; i>=0; i--) {
        if(e/ten(i) > 0) break;
    }
    return f*ten(++i)+e;
}

int main() {
    long long a[4];
    for(int i=0; i<4; i++) scanf("%lld", &a[i]);
    a[0] = makeNum(a[0], a[1]);
    a[2] = makeNum(a[2], a[3]);
    printf("%lld\n", a[0]+a[2]);
    return 0;
}
