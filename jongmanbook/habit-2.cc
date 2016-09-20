#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
vector<int> getsfx(const string &s) {
    const int n = s.size();
    const int lim = max(n+1,27);
    vector<int> sfx(n), g(n+1,0), ng(n+1,0), idx(n+1,0), cnt(lim);
    for(int i=0; i<n; i++) {
        sfx[i]=i; g[i]=s[i]-'a'+1;
    }
    g[n]=0;
    for(int t=1; t<n; t<<=1) {
        cnt.clear(); cnt.resize(lim,0);
        for(int i=0; i<n; i++) cnt[g[min(i+t,n)]]++;
        for(int i=1; i<lim; i++) cnt[i]+=cnt[i-1];
        for(int i=n-1; i>=0; i--) idx[--cnt[g[min(i+t,n)]]]=i;

        cnt.clear(); cnt.resize(lim,0);
        for(int i=0; i<n; i++) cnt[g[i]]++;
        for(int i=1; i<lim; i++) cnt[i]+=cnt[i-1];
        for(int i=n-1; i>=0; i--) sfx[--cnt[g[idx[i]]]]=idx[i];

        auto cmp=[&](int i, int j) {
            if(g[i]!=g[j]) return g[i]<g[j];
            else return g[i+t]<g[j+t];
        };

        ng[sfx[0]]=1;
        ng[n]=0;
        for(int i=1; i<n; i++) {
            if(cmp(sfx[i-1],sfx[i])) ng[sfx[i]]=ng[sfx[i-1]]+1;
            else ng[sfx[i]]=ng[sfx[i-1]];
        }
        g=ng;
    }
    return sfx;
}

int main() {
    vector<int> sfx;
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    while(tc--) {
        string s;
        int k, mx=0;
        cin >> k >> s;
        sfx = getsfx(s);
        int n=s.size();
        auto lcp = [&](int i, int j)->int{
            int cnt=0;
            for(; i<n&&j<n; i++,j++) {
                if(s[i]==s[j]) cnt++;
                else break;
            }
            return cnt;
        };
        for(int i=0; i+k<=n; i++) {
            mx = max(mx, lcp(sfx[i],sfx[i+k-1]));
        }
        printf("%d\n", mx);
    }
    return 0;
}
