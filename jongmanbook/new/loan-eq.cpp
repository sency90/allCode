#include <bits/stdc++.h>
using namespace std;
double n, p;
int m;
double Pow(double x, int n) {
    if(n==0) return 1.0;
    double ret = Pow(x,n/2);
    if(n%2==0) return ret*ret;
    else return ret*ret*x;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n >> m >> p;
        double x = Pow(1.0+p/1200, m);
        printf("%.10lf\n", (n*p/1200)*x/(x-1));
    }
    return 0;
}