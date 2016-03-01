#include <cstdio>
#include <cstring>
#include <limits.h>
using namespace std;
int inf = INT_MAX/2;
int n;
bool vis[10][10]; // is_visited
int val[10][10]; // cost at particular state
int weight[10][10]; // given weight

int dp(int at, int mask) {
    if ( mask ==  (1 << n) - 1 ) { // all visited
        vis[at][mask] = true;
        return val[at][mask];
    }

    if ( vis[at][mask] ) return val[at][mask];
    vis[at][mask] = true;

    int ans = inf;
    int cost;

    for ( int i = 0; i < n; i++ ) {
        if ( weight[at][i] != -1 && (mask & (1 << i)) == 0 ) {
            cost = dp (i, mask | (1 << i)) + weight [at][i];
            if ( ans > cost ) ans = cost;
        }
    }

    return val[at][mask] = ans;
}

int main () {
    memset (vis, false, sizeof (vis));
    memset (weight, -1, sizeof (weight));
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &weight[i][j]);
            if(weight[i][j] == 0) weight[i][j] = inf;
        }
    }
    printf ("Cost : %d\n", dp (0, 1));

    return 0;
}
