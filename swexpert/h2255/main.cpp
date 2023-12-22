#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

extern int init(int N, int sCity[], int eCity[], int mCost[]);
extern void add(int sCity, int eCity, int mCost);
extern int cost(int mHub);

/////////////////////////////////////////////////////////////////////////

#define MAX_N 1400
#define CMD_INIT 1
#define CMD_ADD 2
#define CMD_COST 3

static bool run() {
	int q;
	scanf("%d", &q);

	int n;
	int sCityArr[MAX_N], eCityArr[MAX_N], mCostArr[MAX_N];
	int sCity, eCity, mCost, mHub;
	int cmd, ans, ret = 0;
	bool okay = false;

	for (int i = 0; i < q; ++i) {
		scanf("%d", &cmd);
		switch (cmd) {
			case CMD_INIT:
				okay = true;
				scanf("%d", &n);
				for (int j = 0; j < n; ++j) {
					scanf("%d %d %d", &sCityArr[j], &eCityArr[j], &mCostArr[j]);
				}
				scanf("%d", &ans);
				ret = init(n, sCityArr, eCityArr, mCostArr);
				if (ans != ret)
					okay = false;
				break;
			case CMD_ADD:
				scanf("%d %d %d", &sCity, &eCity, &mCost);
				add(sCity, eCity, mCost);
				break;
			case CMD_COST:
				scanf("%d %d", &mHub, &ans);
				ret = cost(mHub);
				//printf("ans:%d, ret(myans):%d\n", ans, ret);
				if (ans != ret)
					okay = false;
				break;
			default:
				okay = false;
				break;
		}
	}
	return okay;
}

int main() {
	setbuf(stdout, NULL);
	freopen("sample_input.txt", "r", stdin);

	int T, MARK;
	scanf("%d %d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++) {
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}

	return 0;
}
