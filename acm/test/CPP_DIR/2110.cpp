#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
bool canregi(vector<int> &v, int rc, int mid) {
    int cnt = 1;
    int lastRouter = v[0];
    for(auto router : v) {
        if(router - lastRouter >= mid) {
            lastRouter = router;
            cnt++;
        }
    }
    return cnt >= rc;
}
int main() {
    int n, c;
    scanf("%d %d", &n, &c);

    vector<int> v(n);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());

    int l=1, r=v[n-1], mid;
    int max = l;
    while(l <= r) {
        mid = (l+r)/2;
        if(canregi(v, c, mid)) {
            if(max < mid) max = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    printf("%d", max);
    return 0;
}
