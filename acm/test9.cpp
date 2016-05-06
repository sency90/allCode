#include <stdio.h>
#include <vector>
using namespace std;
vector<int> v;
bool cmp(const int &lhs, const int &rhs) {
    return lhs < rhs;
}
int main() {
    int n, d;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &d);
        v.push_back(d);
    }
    sort(v.begin(), v.end(), cmp);
    for(int i=0; i<n; i++) {
        printf("%d\n", v[i]);
    }
    return 0;
}
