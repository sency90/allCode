#include <string>
#include <iostream>
using namespace std;
int res[20];
int main() {
    int n;
    string s;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    n = n*2-1;
    for(int i=0; i<n; i++) {
        cin >> s;
        for(int j=0; j<s.size(); j++) res[j]^=s[j];
    }
    for(int i=0; res[i]; i++) cout << (char)res[i];
    return 0;
}
