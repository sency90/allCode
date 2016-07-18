#include <iostream>
#include <cstring>
using namespace std;
int t,n,m,x,y;
bool f[10][10], chk[10];
int coupling() {
    int first=-1;
    for(int i=0; i<n; i++) {
        if(!chk[i]) {
            first=i;
            break;
        }
    }
    if(first==-1) return 1;

    int ret = 0;
    for(int i=first+1; i<n; i++) {
        if(chk[i] || !f[first][i]) continue;

        chk[first]=chk[i]=true;
        ret += coupling();
        chk[first]=chk[i]=false;
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        memset(chk, false, sizeof(chk));
        memset(f, false, sizeof(f));
        cin >> n >> m;
        for(int i=0; i<m; i++) {
            scanf("%d%d",&x,&y);
            f[x][y] = f[y][x] = true;
        }
        cout << coupling() << "\n";
    }
    return 0;
}
