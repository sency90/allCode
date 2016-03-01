#include <stdio.h>
int main() {
    int x; scanf("%d", &x);
    x = 1000 - x;
    int cnt = x/500;
    x %= 500;
    cnt += x/100;
    x %= 100;
    cnt += x/50;
    x %= 50;
    cnt += x/10;
    x %= 10;
    cnt += x/5;
    x %= 5;
    cnt += x/1;
    x %= 1;
    printf("%d", cnt);
    return 0;
}
