#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
string s;
int zsum[1000001], osum[1000001];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    for(int z=1;;z++) {
        if(!(cin >> s)) return 0;
        int n; cin >> n;
        for(int i=0; i<s.size(); i++) {
            zsum[i+1]=zsum[i]+(s[i]=='0');
            osum[i+1]=osum[i]+(s[i]=='1');
        }
        printf("Case %d:\n", z);
        for(int i=0; i<n; i++) {
            int x,y;
            cin >> x >> y;
            if(x>y) swap(x,y);
            if(zsum[y+1]==zsum[x] || osum[y+1]==osum[x]) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}
