#include <stdio.h>
#include <queue>
using namespace std;
priority_queue<int> mxh;
int main() {
    int d, sum=0, v[9];
    for(int i=0; i<9; i++) {
        scanf("%d", &d);
        v[i] = d;
        sum += d;
    }
    sum-=100;
    for(int i=0; i<8; i++) {
        for(int j=i+1; j<9; j++) {
            if(sum == v[i]+v[j]) {
                for(int k=0; k<9; k++) {
                    if(k==i || k==j) continue;
                    mxh.push(-v[k]);
                }
                while(!mxh.empty()) {
                    printf("%d\n", -mxh.top());
                    mxh.pop();
                }
                return 0;
            }
        }
    }

    return 0;
}
