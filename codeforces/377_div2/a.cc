#include <cstdio>
using namespace std;
int main() {
    long long n,m;
    scanf("%lld%lld",&n,&m);
    for(long long i=1LL; ;i++) {
        long long tmp=i*n%10LL;
        if(tmp==m||tmp==0LL) {
            printf("%lld",i);
            return 0;
        }
    }
    return 0;
}
