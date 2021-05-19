#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
vector<string> v;
bool cmp(const string& lhs, const string& rhs) {
    if(lhs.size()==rhs.size()) {
        int lc=0, rc=0;
        for(int i=0; i<lhs.size(); i++) {
            if(isdigit(lhs[i])) lc+=lhs[i]-'0';
        }
        for(int i=0; i<rhs.size(); i++) {
            if(isdigit(rhs[i])) rc+=rhs[i]-'0';
        }
        if(rc==lc) return rhs > lhs;
        else return lc < rc;
    } else return lhs.size() < rhs.size();
}
char s[51];
int main() {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%s", s);
        v.push_back(s);
    }
    sort(v.begin(), v.end(), cmp);
    for(auto x:v) cout << x << '\n';
    return 0;
}
