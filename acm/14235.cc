#include <cstdio>
#include <queue>
using namespace std;
priority_queue<int> mxh;
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int a; scanf("%d", &a);
        if(a==0) {
            if(mxh.empty()) puts("-1");
            else {
                printf("%d\n", mxh.top()); mxh.pop();
            }
        }
        for(int j=0; j<a; j++) {
            int x; scanf("%d", &x);
            mxh.push(x);
        }
    }
    return 0;
}
