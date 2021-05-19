#include <cstdio>
using namespace std;
int t[51], x[51];
double ABS(double x) {
    if(x<0.0) return -x;
    else return x;
}
int main() {
    int n;
    double c;
    scanf("%d%lf",&n,&c);
    for(int i=0; i<n; i++) scanf("%d", &t[i]);
    for(int i=0; i<n; i++) scanf("%d", &x[i]);
    double lo=0.0,hi=1e9;
    while(ABS(lo-hi)>=1e-9) {
        double r = (lo+hi)/2;
        double sum = 0.0;
        for(int i=0; i<n; i++) {
            sum+=double(x[i]-r)*t[i];
            if(sum<=0.0) sum=0.0;
            if(sum>c) break;
        }
        //printf("%lf %lf %lf %lf\n",lo,hi,r,sum);
        if(sum>c) lo=r;
        else hi=r;
    }
    printf("%.10lf", hi);
    return 0;
}
