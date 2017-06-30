#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    double n,a;
    cin >> n >> a;
    double x=180/n;
    int ans=0;
    double mn=180.0;
    for(int i=1; i<=n-2; i++) {
        if(mn>abs(x*i-a)) {
            mn = abs(x*i-a);
            ans=i;
        }
    }
    cout << "1 2 "<< n-ans+1;
    return 0;
}
