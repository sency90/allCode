// *** main.cpp ***
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define MAXN    (50)
#define MAXD    (11)

struct Result
{
	int r, c;
};

extern void init(int N, int D, int mForest[MAXN][MAXN], int K);
extern Result findCriminal();

static const int dr[4] = { 0, -1, 0, 1 };
static const int dc[4] = { -1,  0, 1, 0 };

static unsigned long long mSeed;
static int pseudo_rand()
{
	mSeed = (mSeed * 1103515245ULL + 12345) % 2147483647;
	return (int)((mSeed >> 16) & 65535);
}

static int mForest[MAXN][MAXN];
static bool visited[MAXN][MAXN];

static int N, D;

static int curR, curC, dir;
static int callCount, callLimit;

int useDetector(int P[MAXD][MAXD])
{
	int nr, nc;

	if (callCount > callLimit) return 0;
	callCount++;

	while (true)
	{
		nr = (curR + dr[dir] + N) % N;
		nc = (curC + dc[dir] + N) % N;

		if (!visited[nr][nc])
			break;

		dir = (dir + 1) % 4;
	}

	curR = nr;
	curC = nc;

	visited[curR][curC] = true;

	for (int r1 = curR - D / 2, r2 = 0; r2 < D; ++r1, ++r2)
		for (int c1 = curC - D / 2, c2 = 0; c2 < D; ++c1, ++c2)
			P[r2][c2] = mForest[(r1 + N) % N][(c1 + N) % N];

	return 1;
}

static bool run()
{
	static int mForest_t[MAXN][MAXN];

	int K, S;
	scanf("%d %d %d %d", &N, &D, &K, &S);

	mSeed = (unsigned long long)S;

	for (int r = 0; r < N; ++r)
		for (int c = 0; c < N; ++c)
			mForest_t[r][c] = mForest[r][c] = pseudo_rand() % (D * D) == 0 ? 2 : 1;

	init(N, D, mForest_t, K);

	bool okay = true;

	for (int i = 0; i < K; ++i)
	{
		scanf("%d", &callLimit);

		callCount = 0;

		curR = pseudo_rand() % N;
		curC = pseudo_rand() % N;
		dir = pseudo_rand() % 4;
		//printf("curR:%d, curC:%d, dir:%d\n", curR, curC, dir);

		for (int r = 0; r < N; ++r)
			for (int c = 0; c < N; ++c)
				visited[r][c] = false;

		visited[curR][curC] = true;

		Result res = findCriminal();
		if (callCount > callLimit || res.r != curR || res.c != curC) {
			printf("my_ans: (%d,%d), real_ans: (%d,%d)", res.r, res.c, curR, curC);
			okay = false;
		}
	}

	return okay;
}

int main()
{
	setbuf(stdout, NULL);
	freopen("input19.txt", "r", stdin);

	int T, MARK;
	scanf("%d%d", &T, &MARK);

	for (int tc = 1; tc <= T; ++tc)
	{
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}

	return 0;
}
