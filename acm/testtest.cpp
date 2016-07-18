#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
string s;
int main() {
    cin >> s;
    cout << s.substr(0,s.size()-1) << endl;
    cout << s.substr(0,1) << endl;
    return 0;
}
