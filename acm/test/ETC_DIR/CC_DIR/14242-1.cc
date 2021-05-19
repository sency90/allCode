#include <iostream>
#include <cstring>
using namespace std;
const long long mod = 1000000007;
int min_edge[20][20];
int main() {
    int n;
    cin >> n;
    long long ans = 0;
    for (int mask=0; mask<(1<<(n-1)); mask++) {
        long long graphs = 1;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                min_edge[i][j] = 1;
            }
        }
        for (int i=0; i<n-1; i++) {
            int e = (mask & (1<<i)) ? 2 : 1;
            if (e == 2) {
                for (int u=0; u<=i; u++) {
                    for (int v=i+1; v<n; v++) {
                        min_edge[u][v] = 2;
                    }
                }
            }
        }
        for (int i=0; i<n; i++) {
            for (int j=i+2; j<n; j++) {
                if (min_edge[i][j] == 1) {
                    graphs = (graphs * 2) % mod;
                }
            }
        }
        for (int i=3; i<=n; i++) {
            graphs = (graphs * i) % mod;
        }
        ans += graphs;
    }
    cout << ans%mod << '\n';
    return 0;
}
