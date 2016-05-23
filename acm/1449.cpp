#include <stdio.h>
#include <algorithm>
using namespace std;
int v[1001];
int main() {
    int n, l, x;
    scanf("%d%d", &n,&l);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    sort(v, v+n);
    printf("%d", n-l);
    return 0;
}
