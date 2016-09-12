#include <bitset>
#include <iostream>
#include <string>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    bitset<64> bit(s);
    cout << bit << "\n";
    return 0;
}
