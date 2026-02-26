#include <bits/stdc++.h>
using namespace std;
constexpr double EPSILON = 1e-9;
const double PI = acos(-1.0);
struct Vec{
    double x,y;
    explicit Vec(double x=0, double y=0):x(x),y(y) {}

    bool operator==(const Vec & rhs) const {
        return x==rhs.x && y==rhs.y;
    }
    bool operator<(const Vec & rhs) const {
        return x!=rhs.x? x<rhs.x: y<rhs.y;
    }
    Vec operator+(const Vec & rhs) const {
        return Vec(x+rhs.x, y+rhs.y);
    }
    Vec operator-(const Vec & rhs) const {
        return Vec(x-rhs.x, y-rhs.y);
    }
    Vec operator*(double k) const {
        return Vec(k*x, k*y);
    }
    double Dot(const Vec & rhs) const {
        return x*rhs.x + y*rhs.y;
    }
    double Cross(const Vec & rhs) const {
        return x*rhs.y - y*rhs.x;
    }
    double Length() const {
        return hypot(x,y);
    }
    Vec UnitVec() const {
        if(Length() == 0.0) return Vec(0.0, 0.0);
        return Vec(x/Length(), y/Length());
    }
    double Angle() const {
        return fmod(atan2(y,x)+2*PI, 2*PI);
    }
    Vec ProjectTo(const Vec & rhs) const {
        Vec rhs_unit = rhs.UnitVec();
        return rhs_unit * (this->Dot(rhs_unit));
    }
};

double Ccw(const Vec & lhs, const Vec & rhs) {
    return lhs.Cross(rhs);
}
double Ccw(const Vec & p, const Vec & a, const Vec & b) {
    return Ccw(a-p,b-p);
}

struct LineSeg{ //선분
    Vec v[2];
    bool HasIntersection(const LineSeg & rhs) const {
        Vec p = v[1]-v[0];
        Vec a = rhs.v[0]-v[0];
        Vec b = rhs.v[1]-v[0];
        double r1 = p.Cross(a);
        double r2 = p.Cross(b);
        if(fabs(r1)<EPSILON && fabs(r2)<EPSILON) { // if(r1 == 0 && r2 == 0) -> 모두 하나의 직선 위에 있다.
            return HasParallelSeg(rhs);
        }
        else {
            return r1*r2<=0.0;
        }
    }
    bool HasParallelSeg(const LineSeg & rhs) const {
        LineSeg l = *this;
        LineSeg r = rhs;
        if(l.v[1] < l.v[0]) std::swap(l.v[0], l.v[1]);
        if(r.v[1] < r.v[0]) std::swap(r.v[0], r.v[1]);

        if(l.v[1]<r.v[0] || r.v[1]<l.v[0]) return false;
        else return true;
    }
    shared_ptr<Vec> GetIntersectionVec(const LineSeg & rhs) const {
        if(!HasIntersection(rhs)) return nullptr;

        Vec a = rhs.v[1]-rhs.v[0];
        Vec b = rhs.v[0]-v[0];
        Vec c = v[1]-v[0];

        double t = b.Cross(a) / c.Cross(a);
        return make_shared<Vec>(c*t + v[0]);
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    return 0;
}