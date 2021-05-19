#include <stdio.h>
#include <ctype.h>
int main() {
    char c, res;
    int n; scanf("%d", &n);
    c=getchar();
    for(int i=0; i<n; i++) {
        res = 0;
        while((c=getchar())!='\n' && c!=EOF) {
            if(isdigit(c)) res += c-48;
        }
        printf("Case #%d: %hhd\n", i+1, res);
    }
    return 0;
}
