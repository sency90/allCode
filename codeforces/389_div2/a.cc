#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
int main() {
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    printf("%d %d %c",(k-1)/(2*m)+1, ((k-1)%(2*m))/2+1, "LR"[((k-1)%(2*m))%2]);
    return 0;
}
