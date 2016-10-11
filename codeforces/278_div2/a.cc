#include <cstdio>
#include <algorithm>
using namespace std;
bool has8(int x) {
    if(x<0) x=-x;
    while(x!=0) {
        if(x%10 == 8) return true;
        x/=10;
    }
    return false;
}
int main() {
    int n,ori,inc;
    scanf("%d", &n);
    ori=n;
    while(true) {
        n++;
        if(has8(n)) break;
    }
    inc=n-ori;
    printf("%d", inc);
    return 0;
}
