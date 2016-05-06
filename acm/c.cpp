#include <stdio.h>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
struct Info{
    int v, s, idx;
    bool operator<(const Info &rhs) const{
        if(v==rhs.v) return s>rhs.s;
        else return v>rhs.v;
    }
};
Info p[200000];
map<int, int> mp;
int main() {
    int n, m, d;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &d);
        mp[d]++;
    }
    scanf("%d", &m);
    for(int i=0; i<m; i++) {
        scanf("%d", &d);
        p[i].v = mp[d];
    }
    for(int i=0; i<m; i++) {
        scanf("%d", &d);
        p[i].s = mp[d];
        p[i].idx = i+1;
    }
    sort(p, p+m);
    printf("%d", p[0].idx);
    return 0;
}
