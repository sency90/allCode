#include <stdio.h>
#include <string>
#include <map>
using namespace std;
map<string, string> p;
map<string, int> ans;
string find(string& u) {
    if(u==p[u]) return u;
    else return p[u] = find(p[u]);
}
void uni(string& u, string& v) {
    u=find(u); v=find(v);
    if(u!=v) {
        ans[u] += ans[v];
        p[v] = u;
    }
}
int main() {
    int t, f;
    char x[21], y[21];
    scanf("%d", &t);
    string a, b;
    while(t--) {
        p.clear(); ans.clear();
        scanf("%d", &f);
        while(f--) {
            scanf("%s %s", x, y);
            a=x; b=y;
            if(p.count(a)==0) { p[a]=a; ans[a]=1; }
            if(p.count(b)==0) { p[b]=b; ans[b]=1; }
            uni(a,b);
            printf("%d\n", ans[p[a]]);
        }
    }
    return 0;
}
