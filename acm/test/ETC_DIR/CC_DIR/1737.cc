#include <cmath>
#include <cstdio>
#include <map>
#define RND 1000000000000000000
using namespace std;
map<double, long long> p;
double pi = acos(-1.0);
long long f(double x) {
    if(x <= pi) return 1;
    if(p.count(x)!=0) return p[x];
    return p[x] = (f(x-1) + f(x-pi))%RND;
}
int main() {
    int n;
    scanf("%d", &n);
    printf("%lld", f(n));
    return 0;
}
