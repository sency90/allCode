#include <stdio.h>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
vector<int> v[100001];
queue<int> q;
int d[100001], parent[100001], p[100001][17];
bool chk[100001];
int main() {
    memset(chk, false, sizeof(chk));
    int n, x, y;
    scanf("%d", &n);
    for(int i=1; i<n; i++) {
        scanf("%d %d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int depth = 1;
    chk[1] = true;
    d[1] = 0;
    q.push(1);
    while(!q.empty()) {
        int sz = q.size();
        for(int i=0; i<sz; i++) {
            int t = q.front(); q.pop();
            for(int j=0; j<v[t].size(); j++) {
                if(chk[v[t][j]]) continue;
                chk[v[t][j]] = true;
                parent[v[t][j]] = t;
                q.push(v[t][j]);
                d[v[t][j]] = depth;
            }
        }depth++;
    }
    for(int i=1; i<=n; i++) {
        p[i][0] = parent[i];
    }
    for(int j=1; (1<<j)<n; j++) {
        for(int i=1; i<=n; i++) {
            if(p[i][j-1] == 0) continue;
            p[i][j] = p[ p[i][j-1] ][j-1];
        }
    }
    int m, k, s, e;
    scanf("%d", &m);
    while(m--) {
        scanf("%d %d", &s, &e);
        if(d[s] < d[e]) swap(s,e);
        while(d[s] != d[e]) {
            //어차피 k=0인 상태에서 밑의 for 반복문을 나온다는 것은
            //위의 while조차도 통과 못한다는 뜻이므로 고려해주지 않아도 된다.
            for(k=1; (1<<k)<=d[s]-d[e]; k++);
            k--;
            s=p[s][k];
        }
        if(s==e) {
            printf("%d\n", s);
            continue;
        }
        do{ for(k=0; (1<<k)<d[s]; k++) {
                if(p[s][k]==p[e][k]) break;
                s=p[s][k];
                e=p[e][k];
            }
        }while(k!=0);
        printf("%d\n", p[s][k]);
    }
    return 0;
}
