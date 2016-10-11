#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
char mp[51][51];
int black[1260][1260], white[1260][1260], aMatch[1260], bMatch[1260];
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
bool chk[1260];
vector<vector<int> > v;
bool bipartite(int x) {
    if(chk[x]) return false;
    chk[x]=true;
    for(auto &y: v[x]) {
        if(!bMatch[y] || bipartite(bMatch[y])) {
            bMatch[y]=x;
            aMatch[x]=y;
            return true;
        }
    }
    return false;
}
int main() {
    int tc; scanf("%d", &tc);
    while(tc--) {
        memset(mp,0,sizeof(mp));
        memset(black,0,sizeof(black));
        memset(white,0,sizeof(white));
        memset(aMatch,0,sizeof(aMatch));
        memset(bMatch,0,sizeof(bMatch));
        int n,m; scanf("%d%d",&n,&m);
        int B=0, W=0;
        for(int i=0; i<n; i++) {
            scanf("%s",mp[i]);
            for(int j=0; j<m; j++) {
                if(mp[i][j]=='.') {
                    if((i+j)&1) black[i][j]=++B;
                    else white[i][j]=++W;
                }
            }
        }

        v.clear(); v.resize(B+1, vector<int>());
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(black[i][j]) {
                    for(int k=0; k<4; k++) {
                        int nx=i+dx[k], ny=j+dy[k];
                        if(nx<0||ny<0||nx>=n||ny>=m) continue;
                        if(white[nx][ny]) {
                            int x=black[i][j],y=white[nx][ny];
                            v[x].push_back(y);
                        }
                    }
                }
            }
        }

        int ans=0;
        for(int i=1; i<=B; i++) {
            memset(chk,false,sizeof(chk));
            if(bipartite(i)) ans++;
        }
        //printf("ans: %d,  B+W: %d\n",ans,B+W);
        if((ans<<1)==B+W) puts("YES");
        else puts("NO");
    }
    return 0;
}
