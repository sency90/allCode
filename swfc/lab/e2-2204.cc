#include <iostream>
#include <algorithm>
using namespace std;
char s[501];
int d[501][501];
bool chk[501][501];
int f(int x,int y) {
    if(x>=y) return 0;

    int &ret = d[x][y];
    if(chk[x][y]) return ret;
    chk[x][y]=true;

    if((s[x]=='a'&&s[y]=='t') || (s[x]=='g'&&s[y]=='c')) {
        ret = max(ret,f(x+1,y-1)+2);
    }
    for(int i=x; i<y; i++) {
        ret = max(ret,f(x,i)+f(i+1,y));
    }
    return ret;
}
int main() {
    //freopen("input.txt","r",stdin);
    scanf("%s",s);
    int len=0;
    for(; s[len]; len++);

    printf("%d",f(0,len-1));
    return 0;
}
