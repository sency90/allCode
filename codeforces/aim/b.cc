#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int ABS(int x) { return x<0?-x:x; }
int main() {
    int n, a;
    scanf("%d%d",&n,&a);
    vector<int> v(n);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());
    if(n==1) {
        puts("0");
        return 0;
    }
    int l=v[0], ll=v[1], r=v[n-2], rr=v[n-1], tmp1=0, tmp2=0;
    if(l<a && a<r) tmp1 = ABS(l-a)+ABS(r-a)+min(ABS(l-a),ABS(r-a));
    else if(a<=l) tmp1 = ABS(r-a);
    else if(r<=a) tmp1 = ABS(l-a);
    if(ll<a && a<rr) tmp2 = ABS(ll-a)+ABS(rr-a)+min(ABS(ll-a),ABS(rr-a));
    else if(a<=ll) tmp2 = ABS(rr-a);
    else if(rr<=a) tmp2 = ABS(ll-a);
    printf("%d", min(tmp1, tmp2));
    return 0;
}
