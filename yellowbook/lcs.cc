#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int d[1001][1001];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string s,t;
    cin >> s >> t;
    memset(d, 0, sizeof(d));
    int n=s.size(), m=t.size();
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(s[i-1]==t[j-1]) d[i][j]=max(d[i][j], d[i-1][j-1]+1);
            else d[i][j]=max(d[i-1][j], d[i][j-1]);
        }
    }
    printf("%d\n", d[n][m]);
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=m; j++) {
            printf("%d ", d[i][j]);
        } puts("");
    }
    return 0;
}
