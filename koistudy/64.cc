#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int a,b,c; scanf("%d%d%d",&a,&b,&c);
    if(!(a&1)) printf("%d\n", a);
    if(!(b&1)) printf("%d\n", b);
    if(!(c&1)) printf("%d\n", c);
    return 0;
}
