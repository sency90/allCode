#include <stdio.h>
#include <stack>
using namespace std;
stack<pair<int, int> > s;
int main() {
    int n, h, i, t;
    long long w, mx;
    pair<int, int> prev, cur;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        mx = 0LL;
        for(i=1; i<=n; i++) {
            scanf("%d", &h);
            if(i==1) {
                s.push(make_pair(h, i));
                continue;
            }
            if(!s.empty()) {
                prev = s.top();
                while(prev.first > h) {
                    cur = prev; s.pop();
                    if(!s.empty()) prev = s.top();
                    else prev = make_pair(-1,0);
                    w = (i-1-(prev.second))*(long long)cur.first;
                    if(w > mx) mx = w;
                }
            }
            s.push(make_pair(h, i));
        }
        h = -1;
        while(!s.empty()) {
            if(s.top().first > h) {
                cur = s.top(); s.pop();
                if(!s.empty()) prev = s.top();
                else prev = make_pair(-1,0);
                w = (i-1 - (prev.second))*(long long)cur.first;
                if(w > mx) mx = w;
            }
        }
        printf("%lld\n", mx);
    }
    return 0;
}
