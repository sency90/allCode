#include <bits/stdc++.h>
using namespace std;
#define N 10000000
int mn_prime[N+1];
void Eratosthenes() {
    for(int i=0; i<=N; i++) mn_prime[i] = i;
    int sqrtn = (int)(sqrt(N));
    for(int i=2; i<=sqrtn; i++) {
        if (mn_prime[i] == i) {
            for (int j = i * i; j <= N; j += i) {
                if (mn_prime[j] == j) mn_prime[j] = i;
            }
        }
    }
}
int PrimeFactorCnt(int x) {
    int ans=1, cnt=0;
    int prv_prime = -1;
    while(x>1) {
        if(prv_prime != mn_prime[x]) {
            ans*=(cnt+1);
            cnt=1;
        }
        else cnt++;
        prv_prime = mn_prime[x];
        x/=mn_prime[x];
    }
    if(cnt>0) ans*=(cnt+1);
    return ans;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    Eratosthenes();
    while(tc--) {
        int n,lo,hi;
        cin >> n >> lo >> hi;
        int ans=0;
        for(int i=lo; i<=hi; i++) {
            if(PrimeFactorCnt(i) == n) ans++;
        }
        printf("%d\n", ans);
        
    }
    return 0;
}