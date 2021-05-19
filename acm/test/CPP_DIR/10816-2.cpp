#include <stdio.h>
#include <set>
using namespace std;
int main() {
    int n, m, d;
    scanf("%d", &n);
    multiset<int> ms;
    for(int i=0; i<n; i++) {
        scanf("%d", &d);
        ms.insert(d);
    }
    scanf("%d", &m);
    for(int i=0; i<m; i++) {
        scanf("%d", &d);
        printf("%lu ", ms.count(d));
    }
    return 0;
}
