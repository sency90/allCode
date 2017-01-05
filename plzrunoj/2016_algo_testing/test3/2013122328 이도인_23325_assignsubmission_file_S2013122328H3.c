#include <cstdio>
#include <cstring>
#define MOD 1000000007
#define ll long long

ll cache[101][101][101];
ll solve(ll N, ll L, ll R) {
	if (N <= 0 || L <= 0 || R <= 0) return 0;
	ll &ret = cache[N][L][R];
	if (ret != -1) return ret;
	
	ret = (solve(N - 1, L - 1, R)+solve(N - 1, L, R - 1))%MOD;
	if(N>=2) ret=(ret+solve(N-1,L,R)*(N-2))%MOD;
	
	return ret;
}

int main() {
	memset(cache,-1,sizeof(cache));
	cache[1][1][1] = cache[2][2][1] = cache[2][1][2] = 1;	
	ll N, L, R; scanf("%lld %lld %lld",&N,&L,&R);
	printf("%lld\n",solve(N,L,R));
	return 0;
}
