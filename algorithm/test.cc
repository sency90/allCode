#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
//sfx: suffix array
//g: group number
//ng: new group number
vector<int> sfx,g,ng;
vector<int> getsfx(string &s) {
    int n = s.size();
    sfx.resize(n); g.resize(n+1); ng.resize(n+1);
    for(int i=0; i<n; i++) sfx[i]=i, g[i]=s[i];

    g[n]=-1;
    for(int t=1; t<n; t<<=1) {
        auto cmp = [&](int i, int j) {
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

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    vector<int> sfx = getsfx(s);
    for(int i=0; i<sfx.size(); i++) {
        printf("%d ", sfx[i]);
    }
    return 0;
}
