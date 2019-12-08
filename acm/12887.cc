#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
char s[2][51];
int dx[]={1,0,-1}, dy[]={0,1,0};
bool chk[2][51];
vector<int> v[102];
typedef pair<int,int> pii;
int main() {
    int m; scanf("%d", &m);
    for(int i=0; i<2; i++) {
        scanf("%s", s[i]);
    }
    int wCnt=0;
    for(int i=0; i<2; i++){
        for(int j=0; j<m; j++) {
            if(s[i][j]=='.') {
                for(int k=0; k<3; k++) {
                    int nx=i+dx[k], ny=j+dy[k];
                    if(nx<0 || nx>=2 || ny<0 || ny>=m) continue;
                    if(s[nx][ny]=='.') {
                        v[i*2+j].push_back(nx*2+ny);
                        v[nx*2+ny].push_back(i*2+j);
                    }
                }
                wCnt++;
            }
        }
    }

    queue<pii> q;
    q.push(pii(0,0));
    q.push(pii(1,0));
    chk[0][0]=chk[1][0] = true;

    int cnt=1;
    while(!q.empty()) {
        int sz = q.size();
        for(int z=0; z<sz; z++) {
            pii p = q.front(); q.pop();
            if(p.second == m-1) {
                printf("wCnt: %d\n", wCnt);
                printf("cnt: %d\n", cnt);
                return 0&printf("%d", wCnt-cnt);
            }
            for(int k=0; k<3; k++) {
                int nx=p.first+dx[k], ny=p.second+dy[k];
                if(nx<0 || nx>=2 || ny<0 || ny>=m) continue;
                if(chk[nx][ny]) continue;
                chk[nx][ny] = true;
                q.push(pii(nx,ny));
            }
        }
        cnt++;
    }

    return 0;
}
