#include <iostream>
#include <string>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string a="one",s;
    int n; cin >> n;
    for(int i=0; i<n; i++) {
        cin >> s;
        if(s.size()==5) puts("3");
        else {
            int cnt=0;
            for(int j=0; j<s.size(); j++) {
                if(s[j]==a[j]) cnt++;
            }
            if(cnt>=2) puts("1");
            else puts("2");
        }
    }
    return 0;
}

