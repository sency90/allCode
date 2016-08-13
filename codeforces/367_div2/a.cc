#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
priority_queue<double> mxh;
int main() {
    double x, y, a, b, v;
    scanf("%lf %lf",&a,&b);
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%lf %lf %lf", &x,&y,&v);
        mxh.push(-sqrt((x-a)*(x-a)+(y-b)*(y-b))/v);
    }
    printf("%0.7lf", -mxh.top());
    return 0;
}
