#include <stdio.h>
#include <queue>
using namespace std;
priority_queue<int> mxh;
int main() {
    int d, s=0;
    for(int i=0; i<5; i++) {
        scanf("%d", &d);
        s+=d;
        mxh.push(d);
    }
    for(int i=0; i<2; i++) mxh.pop();
    printf("%d\n%d", s/5, mxh.top());
    return 0;
}
