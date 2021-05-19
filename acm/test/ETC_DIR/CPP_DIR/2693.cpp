#include <stdio.h>
#include <queue>
using namespace std;
priority_queue<int> mxh;
int main() {
    int t, d;
    scanf("%d", &t);
    while(t--) {
        for(int i=0; i<10; i++) {
            scanf("%d", &d);
            mxh.push(d);
        }
        for(int i=0; i<2; i++) mxh.pop();
        printf("%d\n", mxh.top());
        mxh.pop();
        while(!mxh.empty()) mxh.pop();
    }
    return 0;
}
