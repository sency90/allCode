#include <stdio.h>
#include <string.h>
int main() {
    int x[10001], in, n;
    scanf("%d", &n);
    memset(x, 0, sizeof(x));
    while(n--){
        scanf("%d", &in);
        x[in]++;
    }
    for(short i=0; i<10001; i++) {
        while(x[i]--) printf("%hd\n", i);
    }
    return 0;
}
