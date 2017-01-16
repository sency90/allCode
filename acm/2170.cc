#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
vector<pii> v;
int main() {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int x,y;
        scanf("%d%d", &x,&y);
        if(x>y) swap(x,y);
        v.push_back({x,0});
        v.push_back({y,1});
    }
    sort(v.begin(), v.end());
    ll len=0LL;
    int cnt=0,s;
    for(int i=0; i<v.size(); i++) {
        if(cnt==0) s=v[i].first;
        if(!v[i].second) cnt++;
        else cnt--;
        if(cnt==0) len+=(ll)v[i].first-s;
    }
    printf("%lld", len);
    return 0;
}
