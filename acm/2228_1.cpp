#include <cstdio>
int a[101];
int s[101];
int d[101][101];
bool c[101][101];
int min = -32768*101;
int go(int n, int m) {
    if (m == 0) {
        return 0;
    }
    if (n <= 0) {
        return min;
    }
    if (c[n][m]) return d[n][m];
    c[n][m] = true;
    int &ans = d[n][m];
    ans = go(n-1,m);
    for (int i=1; i<=n; i++) {
        int temp = go(i-2, m-1) + s[n]-s[i-1];
        if (ans < temp) ans = temp;
    }
    return ans;
}
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i=1; i<=n; i++) {
        scanf("%d",&a[i]);
        s[i] = s[i-1] + a[i];
    }
    printf("%d\n", go(n,m));
    return 0;
}
