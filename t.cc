#include <algorithm>
#include <cstdio>
using namespace std;
int v[10];
bool cmp(int i, int j) { return i>j; }
int main() {
    int tc; scanf("%d", &tc);
    while(tc--) {
        for(int i=0; i<10; i++) scanf("%d", &v[i]);
        sort(v, v+10, cmp);
        printf("%d\n", v[2]);
    }
    return 0;
}
