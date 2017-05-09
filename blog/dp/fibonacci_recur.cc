#include <cstdio>
#include <cstring>
using namespace std;
long long v[101], d[101];
long long f(int x) {
    if(x==1||x==2) return 1LL; //base case
    else if(d[x]) return d[x]; //d배열 값이 0이 아니면 memo한적이 있다는 뜻.
    else return d[x]=f(x-1)+f(x-2); //memoization
}

int main() {
    int n;
    scanf("%d", &n);
    memset(d, 0, sizeof(d)); //d배열을 모두 0으로 초기화
    printf("%lld\n", f(n));
    return 0;
}
