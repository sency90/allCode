#include <cstdio>
#include <algorithm>
using namespace std;
double a[100001], b[100001], sum=0.0;
int main() {
    int n,p; scanf("%d%d",&n,&p);
    for(int i=0; i<n; i++) {
        scanf("%lf%lf",&a[i],&b[i]);
        sum+=a[i];
    }
    if(sum<=p) return 0&puts("-1");

    double l=0.0, r=1e14;
    for(int z=0; z<100; z++) {
        double t = (l+r)/2;
        sum=0.0;
        for(int i=0; i<n; i++) {
            sum += max(0.0, a[i]*t-b[i])/t;
        }
        if(sum<=p) l=t;
        else r=t;
    }
    printf("%.8lf\n", l);
    return 0;
}
