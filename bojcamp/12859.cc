#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

typedef long long ll;

int n, N, bit[310];
const ll INF = 987654321234567LL;
ll L[310], C[310], dp[310][1 << 10];

void init() {
  for (int i = 0 ; i < 310 ; ++i) {
    for (int j = 0 ; j < (1 << 10) ; ++j) {
      dp[i][j] = 2 * INF;
    }
  }
}

vector<ll> getFactors(ll num) {
  vector<ll> ret;
  for (ll i = 2 ; i * i <= num ; ++i) {
    if (num % i == 0) {
      ret.push_back(i);
      while (num % i == 0) {
        num /= i;
      }
    }
  }
  if (num != 1) {
    ret.push_back(num);
  }
  return ret;
}

ll func(int pos, int state) {
  if (pos == n) {
    if (state == (1 << N) - 1) {
      return 0;
    }
    return INF;
  }
  
  ll& ret = dp[pos][state];
  if (ret != INF * 2) {
    return ret;
  }
  ret = min(func(pos + 1, state), func(pos + 1, state | bit[pos]) + C[pos]);
  return ret;
}

int main() {
  scanf("%d", &n);
  for (int i = 0 ; i < n ; ++i) {
    scanf("%lld", &L[i]);
  }
  for (int i = 0 ; i < n ; ++i) {
    scanf("%lld", &C[i]);
  }
  
  ll sol = INF;
  for (int i = 0 ; i < n ; ++i) {
    vector<ll> factors = getFactors(L[i]);
    for (int j = 0 ; j < n ; ++j) {
      bit[j] = 0;
      for (int k = 0 ; k < (int)factors.size() ; ++k) {
        ll f = factors[k];
        if (L[j] % f != 0) {
          bit[j] |= (1 << k);
        }
      }
    }
    init();
    N = (int)factors.size();
    sol = min(sol, func(0, 0) + C[i]);
  }
  printf("%lld\n", sol >= INF ? -1 : sol);
}