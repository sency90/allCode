#include <stdio.h>
#include <cmath>
using namespace std;
struct Coord{
    double x,y;
    Coord(){} Coord(double x, double y):x(x),y(y){}
};
Coord a[2],b[2];
double dist(double t) {
    Coord m = Coord((1-t)*a[0].x + t*a[1].x, (1-t)*a[0].y + t*a[1].y);
    Coord g = Coord((1-t)*b[0].x + t*b[1].x, (1-t)*b[0].y + t*b[1].y);
    return sqrt((m.x-g.x)*(m.x-g.x) + (m.y-g.y)*(m.y-g.y));
}
int main() {
    for(int i=0; i<2; i++) scanf("%lf%lf",&a[i].x,&a[i].y);
    for(int i=0; i<2; i++) scanf("%lf%lf",&b[i].x,&b[i].y);
    double l=0, r=1.0, midl, midr;
    for(int i=0; i<100; i++) {
        midl=(r+2.0*l)/3.0;
        midr=(2.0*r+l)/3.0;
        if(dist(midl) < dist(midr)) r=midr;
        else l=midl;
    }
    printf("%0.6lf\n", dist(r));
    return 0;
}
