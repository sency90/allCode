#include <stdio.h>
#include <string.h>
char s[21];
int main() {
    scanf("%s", s);
    int len = strlen(s);
    for(int i=0; i<len; i++) {
        printf("'%c'\n", s[i]);
    }
    return 0;
}
