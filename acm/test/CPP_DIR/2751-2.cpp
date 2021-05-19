#include <stdio.h>
#include <set>
using namespace std;
int main() {
    set<int> s;
    int n, d; scanf("%d", &n);
    for(unsigned i = 0; i < n; i++) {
        scanf("%d", &d);
        s.insert(d);
    }
    while(!s.empty()) {
        printf("%d\n", *s.begin());
        s.erase(s.begin());
    }
    return 0;
}
