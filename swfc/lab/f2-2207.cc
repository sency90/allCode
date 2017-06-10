#include <iostream>
#include <algorithm>

using namespace std;
int v[1010],d[1010][1010];
bool chk[1010][1010];
const int inf = 0x3f3f3f;
int main() {
    //freopen("input.txt","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        scanf("%d",&v[i]);
    }
    for(int i=0; i<n; i++) d[i][i]=v[i];

    int mx=0;
    for(int len=1; len<n; len+=2) {
        for(int i=0; i+len<n; i++) {
            if(i+1>i+len-1) d[i][i+len]=(v[i]==v[i+len]);
            else d[i][i+len] = max(d[i][i+len],d[i+1][i+len-1]+(v[i]==v[i+len]));
            for(int k=i+1; k+1<i+len; k++) {
                d[i][i+len] = max(d[i][i+len],d[i][k]+d[k+1][i+len]);
            }
        }
    }
    printf("%d",d[0][n-1]);
    return 0;
}
