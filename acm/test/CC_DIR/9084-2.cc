#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;
int v[10001], d[10001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        for(int i=0; i<n; i++) {
            cin >> v[i];
        }
        int m; cin >> m;
        memset(d, 0, sizeof(d));
        d[0] = 1;
        for(int i=0; i<n; i++) {
            for(int j=v[i]; j<=m; j++) {
                d[j] += d[j-v[i]];
            }
        }
        cout << d[m] << "\n";
    }
    return 0;
}
