#include <cstdio>
using namespace std;
long long d[101];
long long f(int x) {
    //base case
    if(x==0) return 0;
    if(x==1) return 1;

    //memo해둔것이 있다면 바로 가져다 쓴다.
    if(d[x]) return d[x];

    //memo한 게 없으면 계산한다. 계산 후 바로 메모한다.
    return d[x]=f(x-1)+f(x-2);
}
int main() {
    int n;
    scanf("%d", &n);
    printf("%lld", f(n));
    return 0;
}
