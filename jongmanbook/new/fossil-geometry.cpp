#include <bits/stdc++.h>
using namespace std;
constexpr double ES = 1e-8; //Epsilon
constexpr double NA = 105.0; //Not Available

inline double PI() {
    static const double pi = acos(-1.0);
    return pi;
}
inline int Sign(double x) {
    return (x>-ES)-(x<ES);
}
struct Vec {
    double x,y;
    Vec() {}
    Vec(double x, double y):x(x),y(y) {}
    bool operator<(const Vec & rhs) const {
        return (x!=rhs.x ? x<rhs.x : y<rhs.y);
    }
    bool operator==(const Vec & rhs) const {
        return x==rhs.x && y==rhs.y;
    }
    bool operator<=(const Vec & rhs) const {
        return (*this < rhs || *this == rhs);
    }
    Vec operator*(double k) const {
        return Vec(k*x, k*y);
    }
    Vec operator-(const Vec & rhs) const {
        return Vec(x-rhs.x,y-rhs.y);
    }
    Vec operator+(const Vec & rhs) const {
        return Vec(x+rhs.x,y+rhs.y);
    }
    double PolarAngle() const {
        return fmod(atan2(y,x)+2*PI(), 2*PI());
    }
    double Dot(const Vec & rhs) const {
        return x*rhs.x + y*rhs.y;
    }
    double Cross(const Vec & rhs) const {
        return x*rhs.y - rhs.x*y;
    }
    double Len() const {
        return hypot(x,y);
    }
    Vec UnitVec() const {
        return Vec(x/Len(), y/Len());
    }
    Vec ProjectTo(const Vec & rhs) const {
        Vec uv = rhs.UnitVec();
        return uv*(this->Dot(uv));
    }
    int Ccw(const Vec & rhs) const {
        //return값은 아래와 같다.
        // 1) rhs가 *this의 CCW방향 위치에 있을 때: 1
        // 2) rhs가 *this의 CW방향 위치에 있을 때: -1
        // 3) rhs가 *this와 방향이 동일하거나 180도 정반대 방향일 때: 0

        return Sign(this->Cross(rhs));
    }
    void Print() const {
        printf("(%.3lf, %.3lf)\n", x,y);
    }
};
struct LineSeg { //선분
    Vec l,r;
    LineSeg() {}
    LineSeg(const Vec & lhs, const Vec & rhs) {
        if(rhs < lhs) l=rhs, r=lhs;
        else l=lhs, r=rhs;
    }
    bool HasIntersection(const LineSeg & rhs, Vec & intersection) const {
        Vec p = r-l;
        Vec a = rhs.r-l;
        Vec b = rhs.l-l;

        Vec q = rhs.r-rhs.l;
        Vec c = r-rhs.l;
        Vec d = l-rhs.l;

        if(p.Ccw(a)*p.Ccw(b)==0 && q.Ccw(c)*q.Ccw(d)==0) { //두 선분이 한 직선위에 있는 경우
            if(r<rhs.l || rhs.r<l) return false;
            else {
                //겹치는 부분이 최소 한 점 이상인 경우, 교차점을 아무거나 return
                if(rhs.l <= r) intersection = rhs.l;
                else intersection = r;
                return true;
            }
        }
        else {
            if(p.Ccw(a)*p.Ccw(b)<=0 && q.Ccw(c)*q.Ccw(d)<=0) {
                double t = (rhs.l-l).Cross(rhs.r-rhs.l) / (r-l).Cross(rhs.r-rhs.l);
                intersection = l + ((r-l)*t);
                return true; //p x a(외적)와 p x b의 부호가 다르면 교차점이 존재한다.
            }
            else return false;
        }
    }
    bool IsBetweenX(double x) const {
        double mn = min(l.x, r.x);
        double mx = max(l.x, r.x);
        return mn <= x && x <= mx;
    }

    //*this 선분에서 x좌표값에 해당하는 y좌표(f(x)) 값을 return한다.
    double F(double x) const {
        assert(r.x != l.x);

        if(IsBetweenX(x)) {
            double y = (r.y - l.y) / (r.x - l.x) * (x - l.x) + l.y;
            if (l.y <= r.y) {
                if (l.y <= y && y <= r.y) return y;
            }
            else {
                if (r.y <= y && y <= l.y) return y;
            }
        }
        return NA;
    }
};

