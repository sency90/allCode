#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
string s[1001];
bool chk[1001][1001];
int n,m;
queue<pii> q;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int v[1001][1001];
void bfs(int val) {
    while(!q.empty()) {
        pii info = q.front(); q.pop();
        v[info.first][info.second] = val;
        for(int i=0; i<4; i++) {
            int nx = info.first+dx[i];
            int ny = info.second+dy[i];
            if(nx<0||ny<0||nx>=n||ny>=m) continue;
            if(chk[nx][ny]) continue;
            if(s[nx][ny]=='.') continue;
            chk[nx][ny] = true;
            q.push(pii(nx,ny));
        }
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >>n>>m;
    for(int i=0; i<n; i++) {
        cin >> s[i];
    }

    int ans=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(s[i][j]=='#' && !chk[i][j]) {
                q.push(pii(i,j));
                chk[i][j] = true;
                bfs(++ans);
            }
        }
    }

    int rowcnt=0, colcnt=0;
    int prevEmpty=-0x3f3f3f3f;
    for(int i=0; i<n; i++) {
        bool empty = true;
        for(int j=0; j<m; j++) {
            if(v[i][j]) {
                empty = false;
                break;
            }
        }
        if(empty) {
            if(prevEmpty+1!=i) rowcnt++;
            prevEmpty = i;
        }
    }

    prevEmpty=-0x3f3f3f3f;
    for(int j=0; j<m; j++) {
        bool empty = true;
        for(int i=0; i<n; i++) {
            if(v[i][j]) {
                empty = false;
                break;
            }
        }
        if(empty) {
            if(prevEmpty+1!=j) colcnt++;
            prevEmpty = j;
        }
    }

    bool good = true;

    if(colcnt!=rowcnt && rowcnt!=n && colcnt!=m) {
        good = false;
        goto BRK;
    }

    for(int i=0; i<n; i++) {
        int mem=-1;
        bool ing=false, fnal=false;
        for(int j=0; j<m; j++) {
            if(mem<0 && v[i][j]!=0) {
                ing = true;
                mem = v[i][j];
            }
            else if(ing) {
                if(v[i][j]!=mem) {
                    if(v[i][j]==0) {
                        ing = false;
                        fnal = true;
                    }
                    else {
                        good = false;
                        goto BRK;
                    }
                }
            }
            else if(fnal) {
                if(v[i][j]!=0) {
                    good = false;
                    goto BRK;
                }
            }
        }
    }

    for(int j=0; j<m; j++) {
        int mem=-1;
        bool ing=false, fnal=false;
        for(int i=0; i<n; i++) {
            if(mem<0 && v[i][j]!=0) {
                ing = true;
                mem = v[i][j];
            }
            else if(ing) {
                if(v[i][j]!=mem) {
                    if(v[i][j]==0) {
                        ing = false;
                        fnal = true;
                    }
                    else {
                        good = false;
                        goto BRK;
                    }
                }
            }
            else if(fnal) {
                if(v[i][j]!=0) {
                    good = false;
                    goto BRK;
                }
            }
        }
    }

BRK:
    if(good) printf("%d\n", ans);
    else printf("-1");

    return 0;
}
