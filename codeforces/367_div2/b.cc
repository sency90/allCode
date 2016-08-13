#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v;
int main() {
    int n;
    scanf("%d", &n);
    v.resize(n+1);
    v[0]=0;
    for(int i=1; i<=n; i++) {
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());
    int Q, x, l, r;
    scanf("%d", &Q);
    while(Q--) {
        scanf("%d", &x);
        l=0; r=v.size();
        for(int i=0; i<100; i++) {
            int mid = (l+r)/2;
            if(v[mid] <= x) l=mid;
            else r=mid;
        }
        printf("%d\n", l);
    }
    return 0;
}
