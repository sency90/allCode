#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,pii> piipii;
ll fen[2502][2502];
map<piipii,ll> mp;
int n,m;
void update(int x, int y, ll by) {
    for(int i=x; i<=n; i+=i&-i) {
        for(int j=y; j<=m; j+=j&-j) {
            fen[i][j] += by;
        }
    }
}
ll query(int x, int y) {
    ll ret = 0;
    for(int i=x; i; i-=i&-i) {
        for(int j=y; j; j-=j&-j) {
            ret += fen[i][j];
        }
    }
    return ret;
}
int main() {
    int q; scanf("%d%d%d", &n,&m,&q);
    for(int i=0; i<q; i++) {
        int t,x1,y1,x2,y2;
        scanf("%d%d%d%d%d",&t,&x1,&y1,&x2,&y2);
        if(t == 1) {
            int val = (rand()<<15) | rand();
            mp[piipii(pii(x1,y1),pii(x2,y2))] = val;
            update(x1,y1,val);
            update(x1,y2+1,-val);
            update(x2+1,y1,-val);
            update(x2+1,y2+1,val);
        } else if(t == 2) {
            int val = mp[piipii(pii(x1,y1),pii(x2,y2))];
            update(x1,y1,-val);
            update(x1,y2+1,val);
            update(x2+1,y1,val);
            update(x2+1,y2+1,-val);
        } else {
            if(query(x1,y1) == query(x2,y2)) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}
