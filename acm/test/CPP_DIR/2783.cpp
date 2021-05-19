#include <stdio.h>
#include <queue>
using namespace std;
priority_queue<double> mxh;
int main() {
    int n, p, q;
    scanf("%d%d", &p,&q);
    mxh.push(-(double)1000/q*p);
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d%d", &p,&q);
        mxh.push(-(double)1000/q*p);
    }
    printf("%.2lf", -mxh.top());
    return 0;
}
