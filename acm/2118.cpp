#include <stdio.h>
int a[100000];
int main() {
    int n, s=0;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
        s+=a[i];
        a[i+n] = a[i];
    }
    int lim = s/2, t=2*n, p=0, ans=0, mx=0;
    for(int i=0; i<t; i++) {
        ans += a[i];
        while(ans > lim) {
            ans -= a[p++];
        }
        if(mx < ans) mx = ans;
        if(ans == lim) break;
    }
    printf("%d", mx);
    return 0;
}
