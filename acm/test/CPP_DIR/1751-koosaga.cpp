#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long lint;

int n,m;
char s0[305][305], s1[305][305];
lint hash0[305][305], hash1[305][305];
lint pw[90005];

void make_hash(char s[][305], lint h[][305]){
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++){
            h[i][j] = (s[i][j] - '0');
            h[i][j] *= pw[m * i + j];
            h[i][j] += h[i][j-1] + h[i-1][j] - h[i-1][j-1];
        }
    }
}

bool chk(int x1, int y1, int x2, int y2){
    int rx1 = n - 1 - x2;
    int rx2 = n - 1 - x1;
    int ry1 = m - 1 - y2;
    int ry2 = m - 1 - y1;

    lint h0 = hash0[x2][y2] - (x1 ? hash0[x1-1][y2] : 0)
        - (y1 ? hash0[x2][y1-1] : 0) + (x1 && y1 ? hash0[x1-1][y1-1] : 0);

    lint h1 = hash1[rx2][ry2] - (rx1 ? hash1[rx1-1][ry2] : 0)
        - (ry1 ? hash1[rx2][ry1-1] : 0) + (rx1 && ry1 ? hash1[rx1-1][ry1-1] : 0);

    h0 *= pw[(n - x1) * m];
    h1 *= pw[(n - rx1) * m];
    h0 *= pw[m - y1];
    h1 *= pw[m - ry1];
    return h0 == h1;
}

int main(){
    scanf("%d %d",&n,&m);
    pw[0] = 1;
    for (int i=1; i<=n*m; i++) {
        pw[i] = pw[i-1] * 3;
    }
    for (int i=0; i<n; i++) {
        scanf("%s",s0[i]);
        strncpy(s1[n-i-1],s0[i],m);
    }
    for (int i=0; i<n; i++) {
        reverse(s1[i],s1[i] + m);
    }
    make_hash(s0,hash0);
    make_hash(s1,hash1);
    int res = 1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            for (int k=res+1; i+k-1<n && j+k-1<m; k++) {
                if(chk(i,j,i+k-1,j+k-1)) res = k;
            }
        }
    }
    printf("%d",res);
}
