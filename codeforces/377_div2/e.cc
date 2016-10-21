#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef pair<int,int> pii;
map<int, pair<int,vector<int> > > c;
vector<pii> s;
int ause[200001], ans[200001];
int main() {
    int n,m,x;
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++) scanf("%d",&x), c[x].first=0, c[x].second.push_back(i);
    for(int i=0; i<m; i++) scanf("%d", &x), s.push_back({x,i});

    sort(s.begin(), s.end());
    int tacnt=0, comcnt=0;
    for(auto &soc: s) {
        for(int i=0,t=soc.first;;i++) {
            if(c.count(t)) {
                ause[soc.second]=i;
                tacnt+=i;
                comcnt++;
                int &idx=c[t].first;
                ans[c[t].second[idx]]=soc.second+1;
                if(++idx == c[t].second.size()) c.erase(t);
                break;
            }
            if(t==1) break;
            else t=(t>>1)+(t&1);
        }
    }
    printf("%d %d\n", comcnt, tacnt);
    for(int i=0; i<m; i++) printf("%d%c", ause[i]," \n"[i==m]);
    for(int i=0; i<n; i++) printf("%d%c", ans[i]," \n"[i==n]);
    return 0;
}
