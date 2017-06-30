#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
ll v[2000001],d[2000001];
int main() {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%lld", &v[i]);
        v[i+n]=v[i];
    }
    for(int i=1; i<n*2; i++) {
        d[i]=v[i]-v[i-1];
    }

    ll sum=0LL;
    for(int i=1; i<n; i++) {
        sum+=d[i];
    }
    printf("sum: %lld\n", sum);
    if(sum==n-1) return 0&puts("0 0");
    int mn = abs(sum-(n-1));
    int ans=0;
    for(int i=n; i<n*2; i++) {
        sum=sum+d[i]-d[i-n];
        if(mn > abs(sum-(n-1))) {
            mn=abs(sum-(n-1));
            ans=i;
        }
    }
    printf("ans: %d\n", ans);
    int d=0;
    for(int i=ans-(n-1),j=0; j<n; i++,j++) {
        d+=abs(i-v[i]);
    }
    printf("%d %d\n",d,ans-(n-1));
}
