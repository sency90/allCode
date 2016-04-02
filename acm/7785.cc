#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
vector<string> v;
map<string, bool> m;
map<string, bool> chk;
bool cmp(const string &lhs, const string &rhs) {
    return lhs > rhs;
}
int main() {
    int t;
    string x, op;
    scanf("%d", &t);
    while(t--) {
        cin >> x;
        cin >> op;
        if(op=="enter") {
            if(!chk[x]) v.push_back(x);
            m[x] = true;
        } else if(op=="leave") {
            m[x] = false;
        }
        chk[x] = true;
    }
    sort(v.begin(), v.end(), cmp);
    for(int i=0; i<v.size(); i++) {
        if(m[v[i]]) cout << v[i] << '\n';
    }
    return 0;
}
