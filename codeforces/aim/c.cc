#include <string>
#include <iostream>
using namespace std;
string s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    int i;
    for(i=0; s[i]=='a'; i++);
    if(i==s.size()) s[s.size()-1]='z';
    else {
        for(int j=i; j<s.size(); j++) {
            if(s[j]=='a') break;
            else s[j]--;
        }
    }
    cout << s;
    return 0;
}
