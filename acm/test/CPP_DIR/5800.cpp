#include <stdio.h>
#include <queue>
using namespace std;
priority_queue<int> mxh;
int main() {
    int mx, mn, t, d, n, mxgap, p;
    scanf("%d", &t);
    for(int k=1; k<=t; k++){
        mx = 0;
        mxgap = 0;
        mn = 10000000;
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%d", &d);
            mxh.push(d);
        }
        mx = mxh.top(); mxh.pop();
        p = mx;
        while(!mxh.empty()) {
            if(mxgap < p-mxh.top()) mxgap = p-mxh.top();
            p = mxh.top();
            mxh.pop();
        }
        mn = p;
        printf("Class %d\n", k);
        printf("Max %d, Min %d, Largest gap %d\n", mx, mn, mxgap);
    }
    return 0;
}
