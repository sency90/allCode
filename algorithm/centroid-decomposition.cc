#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <cassert>
using namespace std;
typedef pair<int,int> pii;
const int inf = 0x3f3f3f3f;
vector<pii> v[200005];
int vcnt[200005], need_mnvcnt[1000005], need_chk[1000005];
bool viscr[200005];
int C,N,K,ans=inf;
struct Queue{
    int head, tail;
    vector<pii> que;
    Queue():head(0),tail(0),que(200005){};
    void push(pii x) { que[tail++]=x; }
    pii front() { return que[head]; }
    void pop() { head++; }
    bool empty() { return head>=tail; }
    void init() {head=tail=0;}
}q;

void vcounting(int x, int px) {
    vcnt[x]=1;
    for(auto &p: v[x]) {
        int y=p.first;
        if(viscr[y] || y==px) continue;
        vcounting(y,x);
        vcnt[x]+=vcnt[y];
    }
}
int getcr(int x, int px, int half_tsz) {
    for(auto &p: v[x]) {
        int y=p.first;
        if(viscr[y] || y==px) continue;
        if(vcnt[y]>half_tsz) return getcr(y,x,half_tsz);
    }
    return x;
}
void solve(int r) {
    vcounting(r,r);
    int cr = getcr(r,r,vcnt[r]>>1);
    need_chk[0]=++C; need_mnvcnt[0]=0;
    viscr[cr]=true;
    for(auto &p: v[cr]) {
        int y=p.first, w=p.second;
        if(viscr[y] || w>K) continue;
        q.init();

        function<void(int,int,int,int)> dfs = [&](int x, int px, int len, int cnt) {
            q.push({len,cnt});
            for(auto &q: v[x]) {
                int y=q.first, w=q.second;
                if(viscr[y] || y==px || len+w>K) continue;
                dfs(y,x,len+w,cnt+1);
            }
        };
        dfs(y,cr,w,1);
        for(int i=0; i<q.tail; i++) {
            int len=q.que[i].first, cnt=q.que[i].second;
            if(need_chk[K-len]==C) ans=min(ans, need_mnvcnt[K-len]+cnt);
        }
        while(!q.empty()) {
            pii p=q.front(); q.pop();
            int len=p.first, cnt=p.second;
            if(need_chk[len]!=C || need_mnvcnt[len] > cnt) {
                need_chk[len]=C;
                need_mnvcnt[len]=cnt;
            }
        }
    }

    for(auto &p: v[cr]) {
        int y=p.first;
        if(viscr[y]) continue;
        solve(y);
    }
}
int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    N=n; K=k;
    for(int i=1; i<n; i++) {
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        x++; y++;
        v[x].push_back({y,w});
        v[y].push_back({x,w});
    }
    solve(1);
    printf("%d\n", (ans>=inf)?-1:ans);
    return 0;
}
