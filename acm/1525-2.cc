#include <cstdio>
#include <queue>
#include <set>
#include <stack>
using namespace std;
typedef unsigned long long ull;
ull ans = 0ULL;
set<ull> chk;
queue<pair<ull, int> > q;
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
void print(ull bit) {
    stack<ull> st;
    ull tmp = bit;
    for(int i=0; i<16; i++) {
        st.push(tmp&15ULL);
        tmp>>=4;
    }
    while(!st.empty()) {
        printf("%llu ", st.top());
        st.pop();
    }
        printf("    ");
}
void exchange(ull &s, int idxa, int idxb) {
    int dif = (idxa-idxb)*4;
    ull idx_a=(15ULL << (4*idxa)), idx_b = (15ULL << (4*idxb));
    ull a=s&idx_a, b=s&idx_b;

    s&=((~idx_a) & (~idx_b));
    if(dif>0) { a >>= dif; b <<= dif; }
    else { a <<= -dif; b >>= -dif; }
    s |= (a|b);
}
int bfs(ull start, int nine_idx) {
    int cnt=0;
    chk.insert(start);
    q.push(make_pair(start, nine_idx));
    while(!q.empty()) {
        int sz = q.size();
        for(int z=0; z<sz; z++) {
            pair<ull, int> p = q.front(); q.pop();
            ull s = p.first;
            if(s == ans) return cnt;
            int nidx = p.second;
            int x=nidx/3, y=nidx%3;
            for(int i=0; i<4; i++) {
                int nx=x+dx[i], ny=y+dy[i];
                if(nx<0||nx>=3||ny<0||ny>=3) continue;
                int exidx = nx*3+ny;
                exchange(s,exidx,nidx);
                if(chk.count(s) == 0) {
                    chk.insert(s);
                    if(s == ans) return cnt+1;
                    q.push(make_pair(s,exidx));
                }
                exchange(s,nidx,exidx);
            }
        } cnt++;
    }
    return -1;
}

int main() {
    int nine_idx, cnt=0;
    ull d, start= 0ULL;
    for(ull i=9ULL; i>=1ULL; i--) {
        ans = (ans<<4) | i;
    }
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            scanf("%llu", &d);
            if(d==0ULL) {
                d=9ULL;
                nine_idx=i*3+j;
            }
            start |= (d<<(4*cnt++));
        }
    }
    printf("%d\n", bfs(start, nine_idx));
    return 0;
}
