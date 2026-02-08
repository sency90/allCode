#include <bits/stdc++.h>
using namespace std;
using pdd = pair<double, double>;
inline double PI() {
    static double pi = acos(-1);
    return pi;
}
vector<pdd> v, w;
int GetIdx12clockCoord(vector<pdd> & g) {
    double mx = -101;
    int mxi = -1;
    for(int i=0; i<g.size(); i++) {
        if(mx < g[i].second) {
            mx = g[i].second;
            mxi = i;
        }
    }
    return mxi;
}
inline double GetTheta(double x, double y) {
    return fmod(atan2(y,x)+2*PI(), 2*PI());
}
void SortByConvexHullOrder(vector<pdd> & g) {
    //12시 방향 제일 윗 좌표를 고른다.
    int idx = GetIdx12clockCoord(g);
    if (idx != 0) swap(g[0], g[idx]);

    double gijun = GetTheta(0,1);
    for (int i = 0; i < g.size()-1; i++) {
        double mn_nt = 2*PI();
        double mnj = -1;
        for (int j = i+1; j < g.size(); j++) {
            double nx = g[j].first - g[i].first;
            double ny = g[j].second - g[i].second;
            double theta = GetTheta(nx, ny);
            double nt = fmod(theta-gijun + 4*PI(), 2*PI());

            if(mn_nt > nt) {
                mn_nt = nt;
                mnj = j;
            }
        }
        if(i+1 != mnj) swap(g[i+1], g[mnj]);
        gijun += mn_nt;
    }
}

void GetIncIdx(vector<pdd> & in, vector<pdd> & out, vector<int> & in_idx) {
    in_idx.clear();

    out.push_back(out[0]);
    for(int i=0; i<in.size(); i++) {
        double prv_theta = 0;
        bool isInc = true;
        for(int j=0; j<out.size(); j++) {
            double nx = out[j].first - in[i].first;
            double ny = out[j].second - in[i].second;
            double theta = GetTheta(nx, ny);
            if(j!=0) {
                double nt = fmod(theta-prv_theta+2*PI(), 2*PI());
                if(nt>PI()) {
                    isInc = false;
                    break;
                }
            }
            prv_theta = theta;
        }
        if(isInc) in_idx.push_back(i);
    }
    out.pop_back();
}

int Trim(int x, int n) {
    if(x<0) return (x+n)%n;
    else if(x>=n) return x%n;
    else return x;
}
inline pdd VectorMinus(pdd x, pdd y) {
    return pdd(x.first-y.first, x.second-y.second);
}
inline pdd VectorPlus(pdd x, pdd y) {
    return pdd(x.first+y.first, x.second+y.second);
}
inline pdd VectorMul(double t, pdd x) {
    return pdd(t*x.first, t*x.second);
}
inline int Sign(double x) {
    return (x>-1e-8)-(x<1e-8);
}
inline double Cross(pdd x, pdd y) {
    return x.first*y.second-x.second*y.first;
}
inline int Ccw(pdd x, pdd y) {
    return Sign(Cross(x,y));
}
void GetIntersection(int vi, int vj, int wi, int wj, vector<pdd> & cvh) {
    vi=Trim(vi,v.size());
    vj=Trim(vj,v.size());
    wi=Trim(wi,w.size());
    wj=Trim(wj,w.size());


    pdd a = VectorMinus(v[vj],v[vi]);
    pdd b = VectorMinus(v[vj],w[wi]);
    pdd c = VectorMinus(v[vj],w[wj]);
    pdd d = VectorMinus(w[wj],w[wi]);
    pdd e = VectorMinus(w[wj],v[vi]);
    pdd f = VectorMinus(w[wj],v[vj]);
    
    //교점이 있는 경우
    if(Ccw(a,b)*Ccw(a,c)<=0 && Ccw(d,e)*Ccw(d,f)<=0) {
        double r = Cross(VectorMinus(v[vj],v[vi]),VectorMinus(w[wj],w[wi]));
        if(fabs(r)<1e-8) return; //교점이 없음.

        double q = Cross(VectorMinus(w[wi],v[vi]),VectorMinus(w[wj],w[wi]));
        double t = q/r;

        pdd insec = VectorPlus(v[vi], VectorMul(t,VectorMinus(v[vj],v[vi])));
        cvh.push_back(insec);
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin>> tc;
    while(tc--) {
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

        //v->w 포함하는 idx를 받아 vidx에 저장.
        static vector<int> vidx, widx;
        GetIncIdx(v,w,vidx);
        GetIncIdx(w,v,widx);

        static vector<pdd> cvh; //new ConvexHull
        cvh.clear();

        if (!vidx.empty() && !widx.empty()) {
            //1. 두 선분 (v[vidx[0]-1], v[vidx[0]]), (w[widx[0]-1], w[widx[0]]) 교점 구하기
            //2. 두 선분 (v[vidx[0]-1], v[vidx[0]]), (w[widx.back()], w[widx.back()+1]) 교점 구하기
            //3. 두 선분 (v[vidx.back()], v[vidx.back()+1]), (w[widx[0]-1], w[widx[0]]) 교점 구하기
            //4. 두 선분 (v[vidx.back()], v[vidx.back()+1]), (w[widx.back()], w[widx.back()+1]) 교점 구하기
            //위의 1,2,3,4중 2개의 교점이 구해질 것이고, 두 교점과 vidx와 widx들이 이루는 다각형은 새로운 ConvexHull을 구성
            GetIntersection(vidx[0] - 1, vidx[0], widx[0] - 1, widx[0], cvh);
            GetIntersection(vidx[0] - 1, vidx[0], widx.back(), widx.back() + 1, cvh);
            GetIntersection(vidx.back(), vidx.back() + 1, widx[0] - 1, widx[0], cvh);
            GetIntersection(vidx.back(), vidx.back() + 1, widx.back(), widx.back() + 1, cvh);
            for (int i = 0; i < vidx.size(); i++) cvh.push_back(v[vidx[i]]);
            for (int i = 0; i < widx.size(); i++) cvh.push_back(w[widx[i]]);
            SortByConvexHullOrder(cvh);
        }
        else if(!vidx.empty()) {
            for (int i = 0; i < vidx.size(); i++) cvh.push_back(v[vidx[i]]);
        }
        else if(!widx.empty()) {
            for (int i = 0; i < widx.size(); i++) cvh.push_back(w[widx[i]]);
        }

        if(cvh.size()<=2) {
            printf("%.8lf\n", 0);
        }
        else {

        }
    }
    
    return 0;
}