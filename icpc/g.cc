#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int> > v;
vector<pair<int,int> > co;
set<int> s;
int main() {
    int tc;
    scanf("%d",&tc);
    while(tc--) {
        int n,m,x,y;
        v.clear(); co.clear(); s.clear();
        v.resize(100001, vector<int>());
        scanf("%d",&n);
        for(int i=0; i<n; i++) {
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
            s.insert(x);
        }
        int py;
        auto cmp = [](int i, int j){return i>j;};
        for(auto &p : s) {
            sort(v[p].begin(), v[p].end());
            if(p==0) {
                if(v[0][0]!=0) sort(v[0].begin(), v[0].end(), cmp);
                py = v[0][v[0].size()-1];
            } else {
                if(v[p][0]==py) py=v[p][v[p].size()-1];
                else {
                    sort(v[p].begin(), v[p].end(), cmp);
                    py=v[p][v[p].size()-1];
                }
            }
            for(int j=0; j<v[p].size(); j++) {
                co.push_back(make_pair(p,v[p][j]));
            }
        }

        scanf("%d",&m);
        for(int i=0; i<m; i++) {
            scanf("%d", &x);
            printf("%d %d\n", co[x-1].first, co[x-1].second);
        }
    }
    return 0;
}
