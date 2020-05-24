#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;
vector<int> a;
map<int,int> dic;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        a.push_back(x);
    }

    int ans = n-1;
    for(int i=0; i<n; i++) {
        dic.clear();
        bool good = true;
        for(int j=0; j<i; j++) {
            if(++dic[a[j]]>1) {
                good = false;
                break;
            }
        }

        int last = n;
        if(!good) break;
        else {
            for(int j=n-1; j>=i; j--) {
                if(++dic[a[j]]<=1) last = j;
                else break;
            }
        }
        ans = min(ans, last-i);
    }
    printf("%d", ans);
    return 0;
}
