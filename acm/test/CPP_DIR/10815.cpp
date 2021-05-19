#include <stdio.h>
#include <algorithm>
using namespace std;
int v[500000];
bool bs(int l, int r, int d) {
    if(l>r) return false;
    int m = (l+r)/2;
    if(v[m]>d) return bs(l,m-1,d);
    else if(v[m]<d) return bs(m+1,r,d);
    else return true;
}
int main() {
    int n, m, d;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    sort(v, v+n);
    int l=0, r=n-1;
    scanf("%d", &m);
    for(int i=0; i<m; i++) {
        scanf("%d", &d);
        printf("%d ", bs(l,r,d));
    }
    return 0;
}
