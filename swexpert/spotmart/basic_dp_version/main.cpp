#include <stdio.h>
int max(int x, int y) { return x>y?x:y; }
int A[3001], d[2][3001];
int f(int prevState, int n) {
    if(n==0) return 0;
    int &ret = d[prevState][n];
    if(ret>=0) return ret;
    else ret=0;

    if(prevState == 0) ret = max(f(prevState,n-1),f(prevState^1,n-1));
    else ret = f(prevState^1,n-1)+A[n-1];
    return ret;
}
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &A[i]);
        d[0][i]=d[1][i]=-1;
    }
    d[0][n]=d[1][n]=-1;
    printf("%d\n", max(f(0,n),f(1,n)));
    return 0;
}
