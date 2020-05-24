#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int l,r; scanf("%d%d",&l,&r);
        printf("%d %d\n", l, 2*l);
    }
    return 0;
}
