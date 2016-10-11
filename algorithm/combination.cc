#include <cstdio>
using namespace std;
//const long long ERROR=-0x3f3f3f3fLL;
long long d[67][67]; //d[n][r] => (n<=66)
long long combi(long long n, long long r) {
    //if(n<r) return ERROR;
    if(r==0||n==r) return 1LL;
    if(d[n][r]) return d[n][r];
    else return d[n][r]=combi(n-1,r)+combi(n-1,r-1);
}
int main() {
    long long n,r;
    scanf("%lld%lld",&n,&r);
    printf("%lld",combi(n,r));
    return 0;
}
