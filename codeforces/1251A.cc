#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
int ans[26];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    string s;
    for(int i=1; i<=n; i++) {
        cin >> s;

        int b,e=0;
        while(e<s.size()) {
            b=e++;
            for(; e<s.size(); e++) {
                if(s[b]!=s[e]) break;
            }

            if((e-b)%2 == 1) ans[s[b]-'a'] = i;
        }

        for(int j=0; j<26; j++) {
            if(ans[j] == i) putchar(j+'a');
        }
        puts("");
    }
    return 0;
}
