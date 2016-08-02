#include <stdio.h>
#include <stack>
using namespace std;
struct Info{
    int x,h;
    Info(){} Info(int x, int h) : x(x), h(h) {}
};
stack<Info> s;
int main() {
    int n, mx=0, h;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &h);
        int r=i-1, l;
        while(!s.empty()) {
            if(s.top().h < h) break;
            else {
                int h2 = s.top().h; s.pop();
                if(s.empty()) l=0;
                else l=s.top().x;
                mx = max(mx,(r-l)*h2);
            }
        }
        s.push(Info(i,h));
    }
    int r = s.top().x, l;
    while(!s.empty()) {
        h = s.top().h; s.pop();
        if(s.empty()) l=0;
        else l=s.top().x;
        mx = max(mx, (r-l)*h);
    }
    printf("%d", mx);
    return 0;
}
