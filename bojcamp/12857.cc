#include <stdio.h>
#include <map>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
int n;
char s[50005];
vector <int> v[531441];
map <pair<int, int>, int> d;
inline int F(int x) {
	if (x >= 0) return x;
	return -x;
}
int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	int G = 1;
	for (int length = 1; length <= 4; length++) {
		int val = 0;
		for (int i = 1; i <= n; i++) {
			val = val * 27 + (s[i] - 'a' + 1);
			if (i >= length) v[val].push_back(i);
			if (i - length + 1 >= 1) val -= G * (s[i - length + 1] - 'a' + 1);
		}
		G *= 27;
	}
	char a[6], b[6];
	int Q; for (scanf("%d", &Q); Q--; ) {
		scanf("%s%s", a, b);
		int na = strlen(a), nb = strlen(b);
		if (na > n || nb > n) {
			puts("-1");
			continue;
		}
		int x = 0, y = 0;
		for (int i = 0; i < na; i++) x = x * 27 + (a[i] - 'a' + 1);
		for (int i = 0; i < nb; i++) y = y * 27 + (b[i] - 'a' + 1);
		if (v[x].size() == 0 || v[y].size() == 0) {
			puts("-1");
			continue;
		}
		if (x == y) {
			printf("%d\n", na);
			continue;
		}
		if (v[x].size() > v[y].size()) {
			swap(x, y);
			swap(na, nb);
		}
		if (d.count({ x,y })) {
			printf("%d\n", d[{x, y}]);
			continue;
		}
		int vx = v[x].size(), vy = v[y].size();
		int res = n;
		int j = 0;
		for (int i = 0; i < vx; i++) {
			while (j + 1 < vy && v[y][j + 1] <= v[x][i]) j++;
			res = min(res, max(v[x][i], v[y][j]) - min(v[y][j] - nb, v[x][i] - na));
			if (j + 1 < vy) res = min(res, max(v[x][i], v[y][j + 1]) - min(v[x][i] - na, v[y][j + 1] - nb));
		}
		printf("%d\n", res);
		d[{x, y}] = res;
	}
}