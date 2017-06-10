#include <iostream>
using namespace std;
int w[31],g[8],n;
inline int ABS(int x) {
    return x<0?-x:x;
}
char s[]={'N','Y'};
bool d[31][26000],chk[31][26000];
bool f(int x,int sum) {
    sum = ABS(sum);
    bool &ret = d[x][sum];
    if(x==n) return ret=true;
    if(chk[x][sum]) return ret;
    chk[x][sum]=true;

    for(int i=x+1; i<=n; i++) {
        ret = f(i,sum) | f(i,sum+w[i]) | f(i,sum-w[i]);
    }
    return ret;

}
int main() {
    scanf("%d",&n);
    for(int i=1; i<=n; i++) {
        scanf("%d",&w[i]);
    }
    f(0,0);

    int m;
    scanf("%d",&m);
    for(int i=0; i<m; i++) {
        int x; scanf("%d",&x);
        printf("%c ",s[d[n][x]]);
    }
    return 0;
}
