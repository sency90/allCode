#include <cstdio>
#include <cmath>
using namespace std;
const double pi = 2.0*acos(0.0);
const double pi2 = 2.0*pi;
double revision(double x) { return double(int(x*1e6))/1e6; }
double chg(double x, double t) { return (x<0.0)? pi2-t:t; }
int main() {
    freopen("./a_input.txt", "r", stdin);
    freopen("./a_output.txt", "w", stdout);
    int tc; scanf("%d", &tc);
    for(int z=1; z<=tc; z++) {
        double x,y,r=50.0,p;
        scanf("%lf%lf%lf",&p,&x,&y);
        bool white=false;
        x=revision(x-r); y=revision(y-r);
        double d=x*x+y*y;
        if(d>r*r||p==0.0) white=true;
        else {
            if(d==0.0) white=false;
            else {
                double t = acos(y/sqrt(d));
                white = !(chg(x,t)/pi2*100.0 <= p);
            }
        }
        printf("Case #%d: %s\n", z, (white)?"white":"black");
    }
    return 0;
}
