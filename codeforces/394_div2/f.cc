#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
int mn=0x3f3f3f3f, all=0;
int psum[1001][1001], dif[300001];
char s[1001], e[2];
int main() {
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0; i<n; i++) {
        scanf("%s", s);
        for(int j=0; j<m; j++) {
            psum[i][j+1]=psum[i][j]+int(s[j]-'a');
        }
        all+=psum[i][m];
    }
    for(int i=0; i<k; i++) {
        int a,b,c,d;
        scanf("%d%d%d%d%s",&a,&b,&c,&d,e);
        a--; c--;
        int chg = abs((c-a+1)*(d-b+1)*int(e[0]-'a')), ori=0;
        for(int j=a; j<=c; j++) ori+=psum[j][d]-psum[j][b-1];
        dif[i]=all-ori+chg;
    }
    if(k==1) return 0&puts("0");
    sort(dif, dif+k);
    for(int i=1; i<k; i++) {
        mn=min(mn,abs(dif[i]-dif[i-1]));
    }
    printf("%d\n", mn);
    return 0;
}

