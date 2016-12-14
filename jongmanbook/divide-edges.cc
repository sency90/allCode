#include <cstdio>
#include <vector>
#include <string>
#define TREE 0
#define FORD 1
#define BACK 2
#define CROSS 3
using namespace std;
typedef pair<int,int> pii;
const int inf = 0x3f3f3f3f;
vector<pii> ed[4];
vector<int> v[7], discov(7);
bool fin[7];
string s[4]={"Tree Edges", "Forward Edges", "Back Edges", "Cross Edges"};
int cnt=0;
void dfs(int x) {
    discov[x]=++cnt;
    for(int y: v[x]) {
        if(discov[y]) {
            if(!fin[y]) ed[BACK].push_back({x,y});
            else if(discov[y]<discov[x]) ed[CROSS].push_back({x,y});
            else ed[FORD].push_back({x,y});
        } else {
            ed[TREE].push_back({x,y});
            dfs(y);
        }
    }
    fin[x]=true;
}
void mkedge(int x, int y) { v[x].push_back(y); }
int main() {
    mkedge(0,1);
    mkedge(0,4);
    mkedge(0,5);
    mkedge(0,6);
    mkedge(1,2);
    mkedge(4,2);
    mkedge(5,3);
    mkedge(5,6);
    mkedge(2,0);
    mkedge(6,3);
    dfs(0);

    for(int i=0; i<4; i++) {
        printf("%s: ",s[i].c_str());
        for(auto &p: ed[i]) printf("(%d,%d) ",p.first, p.second);
        puts("");
    }
    return 0;
}
