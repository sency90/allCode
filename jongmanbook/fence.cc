#include <stdio.h>
#include <algorithm>
#include <stack>
using namespace std;
stack<pair<int,int> > s;
int main() {
    int t,n,h,l,r;
    scanf("%d", &t);
    while(t--) {
        long long mx = 0LL, h2;
        scanf("%d", &n);
        for(int x=1; x<=n; x++) {
            scanf("%d", &h);
            while(!s.empty()) {
                if(s.top().second < h) break;
                else if(s.top().second == h) s.pop();
                else {
                    h2 = s.top().second; s.pop();
                    if(s.empty()) l=0;
                    else l = s.top().first;
                    mx = max(mx, h2*(x-l-1));
                }
            }
            s.push(make_pair(x,h));
        }
        r = s.top().first;
        while(!s.empty()) {
            h2=s.top().second; s.pop();
            if(s.empty()) l=0;
            else l=s.top().first;
            mx = max(mx, h2*(r-l));
        }
        printf("%lld\n", mx);
    }
    return 0;
}
