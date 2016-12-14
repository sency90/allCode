#include <cstdio>
#include <vector>
using namespace std;
const int inf = 0x3f3f3f3f;
vector<int> v[10], discov(10);
vector<int> cv;
int cnt=0;
int dfs(int x) {
    discov[x]=++cnt;
    int mn = inf;
    for(int y: v[x]) {
        if(discov[y]) mn = min(mn, discov[y]);
        else {
            int subtree = dfs(y);
            if(discov[x]!=1 && subtree > discov[x]) cv.push_back(y);
            mn = min(mn, subtree);
        }
    }
    if(discov[x]==1) {
        if(v[x].size()>=2) cv.push_back(x);
    }
    return min(mn,discov[x]);
}
void mkedge(int x, int y) {
    v[x].push_back(y);
    v[y].push_back(x);
}
int main() {
    mkedge(0,1);
    mkedge(0,2);
    mkedge(0,4);
    mkedge(0,5);
    mkedge(0,6);
    mkedge(1,2);
    mkedge(4,2);
    mkedge(5,3);
    mkedge(5,6);
    dfs(0);

    printf("Cut Vertexes: ");
    for(int p: cv) printf("%d ", p);
    puts("");
    return 0;
}
