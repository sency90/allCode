#include <stdio.h>
#include <cstring>
using namespace std;
int d[12];
int f(int x) {
    if(x<0) return 0;
    if(x==0) return 1;
    return d[x] = f(x-1) + f(x-2) + f(x-3);
}
int main() {
    int n, x;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &x);
        printf("%d\n", f(x));
    }
    return 0;
}
