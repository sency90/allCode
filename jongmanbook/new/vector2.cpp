#include <bits/stdc++.h>
using namespace std;
struct Vec{
    double x,y;

    const double PI = 2.0 * acos(0.0);

    explicit Vec(double x=0, double y=0):x(x),y(y) {}
    bool operator==(const Vec & rhs) const {
        return x==rhs.x && y==rhs.y;
    }
    bool operator<(const Vec & rhs) const {
        return x!=rhs.x ? x<rhs.x : y<rhs.y;
    }
    Vec operator+(const Vec & rhs) const {
        return Vec(x+rhs.x, y+rhs.y);
    }
    Vec operator-(const Vec & rhs) const {
        return Vec(x-rhs.x, y-rhs.y);
    }
    Vec operator*(double k) const {
        return Vec(x*k, y*k);
    }
    double Len() const { return hypot(x,y); }
    Vec Unit() const { return Vec(x/Len(), y/Len()); }
    
    double PolarAngle() const {
        return fmod(atan2(y,x)+2*PI, 2*PI);
    }
    double Dot(const Vec & rhs) const { //내적
        return x*rhs.x + y*rhs.y;
    }
    double Cross(const Vec & rhs) const { //외적
        return x*rhs.y - y*rhs.x;
    }
    Vec Project(const Vec & rhs) const { //rhs 벡터로 사영
        Vec unit_rhs = rhs.Unit();
        return unit_rhs * (this->Dot(unit_rhs));
    }
};
int main() {
    return 0;
}