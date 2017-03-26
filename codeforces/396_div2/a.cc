#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    string a,b;
    cin >> a>>b;
    if(a==b) puts("-1");
    else printf("%lu\n", max(a.size(), b.size()));
    return 0;
}
