#include <stdio.h>
#include <algorithm>
using namespace std;
int d[101][100001], w[100001], v[100001];
//int d[100001], w[100001], v[100001];
int f(int x, int y) {
    if(x==0 || y==0) return 0;
    if(d[x][y] > 0) return d[x][y];
    if(y-w[x] >= 0) return d[x][y] = max(f(x-1,y), f(x-1, y-w[x])+v[x]);
    else return d[x][y] = f(x-1,y);
}
/*
int f(int x, int y) {
    if(x==0 || y==0) return 0;
    if(d[y] > 0) return d[y];
    for(int i=0; i<x; i++) {
        if(y-w[i] >= 0) d[y] = max({d[y], f(i,y), f(i,y-w[i])+v[i]});
        else d[y] = f(i,y);
    }
    return d[y];
}
*/
int main() {
    int n, k;
    scanf("%d%d",&n,&k);
    for(int i=1; i<=n; i++) {
        scanf("%d%d",&w[i],&v[i]);
    }
    printf("%d", f(n,k));
    return 0;
}
