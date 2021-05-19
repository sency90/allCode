#include <cstdio>
#include <vector>
using namespace std;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
vvi A,B;
bool vis[51][51];
bool chg(vvi &A, int &r, int &c) {
    int dif = int(A.size())-(r+3);
    if(dif<0) {
        r+=dif;
        if(r<0) return false;
    }
    dif = int(A[0].size())-(c+3);
    if(dif<0) {
        c+=dif;
        if(c<0) return false;
    }
    if(vis[r][c]) return false;
    vis[r][c]=true;

    for(int i=r; i<r+3; i++) {
        for(int j=c; j<c+3; j++) {
            A[i][j]^=1;
        }
    }
    return true;
}
pii cmp(vvi &A, vvi &B, int r) {
    for(int i=r; i<A.size(); i++) {
        for(int j=0; j<A[i].size(); j++) {
            if(A[i][j]!=B[i][j]) return pii(i,j);
        }
    }
    return pii(-1,-1);
}
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    A.resize(n,vector<int>(m));
    B.resize(n,vector<int>(m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%1d", &A[i][j]);
        }
    }
    bool good=true;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%1d", &B[i][j]);
            if(B[i][j]!=A[i][j]) good=false;
        }
    }
    if(good) return 0&puts("0");
    if(n<3||m<3) return 0&printf("-1");

    int r=0;
    for(int cnt=0;;cnt++) {
        pii co = cmp(A,B,r);
        if(co.first==-1 && co.second==-1) return 0&printf("%d", cnt);
        if(!chg(A,co.first,co.second)) return 0&puts("-1");
        r=co.first;
    }
    return 0;
}
