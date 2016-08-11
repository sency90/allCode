#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
map<vector<int>, int> chk;
void bfs() {
    int n=8;
    for(int ii=1; ii<=n; ii++) {
        queue<vector<int> > q;
        vector<int> v(ii);
        for(int i=0; i<ii; i++) v[i]=i;

        int cnt=1;
        chk[v] = 0;
        q.push(v);
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                vector<int> x = q.front(); q.pop();
                for(int b=0; b<ii; b++) {
                    for(int e=b+2; e<=ii; e++) {
                        reverse(x.begin()+b, x.begin()+e);
                        if(chk.count(x) == 0) {
                            chk[x] = cnt;
                            q.push(x);
                        }
                        reverse(x.begin()+b, x.begin()+e);
                    }
                }
            }
            cnt++;
        }
    }
}
vector<pair<int,int> > v;
int main() {
    int tc, n, d;
    scanf("%d", &tc);
    bfs();
    while(tc--) {
        v.clear();
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%d", &d);
            v.push_back(make_pair(d,i));
        }
        sort(v.begin(), v.end());
        vector<int> tmp(n);
        for(int i=0; i<n; i++) {
            tmp[v[i].second] = i;
        }
        printf("%d\n", chk[tmp]);
    }
    return 0;
}
