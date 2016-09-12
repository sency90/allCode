#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> getsfx(const string &s) {
    int n=s.size();
    vector<int> sfx(n), g(n+1), ng(n+1), cnt, aux(256,0);
    for(int i=0; i<n; i++) {
        sfx[i]=i; g[i]=s[i];
    }
    g[n]=0;
    for(int t=1; t<n; t<<=1) {
        cnt.clear();
        cnt.resize(256, 0);
        for(int i=0; i<n; i++) cnt[g[min(i+t,n)]]++;
        for(int i=1; i<256; i++) cnt[i]+=cnt[i-1];
        for(int i=n-1; i>=0; i--) aux[--cnt[g[min(i+t,n)]]]=i;

        cnt.clear();
        cnt.resize(256, 0);
        for(int i=0; i<n; i++) cnt[g[i]]++;
        for(int i=1; i<256; i++) cnt[i]+=cnt[i-1];
        for(int i=n-1; i>=0; i--) sfx[--cnt[g[aux[i]]]]=aux[i];

        auto cmp = [&](int i, int j)->bool{
            if(g[i]!=g[j]) return g[i]<g[j];
            else return g[i+t]<g[j+t];
        };
        //sort(sfx.begin(), sfx.end(), cmp);
        ng[sfx[0]]=1;
        ng[n]=0;
        for(int i=1; i<n; i++) {
            if(cmp(sfx[i-1],sfx[i])) ng[sfx[i]]=ng[sfx[i-1]]+1;
            else ng[sfx[i]]=ng[sfx[i-1]];
        }
        g = ng;
    }
    return sfx;
}
int main() {
    string s;
    cin >> s;
    vector<int> sfx = getsfx(s);
    for(auto &p : sfx) {
        cout << p << " ";
    }
    cout << "\n";
    return 0;
}
