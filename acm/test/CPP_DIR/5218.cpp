#include <stdio.h>
#include <string.h>
char x[21], y[21];
int main() {
    int t, len;
    scanf("%d", &t);
    while(t--) {
        scanf("%s %s", x, y);
        len = strlen(x);
        printf("Distances: ");
        for(int i=0; i<len; i++) {
            if(y[i]>=x[i]) printf("%d ", y[i]-x[i]);
            else printf("%d ", y[i]+26-x[i]);
        }
        puts("");
    }
    return 0;
}
