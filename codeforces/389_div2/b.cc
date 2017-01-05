#include <cstring>
#include <string>
#include <iostream>
#include <map>
#include <set>
using namespace std;
map<char, char> mp;
set<char> eq;
bool chk[27];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string a, b;
    cin >> a >> b;
    int n = a.size();
    for(int i=0; i<n; i++) {
        if(a[i]==b[i]) {
            if(mp.count(a[i])||mp.count(b[i])) return 0&printf("-1");
            eq.insert(a[i]);
            eq.insert(b[i]);
            continue;
        } else {
            if(eq.count(a[i])||eq.count(b[i])) return 0&printf("-1");
            if(mp.count(a[i])&&mp.count(b[i])) {
                if(mp[a[i]]!=b[i]) return 0&printf("-1");
            } else if(mp.count(a[i]) || mp.count(b[i])) {
                return 0&printf("-1");
            } else {
                mp[a[i]]=b[i];
                mp[b[i]]=a[i];
            }
        }
    }
    printf("%lu\n", mp.size()/2);
    for(auto &p: mp) {
        if(chk[p.first-'a']&&chk[p.second-'a']) {
        } else {
            printf("%c %c\n",p.first,p.second);
            chk[p.first-'a']=chk[p.second-'a']=true;
        }
    }
    return 0;
}
