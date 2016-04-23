#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
char x[1001], y[1001];
int d[1001][1001];
int f(int i, int j) {
    if(i<0 || j<0) return 0;
    if(d[i][j]>0) return d[i][j];
    if(x[i]==y[j]) {
        return d[i][j] = f(i-1,j-1)+1;
    } else return d[i][j] = max(f(i-1,j),f(i,j-1));
}
int main() {
    scanf("%s%s", x, y);
    int lx = strlen(x), ly = strlen(y);
    printf("%d", f(lx-1, ly-1));
    return 0;
}
