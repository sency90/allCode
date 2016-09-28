#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> getsfx(const string &s) {
    int n = s.size(), lim = max(n+1,256);
    vector<int> sfx(n), g(n+1), ng(n+1), idx(n+1), cnt;
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

        auto cmp = [&](int i, int j){
            if(g[i]!=g[j]) return g[i]<g[j];
            else return g[i+t]<g[j+t];
        };
        ng[sfx[0]]=1; ng[n]=0;
        for(int i=1; i<n; i++) {
            if(cmp(sfx[i-1],sfx[i])) ng[sfx[i]]=ng[sfx[i-1]]+1;
            else ng[sfx[i]]=ng[sfx[i-1]];
        }
        g = ng;
    }
    return sfx;
}
vector<int> getlcp(const string &s, const vector<int> &sfx) {
    int n = s.size();
    vector<int> lcp(n), plcp(n), prevsfx(n);
    prevsfx[sfx[0]]=-1;
    for(int i=1; i<n; i++) prevsfx[sfx[i]]=sfx[i-1];
    for(int i=0,c=0; i<n; i++) {
        if(prevsfx[i]==-1) {
            plcp[i]=0;
            continue;
        } else {
            while(s[i+c]==s[prevsfx[i]+c]) c++;
            plcp[i]=c;
            c=max(c-1,0);
        }
    }
    for(int i=0; i<n; i++) lcp[i]=plcp[sfx[i]];
    return lcp;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string s;
    cin >> s;
    vector<int> sfx = getsfx(s);
    printf("sfx: ");
    for(auto &p : sfx) {
        printf("%d ", p);
    } puts("");
    vector<int> lcp = getlcp(s, sfx);
    printf("lcp: ");
    for(auto &p : lcp) {
        printf("%d ", p);
    } puts("");

    return 0;
}
