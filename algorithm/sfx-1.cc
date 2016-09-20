#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
vector<int> getsfx(const string &s) {
    vector<int> sfx(s.size()), g(s.size()+1), ng(s.size()+1);
    int n=s.size();
    for(int i=0; i<n; i++) {
        sfx[i]=i; g[i]=s[i];
    }
    g[n]=-1;
    for(int t=1; t<n; t<<=1) {
        auto cmp = [&](int i, int j)->bool{
            if(g[i]!=g[j]) return g[i]<g[j];
            else return g[i+t]<g[j+t];
        };
        sort(sfx.begin(), sfx.end(), cmp);
        ng[sfx[0]]=0; //sfx[0]에는 원래 맨 앞에 와야할 접미사의 원래 인덱스를 의미한다. 물론 sorting이 아직 완벽히 다 끝나지 않았을 때에는 그 후부의 그룹이 올 수 있다.
        ng[n]=-1;
        for(int i=1; i<n; i++) {
            if(cmp(sfx[i-1],sfx[i])) ng[sfx[i]]=ng[sfx[i-1]]+1;
            else ng[sfx[i]]=ng[sfx[i-1]];
        }
        g = ng;
    }
    return sfx;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string H; cin >> H;
    vector<int> ans = getsfx(H);
    for(auto &p : ans) cout << p <<" ";
    return 0;
}
