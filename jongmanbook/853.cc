#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
vector<vector<int>> v;
vector<pii> tree,ford,back,cross;
vector<int> chk;
vector<bool> fin;
int cnt=0;
void dfs(int x) {
    chk[x]=++cnt;
    for(int y: v[x]) {
        if(!chk[y]) {
            tree.push_back({x,y});
            dfs(y);
        } else {
            if(chk[y]>chk[x]) ford.push_back({x,y});
            else {
                if(fin[y]) cross.push_back({x,y});
                else back.push_back({x,y});
            }
        }
    }
    fin[x]=true;
}
int main() {
    int n=7;
    v.resize(n, vector<int>());
    chk.resize(n,0);
    fin.resize(n,0);
    v[0].push_back(1);
    v[0].push_back(4);
    v[0].push_back(5);
    v[0].push_back(6);
    v[5].push_back(3);
    v[5].push_back(6);
    v[6].push_back(3);
    v[4].push_back(2);
    v[1].push_back(2);
    v[2].push_back(0);
    dfs(0);

    puts("Tree Edge");
    for(auto &p: tree) {
        printf("%d -> %d\n",p.first,p.second);
    }

    puts("Forward Edge");
    for(auto &p: ford) {
        printf("%d -> %d\n",p.first,p.second);
    }

    puts("Backward Edge");
    for(auto &p: back) {
        printf("%d -> %d\n",p.first,p.second);
    }

    puts("Cross Edge");
    for(auto &p: cross) {
        printf("%d -> %d\n",p.first,p.second);
    }
    return 0;
}
