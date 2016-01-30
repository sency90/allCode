#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define NEWINT(x) int x; cin >> x

int main() {
    NEWINT(n);

    vector<string> s;
    string temp;
    for(int i=0; i<n; i++) {
        cin >> temp;
        s.push_back(temp);
    }

    string res;
    bool everIn = false;

    if(n > 1) {
        for(int j=0; j<s[0].size(); j++) {
            for(int i=0; i<n-1; i++) {
                if(s[i].at(j) == s[i+1].at(j)) {
                    everIn = true;
                    continue;
                }
                everIn = false;
                break;
            }
            if(!everIn) res += "?";
            else res += s[0].at(j);
        }
        cout << res << endl;
    }
    else {
        cout << s[0] <<endl;
    }

    return 0;
}