double F(double x, vector<LineSeg> & ls) {
    for(int i=0; i<ls.size(); i++) {
        if(ls[i].r.x == ls[i].l.x) continue;

        double y = ls[i].F(x);
        if(y >= NA) continue;
        return y;
    }
    return NA;
}

//정점p가 Ccw로 정렬된 Convex Hull 안에 포함되는지를 본다.
//<=0으로 비교했기 때문에 Convex Hull 경계에 있어도 true를 리턴한다.
bool IsIn(Vec & p, vector<Vec> & ccw_cvh) {
    for(int i=1; i<ccw_cvh.size(); i++) {
        if((ccw_cvh[i]-ccw_cvh[i-1]).Ccw(p-ccw_cvh[i-1]) <= 0) return false;
    }
    return true;
}

void SortCvhByCcwOrder(vector<Vec>& u) {
    //모든 점의 중심점을 계산한다.
    double midx, midy;
    Vec mid(0.0, 0.0);
    for (int i = 0; i < u.size(); i++) {
        mid = mid + u[i];
    }
    mid = mid * (1.0/u.size());

    //중심점과 Convex Hull의 점점들 간의 PolarAngle값을 구하고, 그 값 순서로 정렬한다.
    auto cmp = [mid](const Vec& lhs, const Vec& rhs) {
        double lang = (lhs - mid).PolarAngle();
        double rang = (rhs - mid).PolarAngle();
        if (fabs(lang - rang) < ES) {
            return (lhs - mid).Len() < (rhs - mid).Len();
        }
        else return lang < rang;
        };

    sort(u.begin(), u.end(), cmp);
}

vector<Vec> v,w,u;
vector<LineSeg> ls_v, ls_w;
vector<LineSeg> lower_ls, upper_ls;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        v.clear(); w.clear();
        ls_v.clear(); ls_w.clear();
        int n,m; cin >> n >> m;

        double x,y;
        for(int i=0; i<n; i++) {
            cin >> x >> y;
            v.emplace_back(x,y);
        }
        v.emplace_back(v[0]);

        for(int i=0; i<m; i++) {
            cin >> x >> y;
            w.emplace_back(x,y);
        }
        w.emplace_back(w[0]);

        //Convex Hull을 선분으로 다시 표현.
        for(int i=0; i<n; i++) {
            ls_v.emplace_back(v[i],v[i+1]);
        }
        for(int i=0; i<m; i++) {
            ls_w.emplace_back(w[i],w[i+1]);
        }

        //u: 새로운 Convex Hull 정점들
        u.clear();
        Vec intsc;
        //1) v와 w의 교점을 u에 넣는다.
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(ls_v[i].HasIntersection(ls_w[j], intsc)) {
                    u.emplace_back(intsc);
                }
            }
        }

        //2) v의 정점이 w Convex Hull에 속하면 u에 넣는다.
        //   w의 정점이 v Convex Hull에 속하면 u에 넣는다.
        for(int i=0; i<n; i++) {
            if(IsIn(v[i], w)) u.emplace_back(v[i]);
        }
        for(int j=0; j<m; j++) {
            if(IsIn(w[j], v)) u.emplace_back(w[j]);
        }

        //u의 정점개수가 1개이하면, 문제의 답은 항상 0이다.
        if(u.size()<=1) {
            printf("%.8lf\n", 0.0);
            continue;
        }

        //u를 ccw 방향 순으로 정렬한다.
        SortCvhByCcwOrder(u);
        u.emplace_back(u[0]);

        lower_ls.clear();
        upper_ls.clear();
        for(int i=0; i<u.size()-1; i++) {
            if(u[i+1].x > u[i].x) lower_ls.emplace_back(u[i], u[i+1]);
            else if(u[i+1].x < u[i].x) upper_ls.emplace_back(u[i+1], u[i]);
        }

        double ans = 0.0;
        for(int i=0; i<u.size()-1; i++) {
            ans = max(ans, F(u[i].x, upper_ls) - F(u[i].x, lower_ls));
        }

        printf("%.8lf\n", ans);
    }
    return 0;
}