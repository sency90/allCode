#include <cstdio>
using namespace std;
int d[300];
int main() {
    int n; scanf("%d", &n);
    d[1]=d[2]=1;
    for(int i=3; i<=n; i++) {
        d[i] = d[i-1]+d[i-2];
    }
    printf("%d", d[n]);
    return 0;
}
