#include <stdio.h>
#include <string.h>
int main() {
    int n; scanf("%d", &n);
    char str[1001];
    int len;
    while(n--) {
        scanf("%s", str);
        len = strlen(str);
        if(str[len/2] == str[len/2-1]) printf("Do-it\n");
        else printf("Do-it-Not\n");
    }
    return 0;
}
