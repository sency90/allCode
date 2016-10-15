#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
vector<double> differentiate(const vector<double>& poly) {
    int n = poly.size()-1;
    vector<double> ret(n);
    for(int i=0; i<n; i++) {
        ret[i] = (i+1)*poly[i+1];
    }
    return ret;
}
vector<double> solveNaive(const vector<double>& poly) {
    vector<double> ret;
    double a=poly[2], b=poly[1], c=poly[0];
    double D = b*b-4*a*c, sqrtD;
    if(D<1e-8) ret.push_back(-b/(2*a));
    else {
        sqrtD = sqrt(D);
        ret.push_back((-b-sqrtD)/(2*a));
        ret.push_back((-b+sqrtD)/(2*a));
    }
    return ret;
}
double evaluate(const vector<double>& poly, double x0) {
    int n = poly.size()-1;
    double ret=poly[0], mul=1.0;
    for(int i=1; i<=n; i++) {
        mul *= x0;
        ret += poly[i]*mul;
    }
    return ret;
}

const double L=25;
vector<double> solve(const vector<double>& poly) {
    int n=poly.size()-1;
    if(n<=2) return solveNaive(poly);
    vector<double> derivative = differentiate(poly);
    vector<double> sols = solve(derivative);

    //이 극점들 사이를 하나하나 검사하며 근이 있나 확인한다.
    sols.insert(sols.begin(), -L-1);
    sols.insert(sols.end(), L+1);

    vector<double> ret;
    for(int i=0; i+1<sols.size(); i++) {
        double x1 = sols[i], x2 = sols[i+1];
        double y1 = evaluate(poly, x1), y2 = evaluate(poly, x2);

        //f(x1)과 f(x2)의 부호가 같은 경우 답은 없다.
        if(y1*y2 > 0) continue;

        //불변 조건: f(x1) <= 0 < f(x2)
        if(y1 > y2) {
            swap(y1, y2);
            swap(x1, x2);
        }

        //이분법을 사용하자.
        for(int iter=0; iter<100; ++iter) {
            double mx = (x1+x2)/2;
            double my = evaluate(poly,mx);
            if(y1*my > 0) {
                y1 = my;
                x1 = mx;
            } else {
                y2 = my;
                x2 = mx;
            }
        }
        ret.push_back((x1+x2)/2);
    }
    sort(ret.begin(), ret.end());
    return ret;
}
int main() {
    int t,n;
    scanf("%d",&t);
    while(t--) {
        scanf("%d", &n);
        vector<double> poly(n+1);
        for(int i=n; i>=0; i--) {
            scanf("%lf", &poly[i]);
        }
        for(auto &p : solve(poly)) {
            printf("%0.8lf ", p);
        } puts("");
    }
    return 0;
}
