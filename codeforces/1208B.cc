#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v,g;
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int x; scanf("%d", &x);
        if(!v.empty() && v.back() >= x) {
            auto it = lower_bound(v.begin(), v.end(), x);
            *it = x;
        }
        else v.push_back(x);

        if(!g.empty() && g.back() >= -x) {
            auto it = lower_bound(g.begin(), g.end(), -x);
            *it = -x;
        }
        else g.push_back(-x);
    }

    printf("%d\n", min(n-(int)v.size(), n-(int)g.size()));
    return 0;
}
