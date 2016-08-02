#include <cstdio>
using namespace std;
double n,p,rates;
int m;
double balance(double c) {
    double bal=n;
    for(int i=0; i<m; i++) {
        bal = bal+bal*rates-c;
    }
    return bal;
}
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%lf%d%lf",&n,&m,&p);
        rates = p/1200.0;
        double l=0, r=n+n*rates, ans;
        while(l<=r+1e-7) {
            double mid = (l+r)/2.0;
            if(balance(mid)<0) {
                ans=mid;
                r=mid-1e-7;
            } else l=mid+1e-7;
        }
        printf("%0.7lf\n", ans);
    }
    return 0;
}
