#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int getLCPmax(const string &s) {
    int n = s.size();
    int lim = max(n+1, 256);
    vector<int> sfx(n), cnt, g(n+1), ng(n+1), idx(n+1);
    for(int i=0; i<n; i++) {
        sfx[i]=i;
        g[i]=s[i];
    }
    g[n]=0;
    for(int t=1; t<n; t<<=1) {
        cnt.clear(); cnt.resize(lim,0);
        for(int i=0; i<n; i++) cnt[g[min(i+t,n)]]++;
        for(int i=1; i<lim; i++) cnt[i]+=cnt[i-1];
        for(int i=n-1; i>=0; i--) idx[--cnt[g[min(i+t,n)]]] = i;

        cnt.clear(); cnt.resize(lim,0);
        for(int i=0; i<n; i++) cnt[g[i]]++;
        for(int i=1; i<lim; i++) cnt[i]+=cnt[i-1];
        for(int i=n-1; i>=0; i--) sfx[--cnt[g[idx[i]]]]=idx[i];

        auto cmp = [&](int i, int j)->bool{
            if(g[i]!=g[j]) return g[i]<g[j];
            else return g[i+t]<g[j+t];
        };
        ng[sfx[0]]=1; ng[n]=0;
        for(int i=1; i<n; i++) {
            if(cmp(sfx[i-1],sfx[i])) ng[sfx[i]]=ng[sfx[i-1]]+1;
            else ng[sfx[i]]=ng[sfx[i-1]];
        }
        g=ng;
    }
    vector<int> prevsfx(n);
    int mx = 0;
    prevsfx[sfx[0]]=-1;
    for(int i=1; i<n; i++) prevsfx[sfx[i]]=sfx[i-1];
    for(int i=0, c=0; i<n; i++) {
        if(prevsfx[i]==-1) continue;
        while(s[i+c]==s[prevsfx[i]+c]) c++;
        mx = max(mx,c);
        c = max(c-1,0);
    }
    return mx;
}
int main() {
    string s;
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin>>n;
    cin>>s;
    printf("%d\n", getLCPmax(s));
    return 0;
}
