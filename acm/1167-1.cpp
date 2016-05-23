//bfs로는 안되는 것 같다.
//왜? 트리의 지름을 구하려면 처음 시작점부터 진행점까지의 거리가 얼마나 되는지
//알고 있어야 한다. 그런데, bfs로 하게되면... 음 생각해보니 할수는 있는데,
//이 값을 다 저장하고 있어야 된다. 완전 메모리 낭비...
//심지어 queue를 사용하는 것 떄문에 메모리 문제가 날 수도 있는데
//n크기가 좀 커진다고 하면 안되는거나 마찬가지다.
//그러니까 트리의 지름은 dfs로 구하자.
#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;
vector<pair<int,int> > v[100001];
bool chk[100001];
int mx, mx_idx;
void dfs(int x, int sum) {
    chk[x] = true;
    if(mx < sum) {
        mx = sum;
        mx_idx = x;
    }
    for(int i=0; i<v[x].size(); i++) {
        if(chk[v[x][i].first]) continue;
        chk[v[x][i].first] = true;
        dfs(v[x][i].first, sum+v[x][i].second);
    }
}
int main() {
    int n, d, x, y;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &d);
        while(true) {
            scanf("%d", &x);
            if(x==-1) break;
            scanf("%d", &y);
            v[d].push_back(make_pair(x,y));
        }
    }
    dfs(1,0);
    memset(chk, false, sizeof(chk));
    dfs(mx_idx,0);
    printf("%d", mx);
    return 0;
}
