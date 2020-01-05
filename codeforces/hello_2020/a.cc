#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
vector<string> v,g,p;
int gcd(int b, int s) {
    if(s==0) return b;
    else return gcd(s,b%s);
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m; cin >> n >> m;
    string s;
    for(int i=0; i<n ;i++) {
        cin >> s;
        v.push_back(s);
    }
    for(int i=0; i<m; i++) {
        cin >> s;
        g.push_back(s);
    }

    int lim = gcd(m,n);
    lim = m/lim * n;
    for(int i=0; i<lim; i++) {
        p.push_back(v[i%n]+g[i%m]);
    }

    int k;
    cin >> k;
    for(int i=0; i<k; i++) {
        int x;
        cin >> x;
        x = (x-1)%lim;
        printf("%s\n", p[x].c_str());
    }
    return 0;
}
