#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
int main() {
    int t; scanf("%d", &t);
    while(t--) {
        int n, m; scanf("%d%d",&n,&m);
        if(n==1 || m==1) puts("YES");
        else if(n==2 && m==2) puts("YES");
        else puts("NO");
    }
    return 0;
}
