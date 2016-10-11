#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
long long d[67][67];
long long combi(int n, int r) {
    if(n==0||n==r) return 1LL;
    if(d[n][r]) return d[n][r];
    else return d[n][r]=combi(n-1,r-1)+combi(n-1,r);
}
int lucas_theorem(const char *n, const char *m, int p) { vector<int> np, mp;
    for (int i=0; n[i]; i++) {
        if (n[i]=='0' && np.empty()) continue;
        np.push_back(n[i]-'0');
    }
    for (int i=0; m[i]; i++) {
        if (m[i]=='0' && mp.empty()) continue;
        mp.push_back(m[i]-'0');
    }
    int ret = 1;
    int ni = 0, mi = 0;
    while (ni < np.size() || mi < mp.size()) {
        int nmod = 0, mmod = 0;
        for (int i=ni; i<np.size(); i++) {
            if (i+1<np.size()) np[i+1]+=(np[i]%p)*10;
            else nmod = np[i] % p;
            np[i] /= p;
        }
        for (int i=mi; i<mp.size(); i++) {
            if (i+1<mp.size()) mp[i+1]+=(mp[i] % p)*10;
            else mmod = mp[i] % p;
            mp[i]/=p;
        }
        while (ni < np.size() && np[ni] == 0) ni++;
        while (mi < mp.size() && mp[mi] == 0) mi++;
        ret = (ret * combi(nmod, mmod)) % p;
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string n,r;
    int mod;
    cin>>n>>r>>mod;
    printf("%d\n",lucas_theorem(n.c_str(),r.c_str(),mod));
    return 0;
}
