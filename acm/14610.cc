#include <iostream>
using namespace std;
int v[101][11], rcnt[101];
bool sol[11];
int main() {
    int n,m;
    scanf("%d%d", &n,&m);
    for(int i=0; i<n; i++) {
        int cnt=0;
        scanf("%d", &rcnt[i]);
        for(int j=0; j<m; j++) {
            scanf("%d", &v[i][j]);
            if(v[i][j]>0) {
                sol[j]=true;
                cnt++;
            }
        }
        rcnt[i]-=cnt;
        if(rcnt[i]<0) return 0&puts("NO");
        if(cnt==m) return 0&puts("NO");
    }

    for(int i=n-1; i>=0; i--) {
        for(int j=0; j<m; j++) {
            if(sol[j]) continue;
            else if(v[i][j]==-1 && rcnt[i]>0) rcnt[i]--, v[i][j]=1;
            if(v[i][j]>0) sol[j]=true;
        }
    }

    for(int i=n-1; i>=0; i--) {
        for(int j=0; j<m; j++) {
            if(rcnt[i]>0 && v[i][j]==-1) rcnt[i]--, v[i][j]=1;
        }
        if(rcnt[i]) return 0&puts("NO");
        for(int j=0; j<m; j++) {
            if(v[i][j]==-1) v[i][j]=0;
        }
    }

    for(int i=0; i<n; i++) {
        int cnt0=0, cnt1=0, cntm=0;
        for(int j=0; j<m; j++) {
            if(v[i][j]<0) cntm++;
            else if(v[i][j]==0) cnt0++;
            else cnt1++;
        }
        if(cntm>0 || cnt0==m || cnt1==m) return 0&puts("NO");
    }

    for(int j=0; j<m; j++) {
        int cnt0=0, cntm=0;
        for(int i=0; i<n; i++) {
            if(v[i][j]<0) cntm++;
            else if(v[i][j]==0) cnt0++;
        }
        if(cntm>0 || cnt0==n) return 0&puts("NO");
    }

    puts("YES");
    return 0;
}
