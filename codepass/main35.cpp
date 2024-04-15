/*** main.cpp ***/
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include<stdio.h>

#define MAX_STOCK_LEN 10
#define MAX_N 100000

#define CMD_CHANGE 100
#define CMD_GET_PRICE 200
#define CMD_GET_MOST_INCREASED 300

#define MAX_STOCK_LEN 10

extern void init(int N, char names[][MAX_STOCK_LEN + 1], int prices[]);
extern void change(char from[], char to[], int priceDiff);
extern int getPrice(char name[]);
extern int getMostIncreased(char from[], char to[]);

static char names[MAX_N][MAX_STOCK_LEN + 1];
static int prices[MAX_N];

static bool run()
{
	int N, M;
	bool ok = false;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", names[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &prices[i]);
	}

	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		if (i == 0) {
			init(N, names, prices);
			ok = true;
		}

		int command;
		scanf("%d", &command);

		char from[MAX_STOCK_LEN + 1];
		char to[MAX_STOCK_LEN + 1];
		char name[MAX_STOCK_LEN + 1];
		int ret = 0, ans = 0, priceDiff = 0;
		switch (command) {
			case CMD_CHANGE:
				scanf("%s", from);
				scanf("%s", to);
				scanf("%d", &priceDiff);
				change(from, to, priceDiff);
				break;
			case CMD_GET_PRICE:
				scanf("%s", name);
				ret = getPrice(name);
				scanf("%d", &ans);
				if (ans != ret) {
					ok = false;
				}
				break;
			case CMD_GET_MOST_INCREASED:
				scanf("%s", from);
				scanf("%s", to);

				ret = getMostIncreased(from, to);
				scanf("%d", &ans);
				if (ans != ret) {
					ok = false;
				}
				break;
		}

	}
	return ok;
}

int main() {
	setbuf(stdout, NULL);
	freopen("input35.txt", "r", stdin);

	int T, MARK;
	scanf("%d%d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++) {
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
		//return 0;
	}

	return 0;
}
