#include <stdio.h>
#include <queue>
using namespace std;
priority_queue<int> mxh;
int main() {
    int n, x;
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        scanf("%d",&x);
        mxh.push(x);
    }
    while(!mxh.empty()) {
        printf("%d\n", mxh.top());
        mxh.pop();
    }
    return 0;
}
