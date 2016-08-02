#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n,s[101];
int d[101][3];
bool chk[101][3];

int f(int x,int c) {
    if(x==n+1) return 0;
    if(chk[x][c]) return d[x][c];
    chk[x][c]=true;

    int ans = f(x+1,2)+1;
    if((s[x]==1 || s[x]==3) && c!=0) ans = min(ans,f(x+1,0));
    else if((s[x]==2 || s[x]==3) && c!=1) ans = min(ans,f(x+1,1));
    return d[x][c] = ans;
}

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&s[i]);
    printf("%d",f(1,2));
    return 0;
}
