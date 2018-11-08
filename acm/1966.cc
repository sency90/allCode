#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int,int>;
priority_queue<int> mxh;
queue<pii> q;
int main() {
    int tc; scanf("%d", &tc);
    while(tc--) {
        int n,m,x,mem; scanf("%d%d",&n,&m);
        for(int i=0; i<n; i++) {
            scanf("%d", &x);
            q.push(pii(x,i));
            mxh.push(x);
            if(i==m) mem = x;
        }
        int cnt=0;
        while(!q.empty() && !mxh.empty()) {
            pii info = q.front(); q.pop();
            if(info.first == mxh.top()) {
                mxh.pop(); cnt++;
                if(info.first==mem && info.second==m) {
                    printf("%d\n", cnt);
                    break;
                }
            } else q.push(info);
        }
        while(!q.empty()) q.pop();
        while(!mxh.empty()) mxh.pop();
    }
    return 0;
}
