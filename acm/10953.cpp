#include <stdio.h>
#include <ctype.h>
int main() {
    char c, res;
    int n; scanf("%d", &n);
    c=getchar();
    while(n--) {
        res = 0;
        while((c=getchar())!='\n' && c!=EOF) {
            if(isdigit(c)) res += c-48;
        }
        printf("%hhd\n", res);
    }
    return 0;
}
