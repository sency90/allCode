#include <cstdio>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
queue<pii> q;
const int B = 2000;
char s[51][51];
char v[4000][4000];
int dx[]={0,1,0,-1}, dy[]={1,0,-1,0};
int main() {
    int n,m,k;
    long long ans=0ll;
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++) {
        scanf("%s", s[i]);
        for(int j=0; j<m; j++) {
            if(s[i][j]=='o') {
                v[i+B][j+B]=s[i][j];
                q.push({i+B,j+B});
                ans++;
            }
        }
    }
    int cnt=0;
    scanf("%d", &k);
    if(ans==0ll) return 0&puts("0");
    while(!q.empty()) {
        int sz = q.size();
        for(int z=0; z<sz; z++) {
            pii t = q.front(); q.pop();
            for(int i=0; i<4; i++) {
                int nx=dx[i]+t.first, ny=dy[i]+t.second;
                if(v[nx][ny]=='o') continue;
                v[nx][ny]='o';
                ans++;
                q.push({nx,ny});
            }
        }
        if(++cnt==k) return 0&printf("%lld", ans);
    }
    return 0;
}
