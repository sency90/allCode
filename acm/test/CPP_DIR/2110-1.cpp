#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v;
int c, ans=0;
void bs(int l, int r) {
    if(l>r) return;
    int m = (l+r)/2, cnt=1, j=0;
    for(int i=1; i<v.size(); i++) {
        if(v[i]-v[j]>=m) {
            if(++cnt>=c) break;
            j=i;
        }
    }
    if(cnt>=c) {
        if(ans<m) ans=m;
        bs(m+1,r);
    } else bs(l,m-1);
}
int main() {
    int n, d;
    scanf("%d%d",&n,&c);
    for(int i=0; i<n; i++) {
        scanf("%d", &d);
        v.push_back(d);
    }
    sort(v.begin(),v.end());
    bs(1,v[v.size()-1]-v[0]);
    printf("%d", ans);
    return 0;
}
