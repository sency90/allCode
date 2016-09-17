#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
vector<int> getsfx(const string &s) {
    int n = s.size();
    vector<int> sfx(n), g(n+1), ng(n+1);
    int cnt[27], idx[27];
    g[n]=0;
    for(int i=0; i<n; i++) {
        sfx[i]=i; g[i]=s[i]-'a'+1;
    }
    for(int t=1; t<n; t<<=1) {
        memset(cnt, 0, sizeof(cnt));
        for(int i=0; i<n; i++) cnt[g[min(i+t,n)]]++;
        for(int i=1; i<=26; i++) cnt[i]+=cnt[i-1];
        for(int i=n-1; i>=0; i--) idx[--cnt[g[min(i+t,n)]]]=i;

        memset(cnt, 0, sizeof(cnt));
        for(int i=0; i<n; i++) cnt[g[i]]++;
        for(int i=1; i<=26; i++) cnt[i]+=cnt[i-1];
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
        for(int i=1; i<n; i++) {
            int p=sfx[i], q=sfx[i-1];
            if(s[p]==s[q]) n-min(p,q);
            for(int i=max(p,q), cnt=0; i<n; i++, cnt++) {
                if(s[p]!=s[q]) {
                    mx = max(mx,cnt);
                    break;
                }
            }
        }
        printf("%d\n", mx);
    }
    return 0;
}
