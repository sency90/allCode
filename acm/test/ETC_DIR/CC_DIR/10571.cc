#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int d[201][201];
vector<pair<double, double> > v;
int f(int cur, int last) {
    if(cur==v.size()) return 0;

    int &ret = d[cur][last];
    if(ret!=-1) return ret;

    ret = f(cur+1,last);
    if(v[last].first<v[cur].first && v[last].second<v[cur].second) {
        ret = max(ret, f(cur+1,cur)+1);
    }
    return ret;
}
int main() {
    int tc, n;
    scanf("%d", &tc);
    while(tc--) {
        double a,b;
        scanf("%d", &n);
        memset(d, -1, sizeof(d));
        v.clear();
        v.push_back(make_pair(-1,-1));
        for(int i=0; i<n; i++) {
            scanf("%lf%lf",&a,&b);
            v.push_back(make_pair(a, 10.0-b));
        }
        printf("%d\n", f(1,0));
    }
    return 0;
}
