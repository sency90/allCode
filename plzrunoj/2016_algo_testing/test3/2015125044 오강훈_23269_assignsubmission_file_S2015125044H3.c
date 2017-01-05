#include <iostream>
using namespace std;

int main() {
    long long d[101][101][101];
    int n, l, r;
    cin >> n >> l >> r;
    d[1][1][1] = 1LL;
    for (int i=2; i<=n; i++) {
        for (int j=1; j<=l; j++) {
            for (int k=1; k<=r; k++) {
                d[i][j][k] = d[i-1][j-1][k] + d[i-1][j][k-1] + d[i-1][j][k] * (i-2); //1층자리를 끼우는식
                d[i][j][k] %= 1000000007LL;
            }
        }
    }
    cout << d[n][l][r] << '\n';
    return 0;
}
