#include <bits/stdc++.h>
using namespace std;
int n,k;
int r[1001], c[1001];
vector<double> v;
bool Judge(double x) {
    v.clear();
    for(int i=0; i<n; i++) {
        v.push_back(x*c[i]-r[i]);
    }
    sort(v.begin(), v.end());
    double sum=0;
    for(int i=n-k; i<n; i++) {
        sum+=v[i];
    }
    return sum>=0;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n >> k;
        for(int i=0; i<n; i++) {
            cin >> r[i] >> c[i];
        }
        double lo=0, hi=1;
        while(hi-lo>1e-14) {
            double mid = (lo+hi)/2;
            if(Judge(mid)) hi=mid;
            else lo=mid;
        }
        printf("%.10lf\n", hi);
    }
    return 0;
}