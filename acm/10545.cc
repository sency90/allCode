#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;
string key[11] = {"","","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
map<char, pair<int,int> > mp;
int ori[10];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int d;
    for(int i=2; i<=9; i++) {
        for(int j=0; j<key[i].size(); j++) {
            mp[key[i][j]] = make_pair(i,j+1);
        }
    }
    for(int i=1; i<=9; i++) {
        cin >> d;
        ori[d]=i;
    }
    d=-1;
    string s;
    cin >> s;
    for(int i=0; i<s.size(); i++) {
        if(d == ori[mp[s[i]].first]) cout << "#";
        d = ori[mp[s[i]].first];
        for(int j=0; j<mp[s[i]].second; j++) {
            cout << d;
        }
    }
    return 0;
}
