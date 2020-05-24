#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
struct Info{
    int x,y,z;
    Info(){}
    Info(int x, int y, int z):x(x),y(y),z(z) {}
    bool operator<(const Info & rhs) const {
        if(x==rhs.x) {
            if(y==rhs.y) return z<rhs.z;
            else return y<rhs.y; 
        }
        else return x<rhs.x;
    }
};
queue<Info> q;

int v[101][101][101];
bool chk[101][101][101];
int dx[] = {1,-1,0,0,0,0};
int dy[] = {0,0,1,-1,0,0};
int dz[] = {0,0,0,0,1,-1};
int main() {
    int n,m,h; scanf("%d%d%d",&n,&m,&h);
    for(int k=0; k<h; k++) {
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                scanf("%d", &v[i][j][k]);
                if(v[i][j][k]==1) q.emplace(i,j,k);
            }
        }
    }
    int ans=0;
    while(!q.empty()) {
        int sz = q.size();
        for(int z=0; z<sz; z++) {
            Info info = q.front(); q.pop();
            for(int i=0; i<6; i++) {
                int nx = info.x + dx[i];
                int ny = info.y + dy[i];
                int nz = info.z + dz[i];
                if(nx<0 || ny<0 || nz<0 || nx>=m || ny>=n || nz>=h) continue;
                else if(v[nx][ny][nz]==0) {
                    v[nx][ny][nz]=1;
                    q.emplace(nx,ny,nz);
                }
            }
        }
        ans++;
    }

    for(int k=0; k<h; k++) {
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(v[i][j][k]==0) {
                    return 0&puts("-1");
                }
            }
        }
    }

    printf("%d", ans-1);
    return 0;
}
