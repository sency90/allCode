#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
int chg(char x) {
    if(isupper(x)) return x-'A'+27;
    else return x-'a'+1;
}
vector<int> getsfx(const string &s) {
    int n=s.size();
    vector<int> sfx(n), g(n+1), ng(n+1);
    int cnt[54], idx[54];
    memset(idx, 0x3f, sizeof(idx));
    for(int i=0; i<n; i++) {
        sfx[i]=i;
        g[i]=chg(s[i]);
    }
    g[n]=0;
    for(int len=1; len<n; len<<=1) {
        int lim = n+len;
        for(int i=n-len,j=0; i<n; i++,j++) idx[j]=i;
        memset(cnt, 0, sizeof(cnt));
        for(int i=len; i<n; i++) cnt[g[i]]++;
        //for(int i=n; i<lim; i++) cnt[g[n]]++;
        cnt[g[n]]+=len;

        for(int i=1; i<54; i++) cnt[i]+=cnt[i-1];
        cnt[g[n]]-=len;

        //for(int i=lim; i>=n; i--) idx[--cnt[g[n]]]=i-len;
        for(int i=n-1; i>=len; i--) idx[--cnt[g[i]]]=i-len;

        memset(cnt, 0, sizeof(cnt));
        for(int i=0; i<n; i++) cnt[g[i]]++;
        for(int i=1; i<54; i++) cnt[i]+=cnt[i-1];
        for(int i=n-1; i>=0; i--) sfx[--cnt[g[idx[i]]]]=idx[i];

        auto cmp = [&](int i, int j)->bool{
            if(g[i]!=g[j]) return g[i]<g[j];
            else return g[i+len]<g[j+len];
        };
        //sort(sfx.begin(), sfx.end(), cmp);
        ng[n]=0;
        ng[sfx[0]]=1;
        for(int i=1; i<n; i++) {
            if(cmp(sfx[i-1],sfx[i])) ng[sfx[i]] = ng[sfx[i-1]]+1;
            else ng[sfx[i]] = ng[sfx[i-1]];
        }
        g = ng;
    }
    return sfx;
}
int main() {
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    vector<int> sfx = getsfx(s);
    for(auto &p : sfx) {
        printf("%d ", p);
    }
    return 0;
}
