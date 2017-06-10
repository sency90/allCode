#include <iostream>
#include <cstring>
using namespace std;
#define RND 100000
int d[500001];
int main() {
    //freopen("input.txt", "r", stdin);
    int tc; scanf("%d", &tc);
    while (tc--) {
        memset(d, 0, sizeof(d));
        int n; scanf("%d", &n);
        d[0] = 1;
        for (int i = 1; i <= n; i++) {
            if (i % 2) d[i] = d[i - 1];
            else d[i] = (d[i / 2] + d[i - 1]) % RND;
        }
        printf("%d\n", d[n]);
    }
}
