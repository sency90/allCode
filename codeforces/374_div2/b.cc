#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
string s,dest;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,k;
    cin >> n>>k;
    vector<int> v(n);
    for(int i=0; i<n; i++) {
        cin>>s;
        v[i]=s.size();
    }
    cin>>dest;
    int start=0,end=0;
    sort(v.begin(), v.end());
    for(int i=0; i<n; i++) {
        if(v[i]==dest.size()) {
            start=i;
            break;
        }
    }
    for(int i=n-1; i>=0; i--) {
        if(v[i]==dest.size()) {
            end=i;
            break;
        }
    }
    printf("%d %d\n", (start/k)*5+start+1, (end/k)*5+end+1);
    return 0;
}
