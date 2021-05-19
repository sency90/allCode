#include <stdio.h>
#include <stack>
using namespace std;
stack<pair<int, int> > s;
int main() {
    int n, d, i;
    long long w, mx;
    pair<int, int> prev, cur;
    while(true) {
        scanf("%d", &n);
        if(n==0) return 0;
        mx = 0;
        for(i=1; i<=n; i++) {
            scanf("%d", &d);

            if(i==1) {
                s.push(make_pair(d, i));
                continue;
            }
            if(!s.empty()) {
                prev = s.top();
                while(prev.first > d) {
                    cur = prev; s.pop();
                    if(!s.empty()) prev = s.top();
                    else prev = make_pair(-1,0);
                    w = (i-1-(prev.second))*(long long)cur.first;
                    if(w > mx) mx = w;
                }
            }
            s.push(make_pair(d, i));
        }
        d = -1;
        while(!s.empty()) {
            if(s.top().first > d) {
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
