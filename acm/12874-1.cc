#include <iostream>
#include <cstring>
using namespace std;
long long d[101][101];
const long long mod = 1000000007;
long long go(string &s, int last, int open) {
    long long &ans = d[last][open];
    if (ans != -1) return ans;
    ans = 0;
    if (open == 0) {
        ans = 1;
    }
    int n = s.length();
    int next_open = last + 1;
    while (next_open < n && s[next_open] != '(') {
        next_open += 1;
    }
    if (next_open < n) {
        ans += go(s, next_open, open + 1);
    }
    if (open > 0) {
        int next_close = last + 1;
        while (next_close < n && s[next_close] != ')') {
            next_close += 1;
        }
        if (next_close < n) {
            ans += go(s, next_close, open-1);
        }
    }
    ans %= mod;
    return ans;
}
int main() {
    string s;
    cin >> s;
    s = " " + s;
    memset(d,-1,sizeof(d));
    cout << go(s, 0, 0) - 1 << '\n';
    return 0;
}
