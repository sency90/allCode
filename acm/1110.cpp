#include <stdio.h>

int main() {
    int input, cnt = 0;
    int a, b;
    int c;
    scanf("%d", &input);
    c = input;

    do {
        ++cnt;

        b = c % 10;
        a = c / 10;
        c = a + b;
        c = c%10 + b*10;
    } while(c != input);

    printf("%d\n", cnt);

    return 0;
}
