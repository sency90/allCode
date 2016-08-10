#include <stdio.h>
#include <cstring>
using namespace std;
int d[11];
int f(int x) {
    if(x<0) return 0;
    else if(x==1||x==0) return 1;
    if(d[x]>0) return d[x];
    return d[x] = f(x-1)+f(x-2)+f(x-3);
}
int main() {
    int tc; scanf("%d", &tc);
    while(tc--) {
        int x;
        scanf("%d", &x);
        memset(d, 0, sizeof(d));
        printf("%d\n", f(x));
    }
    return 0;
}
