#include <stdio.h>
#include <queue>
using namespace std;
priority_queue<int> mxh, mxh2;
int main() {
    int d;
    for(int i=0; i<3; i++) {
        scanf("%d", &d);
        mxh.push(-d);
    }
    for(int i=0; i<2; i++) {
        scanf("%d", &d);
        mxh2.push(-d);
    }
    printf("%d", -mxh.top()-mxh2.top()-50);
    return 0;
}
