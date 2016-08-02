#include <stdio.h>
#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;
set<int> st;
map<char, int> cnt;
string s, tmp;
int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n >> s;
    for(int i=0; i<n; i++) {
        st.insert(s[i]);
    }
    int sz = st.size();
    for(int i=0; i<sz; i++) {
        if(cnt.count(s[i]) > 0) cnt[s[i]]++;
        else cnt[s[i]]=1;
    }
    int sta=0, end=sz-1, mn=n;
    while(end<n) {
        if(cnt.size() >= sz) {
            if(mn > end-sta+1) mn=end-sta+1;
            if(cnt[s[sta]] == 1) cnt.erase(s[sta]);
            else cnt[s[sta]]--;
            sta++;
        } else if(cnt.size() < sz) {
            end++;
            if(cnt.count(s[end]) == 0) cnt[s[end]]=1;
            else cnt[s[end]]++;
        }
    }
    cout << mn << "\n";
    return 0;
}
