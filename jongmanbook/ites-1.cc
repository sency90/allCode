#include <cstdio>
#include <queue>
using namespace std;
typedef long long ll;
const ll MOD = (1LL<<32)-1LL;
ll prv;
ll next() { return prv=(prv*214013LL+2531011LL)%(1LL<<32); }
int main() {
    int tc; scanf("%d", &tc);
    while(tc--) {
        queue<ll> q;
        int cnt=0,k,n;
        scanf("%d%d",&k,&n);
        ll cur=1983LL, sum=0LL;
        prv = cur;
        for(int i=0; i<n; i++) {
            cur%=10000LL; cur++;
            //printf("cur: %lld\n", cur);
            q.push(cur); sum += cur;
            while(sum>k) {
                sum-=q.front(); q.pop();
            }
            if(sum == k) cnt++;
            cur = next();
        }
        printf("%d\n", cnt);
    }
    return 0;
}

