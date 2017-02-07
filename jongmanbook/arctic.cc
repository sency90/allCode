#include <cstdio>
#include <set>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;
typedef pair<double, double> pdd;
set<pdd> s;
vector<pdd> co;
priority_queue<pair<double,pair<int,int>>> mxh;
int p[101];
void init(int n) { for(int i=0; i<=n; i++) p[i]=i; }
int find(int x) {
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
bool uni(int x, int y) {
    x=find(x); y=find(y);
    if(x==y) return false;
    else {
        p[y]=x;
        return true;
    }
}
double dist(double x, double y) { return x*x+y*y; }
int main() {
    int tc; scanf("%d", &tc);
    while(tc--) {
        int n,ix;
        scanf("%d", &n);

        co.clear();
        s.clear();
        init(n);
        for(int i=0; i<n; i++) {
            double x,y;
            scanf("%lf%lf",&x,&y);
            if(s.count(pdd(x,y))) continue;
            else {
                s.insert(pdd(x,y));
                co.emplace_back(make_pair(x,y));
            }
        }

        for(int i=0; i<co.size(); i++) {
            for(int j=i+1; j<co.size(); j++) {
                double d=dist(co[i].first-co[j].first, co[i].second-co[j].second);
                mxh.push({-d,{i,j}});
            }
        }

        double ans=0.0;
        while(!mxh.empty()) {
            int u=mxh.top().second.first, v=mxh.top().second.second;
            double d=mxh.top().first; mxh.pop();
            if(uni(u,v)) ans=-d;
        }
        printf("%.2lf\n", sqrt(ans));
    }
    return 0;
}
