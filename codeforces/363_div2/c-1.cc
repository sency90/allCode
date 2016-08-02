#include <iostream>
#include <algorithm>
using namespace std;
int n;
int s[101], d[101][3];
bool chk[101][3];
int f(int x, int c) {
    if(x==0) return 0;
    if(chk[x][c]) return d[x][c];
    chk[x][c] = true;

    d[x][c] = f(x-1,2)+1;
    if((s[x]&1) && c!=0) d[x][c] = min(d[x][c], f(x-1,0));
    if((s[x]&2) && c!=1) d[x][c] = min(d[x][c], f(x-1,1));
    return d[x][c];
}
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> s[i];
    }
    if(s[n]&1) cout << min(f(n,1),f(n,2));
    else if(s[n]&2) cout << min(f(n,0),f(n,2));
    else cout << f(n,2);
    return 0;
}
