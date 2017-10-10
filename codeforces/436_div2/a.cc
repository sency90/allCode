#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
int v[101];
vector<int> ans;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n; 
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        v[x]++;
    }
    int cnt=0;
    for(int i=0; i<101; i++) {
        if(v[i]!=0) ans.push_back(i);
    }
    if(ans.size()!=2) puts("NO");
    else {
        puts("YES");
        printf("%d %d\n", ans[0], ans[1]);
    }
    return 0;
}
