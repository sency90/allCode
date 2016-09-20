#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> getsfx(const string &s) {
    int n = s.size();
    vector<int> sfx(n), g(n+1), ng(n+1);
    for(int i=0; i<n; i++) {
        sfx[i]=i;
        g[i]=s[i];
    }
    g[n]=-1;
    for(int t=1; t<n; t<<=1) {
        auto cmp = [&](int i, int j)->bool{
            if(g[i]!=g[j]) return g[i]<g[j];
            else return g[i+t]<g[j+t];
        };
        sort(sfx.begin(), sfx.end(), cmp);
        ng[sfx[0]]=0;
        ng[n]=-1;
        for(int i=1; i<n; i++) {
            if(cmp(sfx[i-1],sfx[i])) ng[sfx[i]]=ng[sfx[i-1]]+1;
            else ng[sfx[i]]=ng[sfx[i-1]];
        }
        g=ng;
    }
    return sfx;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        int k, mx=0, n;
        string s;
        cin >> k >> s;
        n=s.size();
        vector<int> sfx = getsfx(s);
        auto lcp = [&](int i, int j)->int{
            int k=0;
            for(;i<n&&j<n;i++,j++) {
                if(s[i]==s[j]) k++;
                else break;
            }
            return k;
        };
        for(int i=0; i+k<=n; i++) {
            mx = max(mx, lcp(sfx[i],sfx[i+k-1]));
        }
        printf("%d\n", mx);
    }
    return 0;
}
