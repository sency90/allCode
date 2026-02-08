#include <bits/stdc++.h>
using namespace std;
int n,t;
double a[21],b[21];
double f(double x) {
    double res=(1/a[0])*x + (1/b[0])*(t-x);
    for(int i=1; i<n-1; i++) {
        res = min(res, (1/a[i])*x + (1/b[i])*(t-x));
    }
    return res - (1/a[n-1]*x + 1/b[n-1]*(t-x));
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc;
    while(cin >> t) {
        cin >> n;
        for(int i=0; i<n; i++) {
            cin >> a[i] >> b[i];
        }

        double lo=0, hi=t;
        for(int i=0; i<100; i++) {
            double l=(lo*2+hi)/3;
            double r=(lo+hi*2)/3;
            double fl = f(l);
            double fr = f(r);
            if(fr<fl) hi=r;
            else lo=l;
        }

        double ans = (lo+hi)/2;
        double fans = f(ans);

        if(fans < -1e-9) puts("The cheater cannot win.");
        else {
            if(fans<0) fans=0;
            int ifans = round(fans*3600.0);
            printf("The cheater can win by %d seconds with r = %.2lfkm and k = %.2lfkm.\n", ifans, ans, t - ans);
        }
    }
    return 0;
}