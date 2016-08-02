#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    char c;
    string s;
    for(int i=0; i<n; i++) {
        cin >> c;
        s+=c;
    }


    return 0;
}
