#include <stdio.h>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
char s[50], t[51];
string S, T;
bool hasAns = false;
void dfs(string s) {
    if(s.size() < S.size()) return;
    if(s[s.size()-1] == 'A') {
        string tmp = s.substr(0,s.size()-1);
        dfs(tmp);
        if(tmp==S) {
            hasAns = true;
            return;
        }
    }
    if(s[0] == 'B') {
        s=s.substr(1);
        reverse(s.begin(), s.end());
        if(s==S) {
            hasAns = true;
            return;
        }
        dfs(s);
    }
}
int main() {
    scanf("%s %s",s, t);
    S=s; T=t;
    dfs(T);
    if(hasAns) puts("1");
    else puts("0");
    return 0;
}

