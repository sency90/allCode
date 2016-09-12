//page 669
#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> getsfx(const string &H) {
    int n = H.size();
    vector<int> sfx(n), g(n+1), ng(n+1);
    for(int i=0; i<n; i++) {
        sfx[i]=i; g[i]=H[i];
    }
    g[n]=-1;
    for(int t=1; t<n; t<<=1) {
        auto cmp = [&](int i, int j)->bool{
            if(g[i]!=g[j]) return g[i]<g[j];
            else return g[i+t]<g[j+t];
        };
        sort(sfx.begin(), sfx.end(), cmp);

        ng[sfx[0]] = 0;
        ng[n]=-1;
        for(int i=1; i<n; i++) {
            if(cmp(sfx[i-1], sfx[i])) ng[sfx[i]] = ng[sfx[i-1]]+1;
            else ng[sfx[i]] = ng[sfx[i-1]];
        }
        g = ng;
    }
    return sfx;
}
int main() {
    string H;
    cin >> H;
    int n = H.size();
    string newH = H+H;
    vector<int> ans = getsfx(newH);
    for(auto &p : ans) {
        if(p<=n) {
            cout << newH.substr(p,n) << "\n";
            return 0;
        }
    }
    return 0;
}
