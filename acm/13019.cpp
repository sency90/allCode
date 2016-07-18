#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int cnta[26], cntb[26];
string a, b;
int main() {
    cin >> a >> b;
    if(a.size()!=b.size()) {
        puts("-1");
        return 0;
    }
    for(int i=0; i<a.size(); i++) {
        cnta[a[i]-'A']++;
        cntb[b[i]-'A']++;
    }
    for(int i=0; i<26; i++) {
        if(cnta[i]!=cntb[i]) {
            puts("-1");
            return 0;
        }
    }

    int cnt=0, ans=0, j=b.size()-1;
    for(int i=b.size()-1; i>=0; i--) {
        while(b[i]!=a[j]) {
            cnt++;
            if(--j<0) break;
        }
        j--;
        ans+=cnt;
        cnt=0;
        if(j<0) break;
    }
    printf("%d", ans);
    return 0;
}
