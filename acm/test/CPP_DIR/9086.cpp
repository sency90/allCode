#include <stdio.h>
#include <string.h>
char str[1001];
int main() {
    int t, len;
    scanf("%d", &t);
    while(t--) {
        scanf("%s", str);
        len = strlen(str);
        printf("%c%c\n", str[0], str[len-1]);
    }
    return 0;
}
