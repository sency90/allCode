#include <stdio.h>
void f(int x) {
    if(x<10) {
        printf("%d\n", x);
        return;
    }
    int res = 1;
    printf("%d ", x);
    while(x != 0) {
        res*=(x%10);
        x/=10;
    }
    f(res);
}
int main() {
    int d;
    while(true) {
        scanf("%d", &d);
        if(d == 0) return 0;
        f(d);
    }
    return 0;
}
