#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
void next_perm(string &s, int n) {
    if(n==1) return;

    int o=-1;
    for(int i=s.size()-1; i>=1; i--) {
        if(s[i-1]<s[i]) {
            o=i;
            break;
        }
    }
    if(o==-1) return;
    else {
        auto it = upper_bound(s.rbegin(),s.rbegin()+(s.size()-o),s[o-1]);
        swap(*it, s[o-1]);
        reverse(s.begin()+o,s.end());
        cout << s << "\n";
        next_perm(s,n-1);
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string s,t; int n;
    cin >> s >> n;
    t=s;
    next_perm(s,n);
    cout << s << "\n\n";
    cout << "start next_permutation\n";
    for(int i=0; i<n; i++) {
        cout << t <<"\n";
        next_permutation(t.begin(), t.end());
    }
    return 0;
}
