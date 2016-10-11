#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
vector<pair<int,int> > v;
vector<vector<pair<int,int> > > group;
char mp[22][22], gno[22][22];
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
int main() {
    int tc; scanf("%d", &tc);
    while(tc--) {
        v.clear();
        queue<pair<int,int> > q;
        memset(mp, 0, sizeof(mp));
        memset(gno, 0, sizeof(gno));
        int n,m; scanf("%d%d",&n,&m);
        for(int i=0; i<n; i++) {
            scanf("%s", mp[i]);
            for(int j=0; j<m; j++) {
                if(mp[i][j]=='.') v.push_back(make_pair(i,j));
            }
        }

        int g=0;
        for(auto &it: v) {
            if(gno[it.first][it.second]) continue;
            q.push(it); gno[it.first][it.second]=++g;
            while(!q.empty()) {
                int x=q.front().first, y=q.front().second; q.pop();
                for(int i=0; i<4; i++) {
                    int nx=x+dx[i], ny=y+dy[i];
                    if(nx<0||ny<0||nx>=n||ny>=m) continue;
                    if(mp[nx][ny]=='#') continue;
                    if(gno[nx][ny]) continue;
                    gno[nx][ny]=g;
                    q.push(make_pair(nx,ny));
                }
            }
        }

        group.clear();
        group.resize(g+1, vector<pair<int,int> >());
        for(auto &it: v) {
            int x=it.first, y=it.second;
            group[gno[x][y]].push_back(it);
        }
        int ans=0;
        for(int i=1;i<=g;i++) {
            int odd=0, even=0;
            for(auto &it: group[i]) {
                int x=it.first, y=it.second;
                if((x+y)&1) odd++;
                else even++;
            }
            ans+=(odd>even)?odd:even;
            bool oddmany=(odd>even)?true:false;
            if(oddmany) {
                for(auto &it: group[i]) {
                    int x=it.first, y=it.second;
                    if((x+y)&1) mp[x][y]='^';
                }
            } else {
                for(auto &it: group[i]) {
                    int x=it.first, y=it.second;
                    if(!((x+y)&1)) mp[x][y]='^';
                }
            }
        }
        printf("%d\n", ans);
        for(int i=0; i<n; i++) {
            printf("%s\n", mp[i]);
        }
    }
    return 0;
}
