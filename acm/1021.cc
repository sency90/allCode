#include <cstdio>
#include <cstring>
#include <algorithm>
#include <deque>
using namespace std;
deque<int> dq;
int main() {
    int n,m; scanf("%d%d", &n,&m);
    for(int i=1; i<=n; i++) dq.push_back(i);
    int cnt=0,x;
    for(int i=0; i<m; i++) {
        scanf("%d", &x);
        int idx=1;
        for(int j=0; j<dq.size(); j++, idx++) {
            if(dq[j] == x) break;
        }
        int l=idx-1, r=dq.size()-idx+1;
        if(l<r) {
            while(!dq.empty()) {
                if(x == dq.front()) {
                    dq.pop_front();
                    break;
                }
                dq.push_back(dq.front()); dq.pop_front();
                cnt++;
            }
        } else {
            while(!dq.empty()) {
                if(x == dq.front()) {
                    dq.pop_front();
                    break;
                }
                dq.push_front(dq.back()); dq.pop_back();
                cnt++;
            }
        }
    }
    printf("%d", cnt);
    return 0;
}
