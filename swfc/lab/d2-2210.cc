#include <iostream>
#include <algorithm>
using namespace std;
int d[2001][2001], l[2001], r[2001];
int n;
bool chk[2001][2001];
int f(int x, int y) {
    if(x>=n||y>=n) return d[x][y]=0;

    int &ret = d[x][y];
    if(chk[x][y]) return ret;
    chk[x][y]=true;

    if(l[x]>r[y]) ret = max(f(x+1,y),f(x,y+1)+r[y]);
    else ret = max(f(x+1,y),f(x+1,y+1));
    return ret;
}
int main() {
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        scanf("%d",&l[i]);
    }
    for(int i=0; i<n; i++) {
        scanf("%d",&r[i]);
    }
    printf("%d",f(0,0));
    return 0;
}
