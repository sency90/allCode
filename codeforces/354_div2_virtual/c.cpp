#include <stdio.h>
int n, k;
char s[100001];
int d[100001];
int bs(int l, int r) {
    if(l>=r) return l;
    int m=(l+r+1)/2;
    bool isGood = false;
    for(int i=m; i<=n; i++) {
        int dif = d[i]-d[i-m];
        if(dif<=k || m-dif<=k) {
            isGood = true;
            break;
        }
    }
    if(isGood) return bs(m,r);
    else return bs(l,m-1);
}
int main() {
    scanf("%d%d",&n,&k);
    scanf("%s", s);
    for(int i=0; i<n; i++) {
        d[i+1]=d[i]+(s[i]=='a');
    }
    printf("%d", bs(0,n));
    return 0;
}
