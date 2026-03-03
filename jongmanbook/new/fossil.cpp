#include <bits/stdc++.h>
using namespace std;
using pdd = pair<double, double>;
inline double PI() {
    static double pi = acos(-1);
    return pi;
}
vector<pdd> v, w;
int GetIdx12clockCoord(vector<pdd>& g) {
    double mx = -101;
    int mxi = -1;
    for (int i = 0; i < g.size(); i++) {
        if (mx < g[i].second) {
            mx = g[i].second;
            mxi = i;
        }
    }
    return mxi;
}
inline double GetTheta(double x, double y) {
    return fmod(atan2(y, x) + 2 * PI(), 2 * PI());
}
void SortByConvexHullOrder(vector<pdd>& g) {
    if (g.empty()) return;
    //12시 방향 제일 윗 좌표를 고른다.
    int idx = GetIdx12clockCoord(g);
    if (idx != 0) swap(g[0], g[idx]);

    double gijun = GetTheta(0, 1);
    for (int i = 0; i < g.size() - 1; i++) {
        double mn_nt = 2 * PI();
        double mnj = -1;
        for (int j = i + 1; j < g.size(); j++) {
            double nx = g[j].first - g[i].first;
            double ny = g[j].second - g[i].second;
            double theta = GetTheta(nx, ny);
            double nt = fmod(theta - gijun + 4 * PI(), 2 * PI());

            if (mn_nt > nt) {
                mn_nt = nt;
                mnj = j;
            }
        }
        if (i + 1 != mnj) swap(g[i + 1], g[mnj]);
        gijun += mn_nt;
    }
}

void GetIncCo(vector<pdd>& in, vector<pdd>& out, vector<pdd>& ret) {
    //in.size()-1까지 반복문을 도는 것은 in[0]가 in vector의 마지막에 한번 더 추가되었기 때문이다.
    //이 처리는 out vector에도 동일하게 적용되어있다.
    for (int i = 0; i < in.size() - 1; i++) {
        double prv_theta = 0;
        bool isInc = true;
        for (int j = 0; j < out.size(); j++) {
            double nx = out[j].first - in[i].first;
            double ny = out[j].second - in[i].second;
            double theta = GetTheta(nx, ny);
            if (j != 0) {
                double nt = fmod(theta - prv_theta + 2 * PI(), 2 * PI());
                if (nt > PI()) {
                    isInc = false;
                    break;
                }
            }
            prv_theta = theta;
        }
        if (isInc) ret.push_back(in[i]);
    }
}

inline pdd VectorMinus(pdd x, pdd y) {
    return pdd(x.first - y.first, x.second - y.second);
}
inline pdd VectorPlus(pdd x, pdd y) {
    return pdd(x.first + y.first, x.second + y.second);
}
inline pdd VectorMul(double t, pdd x) {
    return pdd(t * x.first, t * x.second);
}
inline int Sign(double x) {
    return (x > -1e-8) - (x < 1e-8);
}
inline double Cross(pdd x, pdd y) {
    return x.first * y.second - x.second * y.first;
}
inline int Ccw(pdd x, pdd y) {
    return Sign(Cross(x, y));
}
void GetIntersection(int vi, int vj, int wi, int wj, vector<pdd>& cvh) {
    pdd a = VectorMinus(v[vj], v[vi]);
    pdd b = VectorMinus(v[vj], w[wi]);
    pdd c = VectorMinus(v[vj], w[wj]);
    pdd d = VectorMinus(w[wj], w[wi]);
    pdd e = VectorMinus(w[wj], v[vi]);
    pdd f = VectorMinus(w[wj], v[vj]);

    //교점이 있는 경우
    if (Ccw(a, b) * Ccw(a, c) <= 0 && Ccw(d, e) * Ccw(d, f) <= 0) {
        double r = Cross(VectorMinus(v[vj], v[vi]), VectorMinus(w[wj], w[wi]));
        if (fabs(r) < 1e-8) return; //교점이 없음.

        double q = Cross(VectorMinus(w[wi], v[vi]), VectorMinus(w[wj], w[wi]));
        double t = q / r;

        pdd insec = VectorPlus(v[vi], VectorMul(t, VectorMinus(v[vj], v[vi])));
        cvh.push_back(insec);
    }
}
double F(vector<pdd>& g, double x) {
    static vector<double> ans;
    ans.clear();
    for (int i = 0; i < g.size() - 1; i++) {
        if ((g[i].first <= x && x <= g[i + 1].first) ||
            (g[i + 1].first <= x && x <= g[i].first)) {
            if (fabs(g[i].first - g[i + 1].first) < 1e-8) { //==0
                ans.push_back(g[i].second);
                ans.push_back(g[i + 1].second);
            }
            else if (fabs(g[i].second - g[i + 1].second) < 1e-8) {
                ans.push_back(g[i].second);
            }
            else {
                double a = (g[i].second - g[i + 1].second) / (g[i].first - g[i + 1].first);
                ans.push_back(a * (x - g[i].first) + g[i].second);
            }
        }
    }
    if (ans.empty()) return 0.0;
    sort(ans.begin(), ans.end());
    return ans.back() - ans[0];
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        v.clear(); w.clear();
        for (int i = 0; i < n; i++) {
            double x, y;
            cin >> x >> y;
            v.emplace_back(x, y);
        }
        for (int i = 0; i < m; i++) {
            double x, y;
            cin >> x >> y;
            w.emplace_back(x, y);
        }

        //처음 고른 좌표부터 Convex Hull을 그리는 좌표 순서로 정렬한다.
        SortByConvexHullOrder(v);
        SortByConvexHullOrder(w);

        //GetIntersection()에서 Convex Hull의 선분을 한바퀴 돌아야 하기 때문에
        //가장 첫번째 점인 v[0],w[0]를 맨 마지막에도 한번 더 넣어준다.
        v.push_back(v[0]);
        w.push_back(w[0]);

        static vector<pdd> cvh;
        cvh.clear();
        //두 ConvexHull의 모든 교점 구하기
        for (int i = 0; i < v.size() - 1; i++) {
            for (int j = 0; j < w.size() - 1; j++) {
                GetIntersection(i, i + 1, j, j + 1, cvh);
            }
        }
        //for(int i=0; i<cvh.size(); i++) {
        //    printf("(%.3lf, %.3lf)\n", cvh[i].first, cvh[i].second);
        //}
        //puts("");
        //한쪽 ConvexHull의 점이 다른 한쪽의 ConvexHull 안으로 들어가는 경우 cvh에 추가.
        GetIncCo(v, w, cvh);
        GetIncCo(w, v, cvh);
        SortByConvexHullOrder(cvh);
        //for(int i=0; i<cvh.size(); i++) {
        //    printf("(%.3lf, %.3lf)\n", cvh[i].first, cvh[i].second);
        //}

        double ans = 0.0;
        if (cvh.size() > 2) { //ternary search
            double lo = 101, hi = -1.0;
            for (int i = 0; i < cvh.size(); i++) {
                lo = min(lo, cvh[i].first);
                hi = max(hi, cvh[i].first);
            }

            cvh.push_back(cvh[0]);
            for (int z = 0; z < 100; z++) {
                double lmid = (lo * 2 + hi) / 3;
                double rmid = (lo + hi * 2) / 3;

                double lres = F(cvh, lmid);
                double rres = F(cvh, rmid);
                if (lres < rres) lo = lmid;
                else hi = rmid;
            }

            ans = F(cvh, lo);
        }
        printf("%.10lf\n", ans);
    }

    return 0;
}