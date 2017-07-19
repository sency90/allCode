#include <iostream>
#include <string>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    string s;
    for(int i=0; i<n; i++) {
        cin >> s;
        if(s=="1"||s=="4"||s=="78") puts("+");
        else {
            int k=s.size();
            if(s[k-2]=='3' && s[k-1]=='5') puts("-");
            else if(s[0]=='9' && s[k-1]=='4') puts("*");
            else puts("?");
        }
    }
    return 0;
}
