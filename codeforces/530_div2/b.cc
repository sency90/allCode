#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
int main() {
    int n; scanf("%d", &n);
    int x = sqrt(n);
    if(x*x == n) printf("%d\n", x+x);
    else if(x*(x+1)<n) printf("%d\n", x+x+2);
    else printf("%d\n", x+x+1);
    return 0;
}
