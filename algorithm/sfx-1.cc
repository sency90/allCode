#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> getsfx(string &s) {
    int n = s.size();
    vector<int> sfx(n), g(n+1), ng(n+1), aux(n+1), cnt(n);
    for(int i=0; i<n; i++) {
        sfx[i]=i;
        g[i]=s[i];
    }
    g[n]=-1;
    for(int t=1; t<n; t<<=1) {
        auto cmp = [&](int i, int j)->bool{
            if(g[i]==g[j]) return g[i+t]<g[j+t];
            else return g[i]<g[j];
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
vector<int> getlcp(string &s, vector<int>& sfx) {
    int n = s.size();
    vector<int> lcp(n), plcp(n+1), prevsfx(n+1);
    prevsfx[sfx[0]]=-1;
    for(int i=1; i<n; i++) prevsfx[sfx[i]]=sfx[i-1];
    for(int i=0,c=0; i<n; i++) {
        if(prevsfx[i]==-1) plcp[i]=0;
        else {
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
    int n;
    string s;
    cin >> s;
    vector<int> sfx = getsfx(s);
    vector<int> lcp = getlcp(s, sfx);
    printf("suffix array: ");
    for(auto &p: sfx) printf("%d ", p); puts("");
    printf("longest common prefix: ");
    for(auto &p: lcp) printf("%d ", p); puts("");
    return 0;
}
