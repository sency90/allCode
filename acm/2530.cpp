#include <stdio.h>

int main() {
    unsigned short h, m, s;
    int time;
    scanf("%hu %hu %hu %d", &h, &m, &s, &time);
    s += time % 60;
    m += s / 60;
    s %= 60;

    m += time / 60;
    h += m / 60;
    m %= 60;

    h %= 24;

    printf("%hu %hu %hu\n", h, m, s);
    return 0;
}
