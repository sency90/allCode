#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    long long r,g,b;
    cin >>r>>g>>b;
    cout << min({(r+g+b)/3,r+g,g+b,b+r});
    return 0;
}
