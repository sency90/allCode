#include <stdio.h>
int main() {
    char c;
    int n; scanf("%d", &n);
    getchar();
    for(int i=1; i<=n; i++) {
        printf("%d. ", i);
        while((c=getchar())!='\n' && c!=EOF && c!='\r') {
            printf("%c", c);
        }
        printf("\n");
    }
    return 0;
}
