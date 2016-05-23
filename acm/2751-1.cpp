#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int main() {
    int n, d; scanf("%d", &n);
    while(n--) {
        scanf("%d", &d);
        v.push_back(d);
    }
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++) {
        printf("%d\n", v[i]);
    }
    return 0;
}
