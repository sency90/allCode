#include <stdio.h>
#include <unordered_set>
#include <algorithm>
using namespace std;
char s[200001];
long long x;
int ans=0, N;
bool check(int l) {
    x = 1LL;
    for(int i=1; i<l; i++) x*=211LL;
    long long h = 0LL;
    for(int i=1; i<=l; i++) {
        h = h*211LL + (s[i]-'a'+1LL);
    }
    unordered_set<long long> us;
    us.insert(h);
    for(int i=l+1; i<=N; i++) {
        h = (h-(s[i-l]-'a'+1)*x)*211LL + s[i]-'a'+1LL;
        if(us.count(h)) return true;
        else us.insert(h);
    }
    return false;
}
void bs(int l, int r) {
    if(l>r) return;
    int mid = (l+r)/2;
    if(check(mid)) {
        ans = max(ans, mid);
        bs(mid+1, r);
    } else bs(l, mid-1);
}
int main() {
    int l;
    scanf("%d", &l); N=l;
    scanf("%s", s+1);
    bs(1,l-1);
    printf("%d", ans);
    return 0;
}
