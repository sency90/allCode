#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int, int> > v;
bool chk[11];
int n,m,rcnt=0;
void pick(int c, int k) {
    if(c==0) {
        rcnt++;
        return;
    }
    if(k==m) return;
    if(!chk[v[k].first] && !chk[v[k].second]) {
        chk[v[k].first]=chk[v[k].second]=true;
        pick(c-1,k+1);
    } else pick(c,k+1);
}
int main() {
    int t,a,b;
    scanf("%d", &t);
    while(t--) {
        rcnt=0;
        v.clear();
        memset(chk, false, sizeof(chk));
        scanf("%d%d", &n,&m);
        for(int i=0; i<m; i++) {
            scanf("%d%d", &a,&b);
            if(a>b) swap(a,b);
            v.push_back({a,b});
        }
        if(n%2) puts("0");
        else pick(n/2,0);
        printf("%d\n", rcnt);
    }
    return 0;
}
