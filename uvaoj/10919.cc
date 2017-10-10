#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;
string s;
set<string> dict;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int k,m;
    while(true){
        cin >> k; if(k==0) return 0;
        cin >> m;
        dict.clear();
        for(int i=0; i<k; i++) {
            cin >> s;
            dict.insert(s);
        }
        bool hasAns=true;
        for(int i=0; i<m; i++) {
            int c,r,cnt=0;
            cin >> c >> r;
            for(int j=0; j<c; j++) {
                cin >> s;
                if(!hasAns) continue;
                if(dict.count(s)) cnt++;
            }
            if(cnt<r) hasAns=false;
        }
        if(hasAns) puts("yes");
        else puts("no");
    }
    return 0;
}
