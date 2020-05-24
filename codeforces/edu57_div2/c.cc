#include <cstdio>
#include <cstring>
using namespace std;
int ans[180];
int gcd(int b, int l) {
    return (l==0)?b:gcd(l, b%l);
}
int main() {
    int n; scanf("%d", &n);
    memset(ans, 0xff, sizeof(ans));
    for(int i=3; i<=360; i++) {
        int g = gcd(180,i);
        int a = 180/g, b = i/g;
        for(int j=1; b*j<=i-2; j++) {
            if(ans[j*a]==-1) ans[j*a]=i;
        }
    }

    for(int i=0; i<n; i++) {
        int x; scanf("%d", &x);
        if(ans[x]!=-1) printf("%d\n", ans[x]);
        else puts("-1");
    }
    return 0;
}
