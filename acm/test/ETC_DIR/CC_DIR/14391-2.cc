#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
using namespace std;
#define S 1
#define G 0
int v[5][5], mat[5][5];
int n,m;
bool ison(int x, int pos) {
    return x&(1<<pos);
}
int mk(int x, int y, int b, int cnt) {
    int ret = 0;
    if(b==G) {
        for(int i=y; i<y+cnt; i++) {
            ret *= 10;
            ret += v[x][i];
        }
    } else {
        for(int i=x; i<x+cnt; i++) {
            ret *= 10;
            ret += v[i][y];
        }
    }
    return ret;
}

bool chk[4][4];
int f(int x) {
    int ret = 0;
    memset(chk,false,sizeof(chk));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(chk[i][j]) continue;
            chk[i][j]=true;
            int cur = i*m+j;
            if(ison(x,cur)) {
                int cnt=1;
                for(int k=i+1; k<n; k++) {
                    cur = k*m+j;
                    if(ison(x,cur)&&!chk[k][j]) {
                        chk[k][j]=true;
                        cnt++;
                    } else break;
                }
                ret+=mk(i,j,S,cnt);
            } else {
                int cnt=1;
                for(int k=j+1; k<m; k++) {
                    cur = i*m+k;
                    if(!ison(x,cur)&&!chk[i][k]) {
                        chk[i][k]=true;
                        cnt++;
                    } else break;
                }
                ret+=mk(i,j,G,cnt);
            }
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            assert(chk[i][j]);
        }
    }
    return ret;
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%1d",&v[i][j]);
        }
    }
    int lim = (1<<(n*m)), mx=0;
    for(int i=0; i<lim; i++) {
        mx = max(mx, f(i));
    }
    printf("%d", mx);
    return 0;
}
