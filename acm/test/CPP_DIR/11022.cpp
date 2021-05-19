#include <stdio.h>
#include <ctype.h>
int main() {
    char a[2], c, res, j;
    int n; scanf("%d", &n);
    c=getchar();
    for(int i=0; i<n; i++) {
        res = 0;
        j = 0;
        while((c=getchar())!='\n' && c!=EOF) {
            if(isdigit(c)) {
                a[j++] = c;
                res += c-48;
            }
        }
        printf("Case #%d: %d + %d = %hhd\n", i+1, a[0]-48, a[1]-48, res);
    }
    return 0;
}
