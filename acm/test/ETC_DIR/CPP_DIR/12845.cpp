#include <stdio.h>
#include <vector>
using namespace std;
vector<pair<int,int> > ed[501];
int main() {
    int n, m, s, e, w;
    scnaf("%d %d",&n,&m);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    for(int i=0; i<m; i++) {
        scanf("%d%d%d", &s, &e, &w);
        ed[s].push_back(make_pair(e,w));
        ed[e].push_back(make_pair(s,w));
    }

    return 0;
}
