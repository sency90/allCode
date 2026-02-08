#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int m;
double n,p;
bool Judge(double n, int m, double c) {
    if(n<=0) return true;
    else if(m==0) return n<=0;

    return Judge(n*(1.0+p/1200.0)-c,m-1,c);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        cin >> n >> m >> p;
        double lo=0, hi=2*n;
        for(int z=0; z<100; z++) {
            double mid = (lo + hi) / 2;
            if(Judge(n, m, mid)) hi=mid;
            else lo=mid;
        }
        printf("%.8lf\n", hi);
    }
    return 0;
}
