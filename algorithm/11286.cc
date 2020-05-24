#include <cstdio>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
priority_queue<pii, vector<pii>, greater<pii>> mnh;
inline int ABS(int x) { return (x<0)?-x:x; }
int main() {
    int n; scanf("%d",&n);
    for(int i=0; i<n; i++) {
        int x; scanf("%d",&x);
        if(x!=0) mnh.emplace(ABS(x),x);
        else {
            if(mnh.empty()) puts("0");
            else {
                printf("%d\n", mnh.top().second);
                mnh.pop();
            }
        }
    }
    return 0;
}
