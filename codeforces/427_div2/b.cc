#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int k; string s;
    cin >> k >> s;
    for(int i=0; i<s.size(); i++) {
        v.push_back(s[i]-'0');
    }
    sort(v.begin(), v.end());
    int sum=0;
    for(int i=0; i<v.size(); i++) {
        sum+=v[i];
    }
    if(sum>=k) puts("0");
    else {
        for(int i=0; i<v.size(); i++) {
            sum+=(9-v[i]);
            if(sum>=k) return 0&printf("%d\n", i+1);
        }
    }
    return 0;
}
