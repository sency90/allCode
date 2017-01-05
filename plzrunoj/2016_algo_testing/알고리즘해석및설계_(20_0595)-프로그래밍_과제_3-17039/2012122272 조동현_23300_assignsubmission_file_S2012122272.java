#include <cstdio>
#include <memory.h>
using namespace std;
typedef long long ll;
ll d[101][101][101];
ll div = 1000000007;

ll f(int x, int l, int r) {   
   d[1][1][1] = 1;

   for (int i = 2; i <= x; i++) {
      for (int j = 1; j <= l; j++) {
         for (int k = 1; k <= r; k++) {
            d[i][j][k] = (i - 2) * d[i - 1][j][k] + d[i - 1][j - 1][k] + d[i - 1][j][k - 1];
            d[i][j][k] %= div;
         }
      }
   }
   return d[x][l][r];
}
int main() {
   int n, l, r;
   memset(d, 0, sizeof(d));
   scanf("%d%d%d", &n, &l, &r);
   printf("%lld\n", f(n, l, r));
   return 0;
}