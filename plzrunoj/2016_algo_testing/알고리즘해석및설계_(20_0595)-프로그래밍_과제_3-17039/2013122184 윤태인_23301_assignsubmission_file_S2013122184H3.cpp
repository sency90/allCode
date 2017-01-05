#include <cstdio>
using namespace std;
typedef long long ll;
ll mod = 1e9 + 7LL;
ll d[101][101][101];
ll function(int n, int l, int r) { //경우의수를 리턴하는것, n:전체빌딩수, l:왼쪽에서보았을때 빌딩수, r:오른쪽에서봤을때 빌딩수
	if (l == 1 && r == 1) {
		if (n == 1) return 1LL;
		else return 0LL;
	}
	else if (l < 1 || r < 1 || n < 1) return 0LL;
	if (d[n][l][r])
		return d[n][l][r];
	d[n][l][r] = (n - 2)* function(n - 1, l, r) + function(n - 1, l - 1, r) + function(n - 1, l, r - 1);
	return d[n][l][r];			// T(n) = (n-2)*T(n-1)+ "T(n-1)에서 왼쪽에 높이1짜리 추가하는경우 와 오른쪽에 추가하는경우"
};								//							d[n-1][l-1][r]							d[n-1][l][r-1]
int main() {
	int N, L, R;
	scanf_s("%d %d %d", &N, &L, &R);
	printf("%d", function(N, L, R) % mod);
	return 0;
}