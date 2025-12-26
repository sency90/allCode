#include <bits/stdc++.h>
using namespace std;
using pdd = pair<double,double>;
const int INF = 0x3f3f3f3f;
inline double PI() {
    static const double value = acos(-1);
    return value;
}
inline double GetTheta(double x, double y) {
    return fmod(atan2(y, x) + 2 * PI(), 2 * PI());
}

vector<pdd> v;
int CountCover(int si, double final_dest) {
    if(final_dest <= v[si].second) return 1;

    double mx=-INF;
    int mxi = -1;
    for(int i=si+1; i<v.size(); i++) {
        if(v[i].first <= v[si].second) {
            if(mx < v[i].second) {
                mx = v[i].second;
                mxi = i;
            }
        }
        else break;
    }

    if(mxi == -1) return INF;
    else return CountCover(mxi, final_dest)+1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        v.clear();
        int n; cin >> n;
        double x, y, r, mx_r = 0;
        for (int i = 0; i < n; i++) {
            cin >> x >> y >> r;
            mx_r = max(r, mx_r);

            double theta = GetTheta(x,y);
            double delta = 2*asin(r/16.0);
            v.emplace_back(theta-delta, theta+delta);
        }

        if(mx_r>=16.0) {
            puts("1");
            continue;
        }

        for(int i=0; i<v.size(); i++) {
            if(v[i].second>=2*PI()) {
                v[i].first -= 2*PI();
                v[i].second -= 2*PI();
            }
        }

        sort(v.begin(), v.end());

        int ans = INF;
        for(int i=0; i<v.size(); i++) {
            if(v[i].first<=0) {
                ans = min(ans, CountCover(i, 2*PI() + v[i].first));
            }
        }
        if(ans==INF) puts("IMPOSSIBLE");
        else printf("%d\n", ans);
    }
    return 0;
}