#include <cstdio>
#include <cstring>
using namespace std;
int chk[1001][1001];
int main() {
    freopen("/Users/lian/allCode/monster/input.txt", "r", stdin);
    freopen("/Users/lian/allCode/monster/output.txt", "w", stdout);
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        int n,m,x,y,w;
        puts("\n");
        scanf("%d%d",&n,&m);
        memset(chk,0,sizeof(chk));
        for(int i=0; i<m; i++) {
            scanf("%d%d%d",&x,&y,&w);
            if(chk[x][y]) {
                printf("%d %d %d %d\n",x,y,chk[x][y],w);
            }
            chk[x][y]=chk[y][x]=w;
        }
    }
    return 0;
}
