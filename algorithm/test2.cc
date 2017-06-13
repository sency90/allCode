#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
vector<int> g,ng,sfx,cnt,orderToIdx;
vector<int> getsfx(string &s) {
    int n=s.size();
    int lim = max(257,n+1);
    g.resize(n+1); ng.resize(n+1); sfx.resize(n); orderToIdx.resize(n+1);
    for(int i=0; i<n; i++) sfx[i]=i, g[i]=s[i];
    for(int t=1; t<n; t<<=1) {
        cnt.clear(); cnt.resize(lim,0);
        for(int i=0; i<n; i++) cnt[g[min(i+t,n)]]++;
        for(int i=1; i<lim; i++) cnt[i]+=cnt[i-1];
        for(int idx=n-1; idx>=0; idx--) orderToIdx[--cnt[g[min(idx+t,n)]]]=idx;
        //orderToIdx[x]=idx; => pair에서 second기준으로 정렬했을 때, second기준으로 x번째에 해당하는 index는 idx라는 뜻이다.

        cnt.clear(); cnt.resize(lim,0);
        for(int i=0; i<n; i++) cnt[g[i]]++;
        for(int i=1; i<lim; i++) cnt[i]+=cnt[i-1];
        for(int i=n-1; i>=0; i--) sfx[--cnt[g[orderToIdx[i]]]]=orderToIdx[i];
        //sfx[x]=idx; => pair에서 second기준으로 정렬후 first기준으로 다시 stable sort를 했을 때, 순서로 x번째에 해당하는 인덱스는 idx라는 뜻이다.

        auto cmp = [&](int i, int j) {
            if(g[i]==g[j]) return g[i+t]<g[j+t];
            else return g[i]<g[j];
        };
        ng[sfx[0]]=1;
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
    string s; cin >> s;
    vector<int> sfx = getsfx(s);
    for(int i=0; i<sfx.size(); i++) {
        printf("%d ", sfx[i]);
    }
    return 0;
}
