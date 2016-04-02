#include <stdio.h>
#include <queue>
using namespace std;
priority_queue<int> mxh;
int main() {
    int t, sum, d, v[3];
    scanf("%d", &t);
    while(t--) {
        sum = 0;
        for(int i=0; i<5; i++) {
            scanf("%d", &d);
            mxh.push(d);
        }
        mxh.pop();
        for(int i=0; i<3; i++) {
            v[i] = mxh.top();
            sum += v[i];
            mxh.pop();
        }
        mxh.pop();
        if(v[0]-v[2] >= 4) puts("KIN");
        else printf("%d\n", sum);
    }
    return 0;
}
