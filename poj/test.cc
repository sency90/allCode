#include <cstdio>
#include <vector>
using namespace std;
vector<int> v;
int main() {
    int n; scanf("%d", &n);
    /*
    for(int i=0; i<n; i++) {
        int x;
        scanf("%d", &x);
        v.emplace_back(x);
    }*/
    int i=0;
    for(;(1<<i)<n; i++);
    printf("(1<<i):%d, %d\n", (1<<i), n);
    return 0;
}
