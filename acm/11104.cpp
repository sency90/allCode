#include <stdio.h>
int bi[25];
void spow(int x) {
    int res = 1;
    bi[0] = res;
    for(int i=1; i<=x; i++) {
        res *= 2;
        bi[i] = res;
    }
}
int main() {
    int res, i, n;
    char c;
    scanf("%d ", &n);
    spow(24);
    while(n--) {
        i = 24;
        res = 0;
        while((c=getchar())!='\n' && c!='\r' && c!=EOF) {
            i--;
            if(c=='1') {
                res += bi[i];
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
