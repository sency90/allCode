#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1'000;
bool mn_prime[N];
int main() {
    memset(mn_prime, true, sizeof(mn_prime));
    mn_prime[0]=mn_prime[1]=false;
    int sqrtn = sqrt(N);
    for(int i=2; i<=sqrtn; i++) {
        if(!mn_prime[i]) continue;
        for(int j=i*i; j<=N; j+=i) {
            mn_prime[j] = false;
        }
    }

    long long sum=0;
    int prime_cnt=0;
    for(int i=0; i<=N; i++) {
        if(mn_prime[i]) {
            prime_cnt++;
            sum += i;
        }
    }
    printf("prime_cnt:%d, sum:%lld, avg:%.3lf\n", prime_cnt, sum, (double)(sum)/prime_cnt);

    return 0;
}