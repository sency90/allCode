#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
using namespace std;
string v[200001];
char v1[200001], v2[200001];
bool pos1=true, pos2=true;
map<string, set<char>> f,s;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string name1, name2;
    int n; cin >> n;
    for(int i=0; i<n; i++) {
        cin >> name1 >> name2;
        string b=name1.substr(0,2);
        v[i]=b;
        v1[i]=name1[2];
        v2[i]=name2[0];
        char c = name1[2];
        if(f[b].count(name1[2])) {
            if(!pos1) return 0&puts("NO");
            else pos1=false;
        } else f[b].insert(name1[2]);
        if(s[b].count(name2[0])) {
            if(!pos2) return 0&puts("NO");
            else pos2=false;
        } else s[b].insert(name2[0]);
    }
    if(!pos1 && !pos2) puts("NO");
    else {
        puts("YES");
        for(int i=0; i<n; i++) {
            if(pos1) {
                cout << v[i] << v1[i] << "\n";
            } else {
                cout << v[i] << v2[i] << "\n";
            }
        }
    }
    return 0;
}
