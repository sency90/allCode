#include <cstdio>
#include <algorithm>
using namespace std;
int ans[10];
int v[10] = {1,2,3,4,5,6,7,8,9,10};
void p(int n, int r) {
    // n * p(n-1, r-1);
    if(r==0) {
        for(int i=0; i<3; i++) {
            printf("%d ", ans[i]);
        }
        puts("");
        return;
    }
    for(int i=n-1; i>=0; i--) {
        swap(v[i], v[n-1]);
        ans[r-1] = v[n-1];
        p(n-1, r-1);
        swap(v[i], v[n-1]);
    }
}
int main() {
    p(4,3);
    return 0;
}
