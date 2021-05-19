#include <stdio.h>
#include <queue>
#include <string.h>
#include <vector>
#include <functional>
using namespace std;
queue<pair<int, int> > q;
priority_queue<int, vector<int>, greater<int> > minheap;
int v[26][26], n;
bool chk[26][26];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int bfs(int x, int y) {
    int X, Y, cnt = 1;
    if(!chk[x][y]) chk[x][y] = true;
    for(int i=0; i<4; i++) {
        X = x+dx[i];
        Y = y+dy[i];
        if(X < 1 || X > n || Y < 1 || Y > n) continue;
        if(chk[X][Y]) continue;
        if(v[X][Y] == 0) continue;
        chk[X][Y] = true;
        q.push(make_pair(X, Y));
    }
    pair<int, int> t;
    while(!q.empty()) {
        t = q.front();
        q.pop();
        cnt += bfs(t.first, t.second);
    }
    return cnt;
}
int main() {
    memset(v, 0, sizeof(v));
    memset(chk, false, sizeof(chk));
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            scanf("%1d", &v[i][j]);
        }
    }

    int totalCnt = 0;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if((!chk[i][j]) && v[i][j]) {
                totalCnt++;
                minheap.push(bfs(i,j));
            }
        }
    }
    printf("%d\n", totalCnt);
    if(minheap.empty()) printf("0\n");
    while(!minheap.empty()) {
        printf("%d\n", minheap.top());
        minheap.pop();
    }
    return 0;
}
