#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 0x3f3f3f3f;
int v[101][101], g[101][101];
int cnt[2];
int row[2][101], col[2][101];
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%d", &v[i][j]);
            g[i][j]=v[i][j];
        }
    }
    for(int i=0; i<n; i++) {
        int mn = inf;
        for(int j=0; j<m; j++) {
            mn=min(mn,v[i][j]);
        }
        if(mn>0) {
            row[0][i+1]+=mn;
            cnt[0]+=mn;
            for(int j=0; j<m; j++) {
                v[i][j]-=mn;
            }
        }
    }
    for(int j=0; j<m; j++) {
        int mn = inf;
        for(int i=0; i<n; i++) {
            mn=min(mn,v[i][j]);
        }
        if(mn>0) {
            col[0][j+1]+=mn;
            cnt[0]+=mn;
            for(int i=0; i<n; i++) {
                v[i][j]-=mn;
            }
        }
    }

    for(int j=0; j<m; j++) {
        int mn = inf;
        for(int i=0; i<n; i++) {
            mn=min(mn,g[i][j]);
        }
        if(mn>0) {
            col[1][j+1]+=mn;
            cnt[1]+=mn;
            for(int i=0; i<n; i++) {
                g[i][j]-=mn;
            }
        }
    }
    for(int i=0; i<n; i++) {
        int mn = inf;
        for(int j=0; j<m; j++) {
            mn=min(mn,g[i][j]);
        }
        if(mn>0) {
            row[1][i+1]+=mn;
            cnt[1]+=mn;
            for(int j=0; j<m; j++) {
                g[i][j]-=mn;
            }
        }
    }

    bool hasAns[2];
    hasAns[0]=hasAns[1]=true;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(v[i][j]) hasAns[0]=false;
            if(g[i][j]) hasAns[1]=false;
        }
    }
    if(!hasAns[0] && !hasAns[1]) puts("-1");
    else {
        int mnidx;
        if(cnt[0]<=cnt[1]) mnidx=0;
        else mnidx=1;

        printf("%d\n", cnt[mnidx]);
        for(int i=1; i<=n; i++) {
            while(row[mnidx][i]-- >0) printf("row %d\n",i);
        }
        for(int i=1; i<=m; i++) {
            while(col[mnidx][i]-- >0) printf("col %d\n",i);
        }

    }
    return 0;
}
