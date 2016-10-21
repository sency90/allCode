#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
vector<vector<int> > v;
int in[1001],o[1001];
int main() {
    int tc; scanf("%d", &tc);
    while(tc--) {
        queue<int> q;
        memset(in, 0, sizeof(in));
        memset(o,0,sizeof(o));
        int k,m,p;
        scanf("%d%d%d",&k,&m,&p);
        v.clear(); v.resize(m+1, vector<int>());
        for(int i=0; i<p; i++) {
            int a,b; scanf("%d%d",&a,&b);
            v[a].push_back(b);
            in[b]++;
        }
        for(int i=1; i<=m; i++) {
            if(!in[i]) {
                q.push(i);
                o[i]=1;
            }
        }
        while(!q.empty()) {
            int x=q.front(); q.pop();
            for(int y: v[x]) {
                if(o[y]<o[x]) o[y]=o[x];
                else if(o[y]==o[x]&&in[y]==1) o[y]++;
                if(--in[y]==0) q.push(y);

            }
        }
        printf("%d %d\n",k,o[m]);
    }
    return 0;
}
