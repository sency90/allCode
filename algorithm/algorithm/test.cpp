#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct SuffixArrayComparator{
    const string &str;
    SuffixArrayComparator(const string &s) : str(s) { }
    //SuffixArrayComparator(const string &s) : s(s) {}
    bool operator() (const int lhs, const int rhs) const {
        return strcmp(str.c_str()+lhs, str.c_str()+rhs) < 0;
    }
};
vector<int> getSuffixArrayNaive(const string &s) {
    vector<int> ans;
    for(int i=0; i<s.size(); i++) {
        ans.push_back(i);
    }
    sort(ans.begin(), ans.end(), SuffixArrayComparator(s));
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    vector<int> ans = getSuffixArrayNaive(s);
    for(auto &p : ans) {
        cout << p << " " << s.c_str()+p << "\n";
    }
    return 0;
}

