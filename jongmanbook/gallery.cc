//이 문제는 root처리를 잘 해줘야 한다. 37번줄이 가장 중요한 부분
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
vector<vector<int> > v;
bool chk[1001], ins[1001], w[1001];
void dfs(int x) {
    chk[x]=true;
    for(int i=0; i<v[x].size(); i++) {
        int y = v[x][i];
        if(chk[y]) continue;
        dfs(y);
        if(!ins[y]) {
            if(!w[y]) w[y]=w[x]=ins[x]=true;
        } else w[x]=true;
    }
}
int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        int g, h, x, y, cnt=0;
        scanf("%d%d",&g,&h);
        v.clear();
        v.resize(g, vector<int>());
        memset(chk, false, sizeof(chk));
        memset(ins, false, sizeof(ins));
        memset(w, false, sizeof(w));
        for(int i=0; i<h; i++) {
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        for(int i=0; i<g; i++) {
            if(!chk[i] && !w[i]) dfs(i);
            if(!w[i]) ins[i]=true;
        }
        for(int i=0; i<g; i++) if(ins[i]) cnt++;
        printf("%d\n", cnt);
    }
    return 0;
}
