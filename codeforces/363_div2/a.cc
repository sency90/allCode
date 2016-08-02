#include <iostream>
#include <string>
using namespace std;
const int inf = 0x3f3f3f3f;
int main() {
    ios::sync_with_stdio(false);
    string str;
    int n,d,pd=inf,mn=inf;
    cin >> n >> str;
    for(int i=0; i<str.size(); i++) {
        cin >> d;
        if(str[i]=='R') pd = d;
        else if(pd!=inf && str[i]=='L') {
            if(mn > d-pd) mn=d-pd;
        }
    }
    if(mn==0x3f3f3f3f) cout << "-1";
    else cout << mn/2;
    return 0;
}
