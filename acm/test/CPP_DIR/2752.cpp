#include <stdio.h>
#include <queue>
using namespace std;
priority_queue<int> mxh;
int main() {
    int d;
    for(int i=0; i<3; i++) {
        scanf("%d", &d);
        mxh.push(-d);
    }
    while(!mxh.empty()) {
        printf("%d ", -mxh.top());
        mxh.pop();
    }
    return 0;
}
