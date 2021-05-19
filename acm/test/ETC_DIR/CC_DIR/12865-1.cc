#include <stdio.h>
#include <algorithm>
using namespace std;
int d[100001],v,w,n,k;
int main() {
    scanf("%d%d",&n,&k);
    for(int i=0; i<n; i++) {
        scanf("%d%d",&w,&v);
        for(int j=k; j>=w; j--) {
            d[j] = max(d[j], d[j-w]+v);
        }
    }
    printf("%d", d[k]);
    return 0;
}
