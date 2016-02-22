#include <stdio.h>
#include <string.h>
bool d[10];
int main() {
    int x, t, n, i, cnt; scanf("%d", &n);
    while(n--) {
        memset(d, false, sizeof(d));
        cnt = 0;
        scanf("%d", &x);
        while((t = x/10) != 0) {
            d[x%10] = true;
            x = t;
        }
        d[x%10] = true;
        for(i=0; i<10; i++) {
            if(d[i]) cnt++;
        }
        printf("%d\n", cnt);
    }
}
