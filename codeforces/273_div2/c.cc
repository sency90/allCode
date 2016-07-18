#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    long long x[3];
    for(int i=0; i<3; i++) cin >> x[i];
    sort(x, x+3);
    x[1]-=x[0]; x[2]-=x[0];
    if(x[1]==0) cout << x[0];
    else if(x[1]*2<x[2]) cout << x[1]+x[0];
    else cout << (2*x[1]-x[2])/3+x[0]+(2*x[2]-x[1])/3;
    return 0;
}
