#include <stdio.h>
#include <cstring>
#include <stack>
#include <vector>
#include <queue>
using namespace std;
stack<int> st;
int inf = 1000000001;
struct Edge{
    int s,e,w;
    Edge() {
        //s=inf; e=inf; w=inf;
    }
    Edge(int ss, int ee, int ww) {
        s=ss; e=ee; w=ww;
    }
    bool operator<(const Edge &rhs) const {
        return w > rhs.w;
    }
};
priority_queue<Edge> mnh;
vector<Edge> ed[1001];
int d[1001];
bool chk[1001];
int vertex[1001];
int cnt=0;
void search(int x) {
    cnt++;
    st.push(x);
    if(vertex[x]!=-1) search(vertex[x]);
}
int main() {
    int n, m, s, e, w;
    scanf("%d %d", &n, &m);
    memset(d, 0, sizeof(d));
    memset(chk, false, sizeof(chk));
    for(int i=0; i<m; i++) {
        scanf("%d %d %d", &s, &e, &w);
        ed[s].push_back(Edge(s,e,w));
    }
    scanf("%d %d", &s, &e);
    for(int i=0; i<=n; i++) d[i] = inf;
    int x;
    vertex[s] = -1;
    chk[s] = true;
    d[s] = 0;
    x = s;
    Edge tmp(s,s,0);
    for(int i=1; i<n; i++) {
        x = tmp.e;
        for(int j=0; j<ed[x].size(); j++) {
            if(chk[ed[x][j].e]) continue;
            mnh.push(ed[x][j]);
        }
        tmp = mnh.top(); mnh.pop();
        chk[tmp.e] = true;
        if(d[tmp.e] > d[tmp.s]+tmp.w) {
            d[tmp.e] = d[tmp.s]+tmp.w;
            vertex[tmp.e] = tmp.s;
        }
    }
    search(e);
    printf("%d\n%d\n",d[e],cnt);
    while(!st.empty()) {
        printf("%d ", st.top());
        st.pop();
    }
    return 0;
}
