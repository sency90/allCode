#include <stdio.h>
#include <queue>
using namespace std;
priority_queue<int> mxh;
int main() {
    int ans, d;
    for(int j=0; j<2; j++) {
        ans = 0;
        for(int i=0; i<10; i++) {
            scanf("%d", &d);
            mxh.push(d);
        }
        for(int i=0; i<3; i++) {
            ans += mxh.top();
            mxh.pop();
        }
        while(!mxh.empty()) mxh.pop();
        printf("%d ", ans);
    }
    return 0;
}
