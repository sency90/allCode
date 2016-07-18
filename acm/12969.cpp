#include <stdio.h>
char ans[31];
bool d[31][31][31][500], chk[31][31][31][500];
int n, k;
bool f(int x, int a, int b, int c) {
    if(x==n) {
        if(c==k) return true;
        else return false;
    }
    if(d[x][a][b][c]) return false;
    d[x][a][b][c] = true;

    ans[x]='A';
    if(f(x+1,a+1,b,c)) return true;

    ans[x]='B';
    if(f(x+1,a,b+1,c+a)) return true;

    ans[x]='C';
    if(f(x+1,a,b,c+a+b)) return true;

    return false;
}
int main() {
    scanf("%d%d",&n,&k);
    if(f(0,0,0,0)) printf("%s", ans);
    else puts("-1");
    return 0;
}
