#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int v[3001][3001], g[3001][3001];
vector<ll> s;
int r,c,h,w;
bool istrue(int md) {
    for(int i=1; i<=r; i++) {
        for(int j=1; j<=c; j++) {
            if(v[i][j]<md) g[i][j]=-1;
            else if(v[i][j]==md) g[i][j]=0;
            else g[i][j]=1;
            g[i][j]+=g[i-1][j]+g[i][j-1]-g[i-1][j-1];
        }
    }
    for(int i=h; i<=r; i++) {
        for(int j=w; j<=c; j++) {
            if(g[i][j]+g[i-h][j-w]-g[i][j-w]-g[i-h][j] < 0) return false;
        }
    }
    return true;
}
int main() {
    scanf("%d%d%d%d",&r,&c,&h,&w);
    for(int i=1; i<=r; i++) {
        for(int j=1; j<=c; j++) {
            scanf("%d", &v[i][j]);
        }
    }
    int lo=1LL, hi=r*c;
    while(lo <= hi) {
        int md=(lo+hi)>>1;
        if(istrue(md)) lo=md+1;
        else hi=md-1;
    }
    printf("%d", lo-1);
    return 0;
}
