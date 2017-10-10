#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;
int x[2001], y[2001];
bool chk[2000001];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for(int i=0; i<n; i++) {
        cin >> x[i];
        chk[x[i]]=true;
    }
    for(int i=0; i<n; i++) {
        cin >> y[i];
        chk[y[i]]=true;
    }
    int cnt=0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(chk[x[i]^y[j]]) cnt++;
            assert((x[i]^y[j])<=2000000);
        }
    }
    if(cnt&1) puts("Koyomi");
    else puts("Karen");
    return 0;
}
