#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
typedef pair<int,int> pii;
vector<bool> target;
vector<bool> chk;
vector<int> ans;
vector<vector<pii>> v;
struct Info{
    Info() {}
    Info(int x, int d, bool isgh):x(x),d(d),isgh(isgh) {}
    int x,d;
    bool isgh;
    bool operator<(const Info & rhs) const {
        if(d==rhs.d) return !isgh;
        else return d>rhs.d; //mxh
    }
};
priority_queue<Info> mnh;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        target.clear(); chk.clear(); v.clear(); ans.clear();
        int n,m,t; cin >> n >> m >> t;
        target.resize(n+1, false);
        chk.resize(n+1, false);
        v.resize(n+1, vector<pii>());
        ans.resize(n+1, 0);
        int s,g,h; cin >> s >> g >> h;
        for(int i=0; i<m; i++) {
            int x,y,d; cin >> x >> y >> d;
            v[x].emplace_back(y,d);
            v[y].emplace_back(x,d);
        }
        for(int i=0; i<t; i++) {
            int k; cin >> k;
            target[k] = true;
        }

        mnh.emplace(s,0,false);
        while(!mnh.empty()) {
            Info info = mnh.top(); mnh.pop();
            if(target[info.x]) {
                if(!info.isgh) {
                    if(ans[info.x]==0) ans[info.x] = -1;
                    else if(ans[info.x]<0) continue;
                }
                else {
                    if(ans[info.x]==0) ans[info.x] = info.d;
                    else continue;
                }
            }
            if(chk[info.x]) continue;
            chk[info.x] = true;
            for(int i=0; i<v[info.x].size(); i++) {
                int y = v[info.x][i].first;
                int d = v[info.x][i].second;
                if(info.isgh) mnh.emplace(y, info.d+d, true);
                else if((info.x==g && y==h) || (info.x==h && y==g)) mnh.emplace(y, info.d+d, true);
                else mnh.emplace(y, info.d+d, false);
            }
        }
        for(int i=1; i<=n; i++) if(ans[i]>0) printf("%d ", i);
        puts("");
    }

    return 0;
}
