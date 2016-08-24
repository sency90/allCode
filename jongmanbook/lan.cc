#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int p[501], x[501],y;
pair<int,int> v[2000];
void init(int n) { for(int i=0; i<n; i++) p[i]=i; }
int find(int x) {
    if(x!=p[x]) p[x] = find(p[x]);
    return p[x];
}
bool uni(int x, int y) {
    x=find(x); y=find(y);
    if(x==y) return false;
    else p[y]=x;
    return true;
}
double dist(int s, int e) {
    return sqrt((double)(s*s)+(double)(e*e));
}
int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        int n,m,s,e;
        scanf("%d%d",&n,&m);
        init(n);
        vector<pair<double, pair<int,int> > > ed;
        for(int i=0; i<n; i++) scanf("%d", &x[i]);
        for(int i=0; i<n; i++) {
            scanf("%d", &y);
            v[i] = make_pair(x[i]+1000,y+1000);
        }
        double d;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                d = dist(v[i].first-v[j].first, v[i].second-v[j].second);
                ed.push_back(make_pair(d, make_pair(i,j)));
            }
        }
        for(int i=0; i<m; i++) {
            scanf("%d%d",&s,&e);
            uni(s, e);
        }

        sort(ed.begin(), ed.end());
        double ans = 0.0;
        for(auto &p : ed) {
            s=p.second.first; e=p.second.second;
            if(uni(s,e)) ans += p.first;
        }
        printf("%0.7lf\n", ans);
    }
    return 0;
}
