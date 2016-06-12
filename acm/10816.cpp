#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int v[500000], ans=0;
struct Info{
    int x, c;
    Info(int xx, int cnt) {
        x=xx; c=cnt;
    }
    bool operator<(const Info& rhs) const {
        return x < rhs.x;
    }
};
vector<Info> a;
int bs(int l, int r, int d) {
    if(l>r) return 0;
    int m = (l+r)/2;
    if(a[m].x > d) return bs(l,m-1,d);
    else if(a[m].x < d) return bs(m+1,r,d);
    else return a[m].c;
}
int main() {
    int n,m,d;
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    sort(v, v+n);
    int last=v[0], cnt=1;
    for(int i=1; i<n; i++) {
        if(v[i]==last) {
            cnt++;
        } else {
            a.push_back(Info(last,cnt));
            last=v[i];
            cnt=1;
        }
    }
    a.push_back(Info(last,cnt));
    scanf("%d",&m);
    for(int i=0; i<m; i++) {
        scanf("%d",&d);
        printf("%d ", bs(0,a.size()-1,d));
    }
    return 0;
}
