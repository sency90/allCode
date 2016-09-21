#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cctype>
#define CHARNUM 53
using namespace std;
vector<int> lcp;
int chg(char x) {
    if(isupper(x)) return x-'A'+27;
    else return x-'a'+1;
}
vector<int> getsfx(const string &s) {
    const int n = s.size();
    lcp.clear(); lcp.resize(n);
    int lim = max(n+1, CHARNUM);
    vector<int> sfx(n), g(n+1,0), ng(n+1,0), cnt, idx(n+1,0);
    for(int i=0; i<n; i++) {
        sfx[i]=i;
        g[i]=chg(s[i]);
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

        auto cmp = [&](int i, int j)->bool{
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
    vector<int> prev_sfx_str(n+1), plcp(n+1);
    prev_sfx_str[sfx[0]]=-1;
    for(int i=1; i<n; i++) prev_sfx_str[sfx[i]]=sfx[i-1];
    for(int i=0, common=0; i<n; i++) {
        if(prev_sfx_str[i]==-1) plcp[i]=0;
        else {
            while(s[i+common] == s[prev_sfx_str[i] + common]) common++;
            plcp[i]=common;
            common = max(common-1,0);
        }
    }
    for(int i=0; i<n; i++) lcp[i]=plcp[sfx[i]];
    return sfx;
}
int main() {
    string s;
    cin >> s;
    vector<int> sfx = getsfx(s);
    printf("sfx: ");
    for(auto &p : sfx) {
        printf("%d ", p);
    }
    printf("\nlcp: ");
    for(auto &p : lcp) {
        printf("%d ", p);
    }
    puts("");
    return 0;
}

