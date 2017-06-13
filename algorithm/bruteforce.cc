//suffix array: bruteforce O(N^2lgN)
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<string, int> psi;
vector<int> getsfx(string &s) {
    int n=s.size();
    vector<psi> v;
    for(int i=0; i<n; i++) {
        v.emplace_back(psi(s.substr(i),i));
    }
    sort(v.begin(), v.end());
    vector<int> ans;
    for(int i=0; i<n; i++) {
        ans.emplace_back(v[i].second);
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    vector<int> sfx = getsfx(s);
    for(auto x: sfx) cout << x << " ";
    return 0;
}
