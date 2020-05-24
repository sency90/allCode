#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--) {
        int a,b; cin >> a >> b;
        int mem=0;
        for(int i=0,k=0; i<9; i++) {
            k=k*10+9;
            if(k<=b) mem = i+1;
            else break;
        }
        printf("%lld\n", (long long)(mem)*a);
    }
    return 0;
}
