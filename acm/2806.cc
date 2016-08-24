#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
string s;
int a[1000001], b[1000001];
int main() {
    int n;
    ios::sync_with_stdio(false);
    cin >> n >> s;
    s=' '+s;
    for(int i=1; i<=n; i++) {
        if(s[i]=='A') {
            a[i] = a[i-1];
            b[i] = min(a[i-1],b[i-1])+1;
        } else {
            a[i] = min(a[i-1],b[i-1])+1;
            b[i] = b[i-1];
        }
    }
    printf("%d\n", a[n]);
    return 0;
}
