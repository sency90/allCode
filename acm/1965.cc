#include <cstdio>
#include <vector>
using namespace std;
vector<int> v;
int main() {
    int n, d;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &d);
        auto it = lower_bound(v.begin(), v.end(), d);
        if(it == v.end()) v.push_back(d);
        else *it = d;
    }
    printf("%lu", v.size());
    return 0;
}
