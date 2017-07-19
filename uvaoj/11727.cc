#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int tc; scanf("%d", &tc);
    int a[3];
    for(int z=1; z<=tc; z++) {
        for(int i=0; i<3; i++) scanf("%d", &a[i]);
        sort(a,a+3);
        printf("Case %d: %d\n", z,a[1]);
    }
    return 0;
}
