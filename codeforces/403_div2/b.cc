#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef pair<double,double> pdd;
pdd a[60001];
int s[60001], v[60001];
int main() {
    int n,i; scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &s[i]);
    for(int i=0; i<n; i++) scanf("%d", &v[i]);
    double l=0, r=1e9, last;
    for(int z=0; z<350; z++) {
        double mid = (l+r)/2;
        for(int i=0; i<n; i++) {
            a[i] = pdd((double)s[i]-v[i]*mid, (double)s[i]+v[i]*mid);
        }
        sort(a, a+n);
        for(int i=0; i<n; i++) {
            printf("%.6lf, %.6lf\n", a[i].first, a[i].second);
        }
        last = 1e9;
        for(i=0; i<n; i++) {
            if(a[i].first>last) break;
            if(a[i].second<last) last=a[i].second;
        }
        if(i==n) r=mid;
        else l=mid;
    }
    printf("%.6lf\n", l);
    return 0;
}
