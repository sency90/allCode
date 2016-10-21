//Suffix Array: O(NlogN), LCP: O(N)    made by plzrun.
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cctype>
#define CHARNUM 256
using namespace std;
vector<int> lcp;

////get Suffix Array O(NlogN) using counting sort.
vector<int> getsfx(const string &s) {
    const int n = s.size();
    int lim = max(n+1, CHARNUM);
    vector<int> sfx(n), g(n+1,0), ng(n+1,0), cnt, idx(n+1,0);
    for(int i=0; i<n; i++) {
        sfx[i]=i;
        g[i]=s[i];
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

    //get LCP O(N)
    vector<int> prevsfx(n+1), plcp(n+1);
    lcp.clear(); lcp.resize(n);
    prevsfx[sfx[0]]=-1;
    for(int i=1; i<n; i++) prevsfx[sfx[i]]=sfx[i-1];
    for(int i=0, c=0; i<n; i++) {
        if(prevsfx[i]==-1) plcp[i]=0;
        else {
            while(s[i+c] == s[prevsfx[i] + c]) c++;
            plcp[i]=c;
            c = max(c-1,0);
        }
    }
    for(int i=0; i<n; i++) lcp[i]=plcp[sfx[i]];
    return sfx;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    vector<int> sfx = getsfx(s);

    printf("sfx: ");
    for(auto &p : sfx) printf("%d ", p);
    puts("");

    printf("lcp: ");
    for(auto &p : lcp) printf("%d ", p);
    puts("");

    return 0;
}
