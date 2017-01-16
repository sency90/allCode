#include <cstdio>
using namespace std;
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    m--;
    for(int i=0; i<m; i++) {
        printf("%d %d\n", m, i);
    }
    for(int i=m; i<n-1; i++) {
        printf("%d %d\n", i, i+1);
    }
    return 0;
}
