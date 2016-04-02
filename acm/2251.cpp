#include <stdio.h>
#include <cstring>
#include <queue>
using namespace std;
queue<pair<int, int> > q;
bool chk[201][201];
bool ans[201];
int from[]={0,0,1,1,2,2};
int to[]={1,2,0,2,0,1};
int main() {
    memset(chk, false, sizeof(chk));
    memset(ans, false, sizeof(ans));
    int w[3], curw[3];
    for(int i=0; i<3; i++) {
        scanf("%d", &w[i]);
    }
    int sum = w[2];
    chk[0][0] = true;
    ans[w[2]] = true;
    q.push(make_pair(0,0));
    while(!q.empty()) {
        curw[0] = q.front().first;
        curw[1] = q.front().second;
        curw[2] = sum - curw[0] - curw[1];
        q.pop();
        for(int i=0; i<6; i++) {
            int nextw[3] = {curw[0],curw[1],curw[2]};
            nextw[to[i]] += nextw[from[i]];
            nextw[from[i]] = 0;
            if(nextw[to[i]] > w[to[i]]) {
                nextw[from[i]] = nextw[to[i]]-w[to[i]];
                nextw[to[i]] = w[to[i]];
            }
            if(chk[ nextw[0] ][ nextw[1] ]) continue;
            chk[ nextw[0] ][ nextw[1] ] = true;
            if(nextw[0] == 0) ans[nextw[2]] = true;
            q.push(make_pair(nextw[0], nextw[1]));
        }
    }
    for(int i=0; i<=w[2]; i++) {
        if(ans[i]) printf("%d ", i);
    }
    return 0;
}
