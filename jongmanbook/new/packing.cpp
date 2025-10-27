#include <bits/stdc++.h>
using namespace std;
struct Item{
    string name;
    int v,d; //부피, 절박도
    Item(){}
    Item(const string & name, int v, int d):name(name),v(v),d(d) {}
};
vector<Item> items;
const int INF = 0x3f3f3f3f;
int dp[1001][101];
int chk[1001][101];
int CHKVAL;
int f(int v, int x) {
    if(v<0) return -INF;
    if(x<0) return 0;
    if(chk[v][x] == CHKVAL) return dp[v][x];
    chk[v][x] = CHKVAL;
    int & ret = dp[v][x];

    return ret=max(f(v,x-1), f(v-items[x].v, x-1) + items[x].d);
}
void g(int v, int x, vector<int> & ans) {
    if(x<0) return;
    if(f(v,x) == f(v,x-1)) {
        g(v,x-1,ans);
    }
    else {
        ans.push_back(x);
        g(v-items[x].v,x-1,ans);
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    string name;
    int v,d;
    while(tc--) {
        int N,W; cin >> N >> W;
        items.clear();
        CHKVAL++;
        for(int i=0; i<N; i++) {
            cin >> name >> v >> d;
            items.emplace_back(name,v,d);
        }
        printf("%d ", f(W,N-1));

        static vector<int> ans;
        ans.clear();
        g(W,N-1,ans);
        printf("%lu\n", ans.size());
        for(int i=0; i<ans.size(); i++) {
            printf("%s\n", items[ans[i]].name.c_str());
        }
    }
    return 0;
}