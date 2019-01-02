#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
char s[100001], a[5]="hard";
int x[100001];
ll d[5][100001];
const ll inf = 0x3f3f3f3f3f3f3f3f;
int main() {
    int n; scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf(" %c", &s[i]);
    for(int i=1; i<=n; i++) scanf("%d", &x[i]);
    memset(d,0x3f,sizeof(d));

    for(int i=0; i<4; i++) d[i][0] = 0;
    for(int i=0; i<4; i++) {
        for(int j=1; j<=n; j++) {
            if(s[j] == a[i]) {
                if(i>=1) d[i][j] = min(d[i-1][j-1], d[i][j-1]+x[j]);
                else d[i][j] = d[i][j-1]+x[j];
            } else d[i][j]=d[i][j-1];
        }
    }
    printf("%lld\n", min({d[0][n], d[1][n], d[2][n], d[3][n]}));
    return 0;
}
