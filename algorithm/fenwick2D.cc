#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
#define UPDATE 1
#define REMOVE 2
#define QUERY 3
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,pii> piipii;
ll fen[2502][2502]; //1..2500까지 사용한다면 2502까지 써줘야 제대로 작동한다.
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
        //query나 update에 들어가는 x,y값이 절대 0이 되어서는 안된다.
        if(t == UPDATE) {
            int val; scanf("%d", &val);
            mp[piipii(pii(x1,y1),pii(x2,y2))] = val;
            update(x1,y1,val);
            update(x1,y2+1,-val);
            update(x2+1,y1,-val);
            update(x2+1,y2+1,val);
        } else if(t == REMOVE) {
            int val = mp[piipii(pii(x1,y1),pii(x2,y2))];
            update(x1,y1,-val);
            update(x1,y2+1,val);
            update(x2+1,y1,val);
            update(x2+1,y2+1,-val);
        } else if(t == QUERY) {
            if(query(x1,y1) == query(x2,y2)) puts("Yes");
            else puts("No");
        } else puts("ERROR");
    }
    return 0;
}
