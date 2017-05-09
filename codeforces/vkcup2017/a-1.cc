#include <cstdio>
#include <algorithm>
using namespace std;
double a[100001], b[100001];
int main() {
    int n,p;
    scanf("%d%d", &n,&p);
    double sum=0.0;
    for(int i=0; i<n; i++) {
        scanf("%lf%lf",&a[i],&b[i]);
        sum+=a[i];
    }
    if(sum<=p) return 0&puts("-1");

    double l=0, r=1e10;
    for(int z=0; z<100; z++) {
        double t = (l+r)/2;
        sum=0.0;
        for(int i=0; i<n; i++) {
            sum += max(a[i]*t-b[i],0.0);
        }
        if(sum<=t*p) l=t;
        else r=t;
    }
    printf("%.5lf", l);
    return 0;
}
