#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
vector<int> v;
int cnt2[26], cnt[26];
bool check(string &s, int div) {
    memset(cnt, 0, sizeof(cnt));
    for(int i=0; i<div; i++) {
        cnt[s[i]-'a']++;
    }
    for(int i=div; i<s.size(); i+=div) {
        memset(cnt2, 0, sizeof(cnt2));
        for(int j=i; j<i+div; j++) {
            cnt2[s[j]-'a']++;
        }
        for(int k=0; k<26; k++) {
            if(cnt[k]!=cnt2[k]) return false;
        }
    }
    return true;

}
int main() {
    string s;
    cin >> s;
    if(s.size()%2==1) {
        for(int i=0; i<s.size(); i++) {
            if(s[i]!=s[0]) {
                putchar(s[0]);
                return 0;
            }
        }
        puts("-1");
        return 0;
    }

    long long n = s.size(), t;
    for(long long i=1LL; i*i<=n; i++) {
        if(n%i == 0) {
            v.push_back(i);
            t=n/i;
            if(t!=i && t!=n) v.push_back(t);
        }
    }
    sort(v.begin(), v.end());

    for(int i=0; i<v.size(); i++) {
        if(check(s,v[i])) {
            cout << s.substr(0,v[i]);
            return 0;
        }
    }
    puts("-1");
    return 0;
}
