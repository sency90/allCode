#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) {
    return strcmp((char*)a, (char*)b);
}
int main() {
    char s[1000][1001];
    scanf("%s", s[0]);
    unsigned long len = strlen(s[0]);
    for(int i=1; i<len; i++) {
        strcpy(s[i], s[0]+i);
    }

    qsort((void *)s, len, sizeof(s[0]), cmp);
    for(int i=0; i<len; i++) {
        printf("%s\n", s[i]);
    }
    return 0;
}
