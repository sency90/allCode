#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
queue<pair<int,int> > q;
vector<pair<int, int> > v[40001];
int d[40001];
pair<int, int> p[40001];
bool chk[40001];
int main() {
    memset(chk, false, sizeof(chk));
    int n, m, a, b, c;
    scanf("%d", &n);
    for(int i=1; i<n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
    }
    chk[a] = true;
    d[a]=0;
    p[a]=make_pair(a,0);
    q.push(p[a]);
    int depth=1;
    while(!q.empty()) {
        int sz = q.size();
        for(int j=0; j<sz; j++) {
            pair<int, int> pi = q.front(); q.pop();
            for(int k=0; k<v[pi.first].size(); k++) {
                if(chk[v[pi.first][k].first]) continue;
                chk[v[pi.first][k].first] = true;
                p[v[pi.first][k].first] = make_pair(pi.first, v[pi.first][k].second);
                d[v[pi.first][k].first] = depth;
                q.push(v[pi.first][k]);
            }
        }depth++;
    }
    scanf("%d", &m);
    for(int i=0; i<m; i++) {
        scanf("%d %d", &a, &b);
        if(d[a] < d[b]) {
            int tmp = b;
            b = a;
            a = tmp;
        }
        int sum = 0;
        while(d[a]>d[b]) {
            sum+=p[a].second;
            a=p[a].first;
        }
        while(a!=b) {
            sum += p[a].second;
            sum += p[b].second;
            a = p[a].first;
            b = p[b].first;
        }
        printf("%d\n", sum);
    }
    return 0;
}
