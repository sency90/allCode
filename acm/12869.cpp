#include <stdio.h>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
int v[3] = {1,3,9}, n;
int d[61][61][61], a[3];
int f(int *a) {


}
int f(int x, int y, int z) {
    if(x<=0&&y<=0&&z<=0) return 0;
    if(x<0||y<0||z<0) return INF;
    if(d[x][y][z] > 0) return d[x][y][z];
    int mn = INF;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(i==j) continue;
            mn = min(mn,f(x-v[i], y-v[j], z-(13-v[i]-v[j])));
        }
    }
    return d[x][y][z] = mn+1;
}
int main() {
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }
    printf("%d", f(a));
    return 0;
}
