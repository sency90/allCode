#include <stdio.h>
int a[20];
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++) {
        if(i==n-1) scanf("%d", &a[i]);
        else scanf("%d,", &a[i]);
    }
    if(m==0) {
        for(int i=0; i<n; i++) {
            if(i==n-1) printf("%d", a[i]);
            else printf("%d,", a[i]);
        }
        return 0;
    }

    for(int j=1; j<=m; j++) {
        for(int i=0; i<n-j; i++) {
            a[i] = a[i+1]-a[i];
        }
    }
    for(int i=0; i<n-m; i++) {
        if(i==n-m-1) printf("%d", a[i]);
        else printf("%d,",a[i]);
    }
    return 0;
}
