#include <stdio.h>
#include <cstring>
#include <queue>
using namespace std;
bool ans[201];
bool chk[201][201];
int cap[3];
int from[] = {0,0,1,1,2,2};
int to[] = {1,2,0,2,0,1};
int main() {
    memset(ans, false, sizeof(ans));
    memset(chk, false, sizeof(chk));
    for(int i=0; i<3; i++) {
        scanf("%d", &cap[i]);
    }
    int sum = cap[2];
    queue<pair<int,int> > q;
    q.push(make_pair(0, 0));
    chk[0][0] = true;
    ans[cap[2]] = true;
    while(!q.empty()) {
        int cur[3];
        cur[0] = q.front().first;
        cur[1] = q.front().second;
        cur[2] = sum - cur[0] - cur[1];
        q.pop();
        for(int k=0; k<6; k++) {
            int next[3] = {cur[0], cur[1], cur[2]};
            next[to[k]] += next[from[k]];
            if(next[to[k]] >= cap[to[k]]) {
                next[from[k]] = next[to[k]]-cap[to[k]];
                next[to[k]] = cap[to[k]];
            }
            if(!chk[next[0]][next[1]]) {
                chk[next[0]][next[1]] = true;
                q.push(make_pair(next[0], next[1]));
                if(next[0] == 0) ans[next[2]] = true;
            }
        }
    }
    for(int i=0; i<=cap[2]; i++) {
        if(ans[i]) printf("%d ", i);
    }
    return 0;
}
