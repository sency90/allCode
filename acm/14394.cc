#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int cnt1[27], cnt2[27];
int chg(char x) {
    if(x=='*') return 27;
    else return x-'A';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string a,b;
    cin >>a>>b;
    for(int i=0; i<a.size(); i++) {
        cnt1[chg(a[i])]++;
        cnt2[chg(b[i])]++;
    }
    int cnt=0;
    for(int i=0; i<26; i++) {
        if(cnt1[i]<cnt2[i]) cnt+=cnt2[i]-cnt1[i];
    }
    printf("%d", cnt);
    return 0;
}
