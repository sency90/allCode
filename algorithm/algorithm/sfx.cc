#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
vector<int> getsfx(const string &s) {
    int sz = max((int)s.size()+1,256);
    vector<int> sfx(s.size()), g(sz), ng(sz);
    int cnt[256], aux[256];
    int n=s.size();
    for(int i=0; i<n; i++){
        sfx[i]=i; g[i]=s[i];
    }
    g[n]=0;
    for(int t=1; t<n; t<<=1) {
        memset(cnt, 0, sizeof(cnt)); //counting sort하기 위한 변수
        for(int i=0; i<n; i++) cnt[g[min(i+t, n)]]++;
        for(int i=1; i<256; i++) cnt[i] += cnt[i-1];
        for(int i=n-1; i>=0; i--) aux[--cnt[g[min(i+t, n)]]] = i;

        memset(cnt, 0, sizeof(cnt));
        for(int i=0; i<n; i++) cnt[g[i]]++;
        for(int i=1; i<256; i++) cnt[i] += cnt[i-1];
        for(int i=n-1; i>=0; i--) sfx[--cnt[g[aux[i]]]] = aux[i];

        ng[sfx[0]] = 1;
        ng[n]=0;

        auto cmp = [&](int i, int j)->bool{
            if(g[i]!=g[j]) return g[i]<g[j];
            else return g[i+t]<g[j+t];
        };

        for(int i=1; i<n; i++){
            if(cmp(sfx[i-1],sfx[i])) ng[sfx[i]] = ng[sfx[i-1]]+1;
            else ng[sfx[i]] = ng[sfx[i-1]];
        }
        g=ng;
    }
    return sfx;
}
int main() {
    ios::sync_with_stdio(false);
    string H;
    cin >> H;
    vector<int> sfx = getsfx(H);
    for(auto &p : sfx) {
        cout << p << " ";
    }
    return 0;
}