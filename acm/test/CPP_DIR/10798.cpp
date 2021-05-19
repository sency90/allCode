#include <stdio.h>
#include <string.h>
int main() {
    int i=0, j, len=0, maxlen=0;
    char str[5][16];
    memset(str, '\0', sizeof(str));

    while(scanf("%s", str[i])!=EOF) {
        len = strlen(str[i++]);
        if(maxlen < len) maxlen = len;
    }
    for(i=0; i<maxlen; i++) {
        for(j=0; j<5; j++) {
            if(str[j][i]=='\0') continue;
            printf("%c", str[j][i]);
        }
    }
    return 0;
}
