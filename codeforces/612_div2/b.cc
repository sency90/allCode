#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
string s[1501];
int dic[30];
char undic[8];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,k; cin >> n >> k;
    for(int i=0; i<n; i++) {
        cin >> s[i];
    }

    sort(s, s+n);

    dic['S'-'A']=1;
    dic['E'-'A']=2;
    dic['T'-'A']=4;

    undic[1]='S';
    undic[2]='E';
    undic[4]='T';

    int ret=0;
    string ans;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            ans="";
            for(int u=0; u<k; u++) {
                if(s[i][u] == s[j][u]) ans += s[i][u];
                else {
                    int bit = dic[s[i][u]-'A'] | dic[s[j][u]-'A'];
                    ans += undic[(bit^7)&7];
                }
            }
            ret += upper_bound(s+j+1, s+n, ans) - lower_bound(s+j+1, s+n, ans);
        }
    }
    printf("%d", ret);
    return 0;
}
