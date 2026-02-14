#include <bits/stdc++.h>
using namespace std;
using pdd = pair<double, double>;
using ppddpdd = pair<pdd, pdd>;
vector<pdd> v, w;
vector<ppddpdd> upper, lower;
bool IsBetween(double x1, double x2, double x) {
    return (x1 <= x && x <= x2) || (x2 <= x && x <= x1);
}
double At(ppddpdd& line, double x) {
    double a = (line.second.second - line.first.second) / (line.second.first - line.first.first);
    return a * (x - line.first.first) + line.first.second;
}
double GetUpperY(vector<ppddpdd>& upper, double x) {
    double mn_y = 100;
    for (int i = 0; i < upper.size(); i++) {
        if (IsBetween(upper[i].first.first, upper[i].second.first, x)) {
            mn_y = min(mn_y, At(upper[i], x));
        }
    }
    return mn_y;
}
double GetLowerY(vector<ppddpdd>& lower, double x) {
    double mx_y = 0;
    for (int i = 0; i < lower.size(); i++) {
        if (IsBetween(lower[i].first.first, lower[i].second.first, x)) {
            mx_y = max(mx_y, At(lower[i], x));
        }
    }
    return mx_y;
}

double GetMinX(vector<pdd>& g) {
    double mn = 100;
    for (int i = 0; i < g.size() - 1; i++) {
        mn = min(mn, g[i].first);
    }
    return mn;
}

double GetMaxX(vector<pdd>& g) {
    double mx = 0;
    for (int i = 0; i < g.size() - 1; i++) {
        mx = max(mx, g[i].first);
    }
    return mx;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;

        v.clear(); w.clear();
        lower.clear(); upper.clear();
        double x, y;
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            v.emplace_back(x, y);
        }
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            w.emplace_back(x, y);
        }

        v.push_back(v[0]);
        w.push_back(w[0]);
        for (int i = 1; i < v.size(); i++) {
            if (v[i].first > v[i - 1].first) lower.emplace_back(v[i - 1], v[i]);
            else if (v[i].first < v[i - 1].first) upper.emplace_back(v[i], v[i - 1]);
        }
        for (int i = 1; i < w.size(); i++) {
            if (w[i].first > w[i - 1].first) lower.emplace_back(w[i - 1], w[i]);
            else if (w[i].first < w[i - 1].first) upper.emplace_back(w[i], w[i - 1]);
        }

        sort(lower.begin(), lower.end());
        sort(upper.begin(), upper.end());

        double lo = max(GetMinX(v), GetMinX(w));
        double hi = min(GetMaxX(v), GetMaxX(w));
        for (int z = 0; z < 100; z++) {
            double lmid = (lo * 2 + hi) / 3;
            double rmid = (lo + hi * 2) / 3;
            double lres = GetUpperY(upper, lmid) - GetLowerY(lower, lmid);
            double rres = GetUpperY(upper, rmid) - GetLowerY(lower, rmid);
            if (lres < rres) lo = lmid;
            else hi = rmid;
        }

        double ans_x = lo;
        double ans_len = GetUpperY(upper, ans_x) - GetLowerY(lower, ans_x);
        if (ans_len < 0) ans_len = 0.0;
        printf("%.8lf\n", ans_len);
    }
    return 0;
}