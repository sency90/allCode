#include <stdio.h>
#include <queue>
using namespace std;
priority_queue<int> mxh;
int main() {
    int t, d; scanf("%d", &t);
    while(t--) {
        scanf("%d", &d);
        if(d==0) {
            if(mxh.empty()) {
                puts("0");
                continue;
            }
            printf("%d\n", mxh.top());
            mxh.pop();
        } else mxh.push(d);
    }
    return 0;
}
