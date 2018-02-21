//teacher.cpp
#include <stdio.h>
#include <stdlib.h>

#define N 1000000
#define M 1000

int myorg[N], mydat[N], *ans;
int oN, dN, aN;

int getNumber(int select, int num);

int get_cnt(int s, int e) {
	if (s > e) return s;
	int m = (s + e) / 2;
	mydat[m] = getNumber(2, m);
	if (mydat[m] > 0) return get_cnt(m + 1, e);
	else return get_cnt(s, m - 1);
}

void dnc(int s, int e) {
	if (mydat[e] == 0) mydat[e] = getNumber(2, e);
	if (myorg[e + aN] == 0) myorg[e + aN] = getNumber(1, e + aN);
	if (mydat[e] == myorg[e + aN]) return;
	int m = (s + e) / 2;
	if (s == e) {
		ans[aN] = myorg[e + aN]; aN++;
		dnc(s, e);
	}
	else {
		dnc(s, m);
		dnc(m + 1, e);
	}
}

int card_find(int user_ans[]) {
	oN = dN = aN = 0;
	ans = user_ans;
	for (int i = 0; i < N; i++) myorg[i] = mydat[i] = 0;
	dN = get_cnt(0, N - 1);

	dnc(0, dN - 1);
	for (int i = dN + aN; i < N; i++) {
		myorg[i] = getNumber(1, i);
		if (myorg[i] == 0) break;
		ans[aN++] = myorg[i];
	}
	return aN;
}
