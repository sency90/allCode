#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int getAns(const string &s) {
    int n = s.size();
    int lim = max(n+1, 256);
    vector<int> sfx(n+1), g(n+1), ng(n+1), idx(n+1), cnt;
    for(int i=0; i<n; i++) {
        sfx[i]=i;
        g[i]=s[i];
    }
    g[n]=0;
    for(int t=1; t<n; t<<=1) {
        cnt.clear(); cnt.resize(lim);
        for(int i=0; i<n; i++) cnt[g[min(i+t,n)]]++;
        for(int i=1; i<lim; i++) cnt[i]+=cnt[i-1];
        for(int i=n-1; i>=0; i--) idx[--cnt[g[min(i+t,n)]]]=i;

        cnt.clear(); cnt.resize(lim);
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

    vector<int> prevsfx(n), plcp(n), lcp(n+1);
    prevsfx[sfx[0]]=-1;
    for(int i=1; i<n; i++) prevsfx[sfx[i]]=sfx[i-1];
    for(int i=0, c=0; i<n; i++) {
        if(prevsfx[i]==-1) plcp[i]=0;
        else {
            while(s[i+c]==s[prevsfx[i]+c]) c++;
            plcp[i]=c;
            c = max(c-1,0);
        }
    }
    for(int i=0; i<n; i++) lcp[i]=plcp[sfx[i]];
    lcp[n]=0;

    int ret=0;
    bool dec=false, inc=false;
    for(int i=1; i<=n; i++) {
        if(lcp[i]>lcp[i-1]) {
            if(dec) {
                dec=false;
                ret-=lcp[i-1];
            }
            inc = true;
        } else {
            if(inc) {
                inc=false;
                ret+=lcp[i-1];
            }
            dec = true;
        }
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    for(int i=0; i<n; i++) {
        cin >> s;
        printf("%d\n", getAns(s));
    }
    return 0;
}
