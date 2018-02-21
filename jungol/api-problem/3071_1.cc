//teacher.cpp
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#define N 30000

using namespace std;

struct data {
	int num, base, state;
	bool operator<(const data &r) const {
		if (state != r.state) return state < r.state;
		return base > r.base;
	}
} a[30005], b[30005];

int Min(int x, int y) { return x < y ? x : y; }
int Max(int x, int y) { return x > y ? x : y; }

void rotate(int t[4][4])
{
	int i, j, tmp[4][4];
	for (i = 0; i < 4; i++) for (j = 0; j < 4; j++) {
		tmp[i][j] = t[j][3 - i];
	}
	for (i = 0; i < 4; i++) for (j = 0; j < 4; j++) {
		t[i][j] = tmp[i][j];
	}
}

int incode(int t[4][4])
{
	int value = 0;
	for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) {
		value = value * 3 + t[i][j];
	}
	return value;
}

void push(int t[4][4], int p)
{
	int i, j, maxh = 0, minh = 11;
	int aa[4][4], bb[4][4];
	for (i = 0; i < 4; i++) for (j = 0; j < 4; j++) {
		maxh = Max(maxh, t[i][j]);
		minh = Min(minh, t[i][j]);
	}
	a[p].num = b[p].num = p;
	a[p].base = minh, b[p].base = maxh;
	for (i = 0; i < 4; i++) for (j = 0; j < 4; j++) {
		aa[i][j] = t[i][j] - minh;
		bb[i][j] = maxh - t[i][3 - j];
	}
	a[p].state = incode(aa);
	b[p].state = incode(bb);
	for (i = 0; i < 3; i++) {
		rotate(aa), rotate(bb);
		a[p].state = Min(a[p].state, incode(aa));
		b[p].state = Min(b[p].state, incode(bb));
	}
}

void radix_sort(data a[])
{
	int cnt[7500] = { 0 }, i;
	data b[30005], c[30005];
	for (i = 0; i < N; i++) cnt[a[i].base-1]++;
	for (i = 9; i > 0; i--) cnt[i] += cnt[i + 1];
	for (i = 0; i < N; i++) b[cnt[a[i].base]++] = a[i];
	for (i = 0; i <= 10; i++) cnt[i] = 0;

	for (i = 0; i < N; i++) cnt[b[i].state % 7000 + 1]++;
	for (i = 2; i <= 7000; i++) cnt[i] += cnt[i - 1];
	for (i = 0; i < N; i++) c[cnt[b[i].state % 7000]++] = b[i];
	for (i = 0; i <= 7000; i++) cnt[i] = 0;

	for (i = 0; i < N; i++) cnt[c[i].state / 7000 + 1]++;
	for (i = 2; i <= 7000; i++) cnt[i] += cnt[i - 1];
	for (i = 0; i < N; i++) a[cnt[c[i].state / 7000]++] = c[i];
}

int makeTree(int module[][4][4])
{
	int ans = 0, i, an = 0, bn = 0, chk[30005] = { 0 };
	for (i = 0; i < N; i++) {
		push(module[i], i);
	}
	radix_sort(a);
	radix_sort(b);
	//sort(a, a + N);
	//sort(b, b + N);
	//while (a[an].state == 0) ans += a[an++].base;
	while (an < N && bn < N) {
		if (chk[a[an].num]) an++;
		else if (chk[b[bn].num]) bn++;
		else if (a[an].num == b[bn].num) an++;
		else if (a[an].state > b[bn].state) bn++;
		else if (a[an].state < b[bn].state) an++;
		else {
			ans += a[an].base + b[bn].base;
			chk[a[an++].num] = chk[b[bn++].num] = 1;
		}
	}
	return ans;
}
