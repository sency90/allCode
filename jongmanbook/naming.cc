#include <stdio.h>
#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
stack<int> s;
int main() {
    ios::sync_with_stdio(false);
    string a, b;
    cin >> a >> b;
    a += b;
    int n = a.size();
    int begin=1, matched=0, x=0;
    s.push(n);
    vector<int> pi(n,0);
    while(begin + matched <= n) {
        if(a[matched] == a[begin+matched]) {
            matched++;
            pi[begin+matched-1] = matched;
            if(matched == n-begin) {
                s.push(n-begin);
                x = n-begin;
                break;
            }
        } else {
            if(matched == 0) begin++;
            else {
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    while(x > 0) {
        if(pi[x-1] == 0) break;
        s.push(pi[x-1]);
        x = pi[x-1];
    }
    while(!s.empty()) {
        cout << s.top() << " "; s.pop();
    }
    return 0;
}
