#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v, ans;
int main() {
    int n;
    scanf("%d", &n);
    v.resize(n);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    vector<int>::iterator it;
    for(auto &p : v) {
        it = lower_bound(ans.begin(), ans.end(), p);
        if(it == ans.end()) ans.push_back(p);
        else *it = p;
    }
    printf("%lu", ans.size());
    return 0;
}
