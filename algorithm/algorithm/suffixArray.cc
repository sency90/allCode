//Time Complexity: O( N(lgN)^2 )
//Compatibility: c++11, c++14
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cstdio>
using namespace std;
vector<int> getsfx(const string &H) {
    int sz = H.size();
    vector<int> sfx(sz), g(sz+1), ng(sz+1);
    for(int i=0; i<sz; i++) {
        sfx[i]=i; g[i]=H[i];
    }
    g[sz]=-1;

    for(int t=1; t<sz; t<<=1) {
        auto cmp = [&](int lhs, int rhs)->bool{
            if(g[lhs]!=g[rhs]) return g[lhs]<g[rhs];
            else return g[lhs+t]<g[rhs+t];
        };
        sort(sfx.begin(), sfx.end(), cmp);

        ng[sfx[0]]=0; ng[sz]=-1;
        for(int i=1; i<sz; i++) {
            if(cmp(sfx[i-1],sfx[i])) ng[sfx[i]]=ng[sfx[i-1]]+1;
            else ng[sfx[i]]=ng[sfx[i-1]];
        }
        g = ng;
    }
    return sfx;
}
int main() {
    ios::sync_with_stdio(false);
    string H;
    cin >> H;
    vector<int> sfx = getsfx(H);
    for(auto &p : sfx) {
        printf("%d %s\n", p, H.c_str()+p);
    }
    return 0;
}
