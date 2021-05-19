#include <cstdio>
#include <string>
#include <map>
using namespace std;
map<string, string> p;
map<string, int> ans;
string find(string a) {
    if(p[a]==a) return a;
    else return p[a] = find(p[a]);
}
void uni(string x, string y) {
    p[find(y)] = find(x);
}
int main() {
    int t, n;
    string x, y, px, py;
    char a[21], b[21];
    scanf("%d", &t);
    while(t--) {
        p.clear();
        ans.clear();
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%s%s", a, b);
            x = a; y = b;
            if(!p.count(x)) {
                p[x] = x;
                ans[x] = 1;
            }
            if(!p.count(y)) {
                p[y] = y;
                ans[y] = 1;
            }
            px = find(x);
            py = find(y);
            if(px!=py) ans[px] += ans[py];
            uni(x, y);
            printf("%d\n", ans[px]);
        }
    }
}
