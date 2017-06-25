#include <iostream>
#include <algorithm>
using namespace std;
int v[101];
int main() {
    int tc; scanf("%d", &tc);
    while(tc--) {
        int n,w; scanf("%d%d", &n, &w);
        int mx=0;
        for(int i=0; i<n; i++) {
            scanf("%d", &v[i]);
        }
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                mx = max(mx, int(w/v[i])*(v[j]-v[i]));
            }
        }
        printf("%d\n", mx);
    }
    return 0;
}
