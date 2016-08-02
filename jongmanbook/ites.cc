#include <stdio.h>
#include <queue>
using namespace std;
typedef unsigned long long uint64;
const uint64 MOD = (1ULL<<32);
int main() {
    int t;
    uint64 n, k;
    scanf("%d", &t);
    while(t--) {
        queue<uint64> q;
        scanf("%llu%llu", &k,&n);
        int cnt=0;
        uint64 a=1983ULL, sum=0ULL, x=1984ULL;
        q.push(x); sum+=x;
        if(sum >= k) {
            if(sum == k) cnt++;
            sum -= q.front(); q.pop();
        }
        for(int i=1; i<n; i++) {
            a=(a*214013ULL+2531011ULL)%MOD;
            x=a%10000ULL+1ULL;
            q.push(x); sum+=x;
            while(sum >= k) {
                if(sum == k) cnt++;
                sum -= q.front(); q.pop();
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
