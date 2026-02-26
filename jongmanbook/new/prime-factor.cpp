#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1'000'000;
int mn_prime[N+1];
void Eratosthenes() {
    for(int i=0; i<=N; i++) mn_prime[i] = i;
    mn_prime[0]=mn_prime[1]=false;
    int sqrtn = (int)(sqrt(N));
    for(int i=2; i<=sqrtn; i++) {
        if (mn_prime[i] == i) { //this case is that i is prime.
            for (int j = i * i; j <= N; j+=i) {
                if(mn_prime[j]==j) mn_prime[j] = i;
            }
        }
    }
}
void GetPrimeFactor(int x, vector<int> & pfs) {
    if(x<=0) return;
    while(x>1) {
        pfs.push_back(mn_prime[x]);
        x/=mn_prime[x];
    }
}
int main() {
    Eratosthenes();
    vector<int> prime_factors;
    int x = 126;
    GetPrimeFactor(x, prime_factors);

    printf("%d's prime factors: ", x);
    for(int i=0; i<prime_factors.size(); i++) {
        printf("%d ", prime_factors[i]);
    }
    puts("");
    
    return 0;
}