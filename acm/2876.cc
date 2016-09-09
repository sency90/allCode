#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int cnt[2][100001];
vector<pair<int,int> > v;
int mx,mxi,len;
int main() {
    int n,x,y;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d%d",&x,&y);
        v.push_back(make_pair(x,y));
    }
    for(int i=1; i<=5; i++) {
        for(auto &p : v) {
            if(p.first==i || p.second==i) len++;
            else len=0;
            if(mx < len) {
                mx = len;
                mxi = i;
            }
        }
    }
    printf("%d %d", mx, mxi);
    return 0;
}
