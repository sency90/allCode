#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;
queue<int> q;
stack<int> st;
bool chk[200001];
int p[200001];
int main() {
    memset(p, -1, sizeof(p));
    int n,k;scanf("%d%d",&n,&k);
    q.push(n);
    chk[n] = true;
    int cnt = 0;
    while(!q.empty()) {
        int sz = q.size();
        for(int z=0; z<sz; z++) {
            int x = q.front(); q.pop();
            if(x==k) {
                printf("%d\n", cnt);
                for(int i=k; i!=-1; i=p[i]) st.push(i);
                while(!st.empty()) {
                    printf("%d ", st.top());
                    st.pop();
                }
                return 0;
            }
            if(x-1>=0 && !chk[x-1]) {
                q.push(x-1);
                chk[x-1] = true;
                p[x-1] = x;
            }
            if(x+1<=200000 && !chk[x+1]) {
                q.push(x+1);
                chk[x+1] = true;
                p[x+1] = x;
            }
            if(x*2<=200000 && !chk[x*2]) {
                q.push(2*x);
                chk[2*x] = true;
                p[2*x] = x;
            }
        }
        cnt++;
    }
    return 0;
}
