#include <bits/stdc++.h>
using namespace std;
int n;
double x[101], y[101];
int p[101];
int cnt[101];
inline void Init(int n) {
    for(int i=0; i<n; i++) {
        p[i] = i;
        cnt[i] = 1;
    }
}
int Find(int x) {
    if(x==p[x]) return p[x];
    else return p[x] = Find(p[x]);
}
bool Uni(int x, int y) {
    x = Find(x);
    y = Find(y);
    if(x==y) return false;
    if(x>y) swap(x,y);
    p[y] = x;
    cnt[x] += cnt[y];
    return true;
}
inline double Diff(double x, double y) {
    double ret = x-y;
    if(ret<0) return -ret;
    else return ret;
}
double Dist(int i, int j) {
    double dx = x[i]-x[j];
    double dy = y[i]-y[j];
    return sqrt(dx*dx + dy*dy);
}
bool Judge(double d) {
    Init(n);
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(Dist(i,j) < d + 1e-12) {
                if (Uni(i, j)) {
                    if (cnt[Find(i)] == n) return true;
                }
            }
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        cin >> n;
        for(int i=0; i<n; i++) {
            cin >> x[i] >> y[i];
        }

        double lo=0, hi=2000;
        while (Diff(lo,hi)>1e-12) {
            double mid = (lo+hi)/2;
            if(Judge(mid)) hi=mid;
            else lo=mid;
        }
        printf("%.2lf\n", hi);
    }
    return 0;
}