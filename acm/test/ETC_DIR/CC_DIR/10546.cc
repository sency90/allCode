#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
int res[20];
string name;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n; n=2*n-1;
    for(int i=0; i<n; i++) {
        cin >> name;
        for(int i=0; i<name.size(); i++) res[i]^=name[i];
    }
    for(int i=0; res[i]; i++) cout << (char)res[i];
    return 0;
}
