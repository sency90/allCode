#include <cstdio>
using namespace std;
int main() {
    freopen("data21.in", "w", stdout);
    int n, m;
    scanf("%d%d",&n,&m);
    printf("%d %d\n", n,m);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int x;
            scanf("%d", &x);
            printf("%d", x);
            printf("%c", " \n"[j==m-1]);
        }
    }

    return 0;
}
