#include <stdio.h>
#include <cstring>
#define RND 100000
using namespace std;
int d[101][101][4];
int f(int x, int y, int dir) {
    if(d[x][y][dir] > 0) return d[x][y][dir];
    if(x==1 && y==1) {
        if(dir==0 || dir==3) return d[x][y][dir]=1;
        else return 0;
    } else if(x==1) {
        if(dir<2) return d[x][y][dir]=1;
        else return 0;
    } else if(y==1) {
        if(dir<2) return 0;
        else return d[x][y][dir]=1;
    }
    if(dir==0) d[x][y][dir] = f(x,y-1,0) + f(x,y-1,2);
    else if(dir==1) d[x][y][dir] = f(x,y-1,0);
    else if(dir==2) d[x][y][dir] = f(x-1,y,3);
    else d[x][y][dir] = f(x-1,y,1) + f(x-1,y,3);
    return d[x][y][dir]%RND;
}
int main() {
    int n, m;
    memset(d, 0, sizeof(d));
    scanf("%d %d", &n, &m);
    if(n==1 && m==1) {
        puts("1");
        return 0;
    }
    int sum=f(n,m,0) + f(n,m,3);
    printf("%d", sum%RND);
    return 0;
}
