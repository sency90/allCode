#include <stdio.h>
#include <queue>
using namespace std;
const int MOD=20090711;
bool first;
int prv;
int next(int a, int b) {
    if(first) {
        first = false;
        return prv = 1983;
    } else return prv = ((long long)prv*a+b)%MOD;
}
int main() {
    int tc,n,a,b;
    scanf("%d",&tc);
    while(tc--) {
        first = true;
        priority_queue<int> mxh, mnh;
        int ans=0;
        scanf("%d%d%d",&n,&a,&b);
        for(int i=0; i<n; i++) {
            if(mxh.empty()) mxh.push(next(a,b));
            else {
                int nx = next(a,b);
                if(nx < mxh.top()) {
                    mnh.push(-mxh.top()); mxh.pop();
                    mxh.push(nx);
                } else mnh.push(-nx);
            }
            if(mnh.size() > mxh.size()) {
                mxh.push(-mnh.top()); mnh.pop();
            }
            ans = (ans+mxh.top())%MOD;
        }
        printf("%d\n", ans);
    }
    return 0;
}
