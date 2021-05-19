#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int d[301][2];
short v[301];
int f(int x, int y) {
    if(x == 0) return d[x][y] = 0;
    if(x == 1) return d[x][y] = v[1];
    if(d[x][y] > 0) return d[x][y];

    if(y == 0) return d[x][y] = max(f(x-2,0),f(x-2,1)) + v[x];
    else {
        int temp = max(f(x-2,0),f(x-2,1));
        temp = max(temp, f(x-1,0));
        return d[x][y] = temp + v[x];
    }
}
int main() {
    memset(d, 0, sizeof(d));
    int n; scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%hd", &v[i]);
    printf("%d", max(f(n,0),f(n,1)));
    return 0;
}
