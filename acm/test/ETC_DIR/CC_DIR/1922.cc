#include <stdio.h>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
queue<pair<int, int> > q;
struct Node{
    int v, w;
    Node(int _v, int _w) {
        v=_v; w=_w;
    }
    bool operator<(const Node &rhs) const {
        return w > rhs.w;
    }
};
vector<Node> v[1001];
priority_queue<Node> mnh;
bool chk[1001];
int main() {
    int n, m, x, y, e;
    memset(chk, false, sizeof(chk));
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++) {
        scanf("%d %d %d", &x, &y, &e);
        v[x].push_back(Node(y,e));
        v[y].push_back(Node(x,e));
    }

    x = 1;
    chk[1] = true;
    int cost=0;
    Node tmp = Node(0,0);
    for(int i=0; i<v[1].size(); i++) {
        mnh.push(v[1][i]);
    }
    while(!mnh.empty()) {
        x = mnh.top().v; mnh.pop();
        for(int i=0; i<v[x].size(); i++) {
            if(!chk[v[x][i].v]) {
                mnh.push(v[x][i]);
                chk[v[x][i].v] = true;
                printf("%d->%d: %d\n", x, v[x][i].v, v[x][i].w);
                cost += v[x][i].w;
            }
        }
    }
    printf("%d", cost);
    return 0;
}
