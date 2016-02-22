#include <stdio.h>
#include <string.h>
bool v[101];
int main() {
    int d, cnt=0;
    memset(v, false, sizeof(v));
    int n; scanf("%d", &n);
    while(n--) {
        scanf("%d", &d);
        if(v[d]) cnt++;
        else v[d] = true;
    }
    printf("%d", cnt);
    return 0;
}
