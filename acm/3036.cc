#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
inline int gcd(int b, int s) { return (s==0)?b:gcd(s,b%s); }
int main() {
    int n; scanf("%d", &n);
    int x; scanf("%d", &x);
    for(int i=1; i<n; i++) {
        int y; scanf("%d", &y);
        int g = gcd(x,y);
        printf("%d/%d\n", x/g, y/g);
    }
    return 0;
}
