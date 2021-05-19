#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
constexpr int M = 'z'-'a'+2; //27
string s;
int g[2100][2];
int idx[1002], nidx[1002], cnt[1002];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> s;

    int n = s.size(), z=0;
    int lim = max(n+1, M);

    auto cmp = [&](int i, int j, int t, int z) {
        if(g[i][z]==g[j][z]) return g[i+t][z]<g[j+t][z];
        else return g[i][z]<g[j][z];
    };

    for(int i=0; i<n; i++) {
        g[i][z]=s[i]-'a'+1;
        nidx[i] = i;
    }
    for(int t=1; t<n; t<<=1) {
        memset(cnt,0,sizeof(cnt));
        for(int i=0; i<n; i++) cnt[g[min(i+t,n)][z]]++;
        for(int i=1; i<lim; i++) cnt[i]+=cnt[i-1];
        for(int i=n-1; i>=0; i--) idx[--cnt[g[min(i+t,n)][z]]] = i;

        memset(cnt,0,sizeof(cnt));
        for(int i=0; i<n; i++) cnt[g[i][z]]++;
        for(int i=1; i<lim; i++) cnt[i]+=cnt[i-1];
        for(int i=n-1; i>=0; i--) nidx[--cnt[g[idx[i]][z]]] = idx[i];

        g[nidx[0]][z^1] = 1;
        for(int i=1; i<n; i++) {
            if(cmp(nidx[i-1], nidx[i],t,z)) g[nidx[i]][z^1] = g[nidx[i-1]][z^1]+1;
            else g[nidx[i]][z^1]=g[nidx[i-1]][z^1];
        }
        z^=1;
    }

    for(int i=0; i<n; i++) {
        printf("%s\n", s.substr(nidx[i]).c_str());
    }

    return 0;
}
