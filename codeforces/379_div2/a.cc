#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int a,b;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i=0; i<n; i++) {
        if(s[i]=='A') a++;
        else b++;
    }
    if(a==b) puts("Friendship");
    else if(a>b) puts("Anton");
    else puts("Danik");
    return 0;
}
