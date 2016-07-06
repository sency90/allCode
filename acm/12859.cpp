#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
struct Info {
    int l, c;
    bool operator<(const Info& rhs) const {
        if(l == rhs.l) return c < rhs.c;
        else return l > rhs.l;
    }
};
vector<Info> v;
int main() {
    int n;
    scanf("%d", &n);
    v.resize(n);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i].l);
    }
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i].c);
    }
    sort(v, v+n);
    long long sum[301] = {v[0].l};
    for(int i=1; i<n; i++) {
        sum[i] = sum[i-1]+v[i].l;
    }
    return 0;
}
