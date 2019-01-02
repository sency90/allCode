#include <stdio.h>
char s[51];
int main() {
    scanf("%[^\n]", s);
    printf("%s", s);
    return 0;
}
