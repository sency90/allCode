#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int main() {
    while(true) {
        stack<int> s;
        int n,m,mx=0,ans=0;
        scanf("%d", &n);
        if(n==0) return 0;
        else scanf("%d", &m);
        for(int i=0; i<m; i++) {
            int x; scanf("%d", &x);
            mx = max(mx, x);
            if(!s.empty()) {
                if(s.top()<=x) ans+=x-s.top();
                while(!s.empty() && s.top()<=x) s.pop();
            }
            s.push(x);
        }
        ans += n-s.top();
        printf("%d\n", ans);
    }
    return 0;
}
