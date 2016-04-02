#include <stdio.h>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
queue<int> q;
int p[50001], d[50001];
bool chk[50001];
vector<int> v[50001];
int main() {
    int n, m, a, b;
    memset(chk, false, sizeof(chk));
    memset(p, 0, sizeof(p));
    scanf("%d", &n);
    p[1] = 1;
    for(int i=1; i<n; i++) {
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    q.push(1);
    d[1]=0;
    chk[1] = true;
    int tmp, k=1;
    while(!q.empty()) {
        int sz = q.size();
        for(int j=0; j<sz; j++) {
            tmp = q.front(); q.pop();
            if(v[tmp].empty()) continue;
            for(int i=0; i<v[tmp].size(); i++) {
                if(chk[v[tmp][i]]) continue;
                d[v[tmp][i]] = k;
                chk[v[tmp][i]] = true;
                p[v[tmp][i]] = tmp;
                q.push(v[tmp][i]);
            }
        }k++;
    }
    scanf("%d", &m);
    for(int i=0; i<m; i++) {
        scanf("%d %d", &a, &b);
        if(d[a] < d[b]) {
            int t = a;
            a = b;
            b = t;
        }
        while(d[a]>d[b]) {
            a = p[a];
        }
        while(a!=b) {
            a = p[a];
            b = p[b];
        }
        printf("%d\n", a);
    }
    return 0;
}
