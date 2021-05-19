#include <stdio.h>
#include <vector>
using namespace std;
vector<pair<int,int> > v[21];
int main() {
    char c;
    int n,m,s,e;
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++) {
        scanf("%d%d%c",&s,&e,&c);
        v[s].push_back({e,c});
        v[e].push_Back({s,c});
    }
    q.push(s);
    while(!q.empty()) {
        s=q.front().first, c=q.front().second;

    }
    return 0;
}
