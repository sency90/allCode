#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v,ans;
inline int gcd(int b, int s) { return (s==0)?b:gcd(s,b%s); }
inline int ABS(int x) { return x<0?-x:x; }
int main() {
    int n; scanf("%d", &n);
    int px; scanf("%d", &px);
    for(int i=1; i<n; i++) {
        int x; scanf("%d", &x);
        v.push_back(ABS(px-x));
        px = x;
    }

    int G=v[0];
    for(int i=1; i<n-1; i++) {
        G=gcd(G,v[i]);
    }

    for(int i=2; i*i<=G; i++) {
        if(G%i==0) {
            ans.push_back(i);
            ans.push_back(G/i);
        }
    }
    if(ans.size()>=2 && ans[ans.size()-1]==ans[ans.size()-2]) ans.pop_back();
    ans.push_back(G);
    sort(ans.begin(), ans.end());
    for(int x: ans) printf("%d ", x);
    return 0;
}
