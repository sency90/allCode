//robot_example
#define _CRT_SECURE_NO_WARNINGS // Ignore build errors when using unsafe functions in Visual Studio.

#include <stdio.h>
#include <stdlib.h>

#define OBS_ratio 0
#define MAX_N 50
#define LIMIT 10000
//#define LIMIT 1000000
#define PENALTY 1000000

enum COMMAND
{
	CMD_GO = 0,
	CMD_BACK = 1,
	CMD_ROTATE_LEFT = 2,
	CMD_ROTATE_RIGHT = 3,
	CMD_QUIT = 4
};

static int N;
extern void init(int N);
extern int go(int input[12]);

/* direction[4] = { RIGHT, DOWN, LEFT, UP }; */
static int dx[4] = { 1, 0, -1, 0 };
static int dy[4] = { 0, 1, 0, -1 };

const int offset[4][12][2] = {
	{   // RIGHT
		{ 4, 0 },
		{ 3, -1 }, { 3, 0 }, { 3, 1 },
		{ 2, -2 }, { 2, -1 }, { 2, 0 }, { 2, 1 }, { 2, 2 },
		{ 1, -1 }, { 1, 0 }, { 1, 1 }
	},
	{   // DOWN
		{ 0, 4 },
		{ 1, 3 }, { 0, 3 }, { -1, 3 },
		{ 2, 2 }, { 1, 2 }, { 0, 2 }, { -1, 2 }, { -2, 2 },
		{ 1, 1 }, { 0, 1 }, { -1, 1 }
	},
	{   // LEFT
		{ -4, 0 },
		{ -3, 1 }, { -3, 0 }, { -3, -1 },
		{ -2, 2 }, { -2, 1 }, { -2, 0 }, { -2, -1 }, { -2, -2 },
		{ -1, 1 }, { -1, 0 }, { -1, -1 }
	},
	{   // UP
		{ 0, -4 },
		{ -1, -3 }, { 0, -3 }, { 1, -3 },
		{ -2, -2 }, { -1, -2 }, { 0, -2 }, { 1, -2 }, { 2, -2 },
		{ -1, -1 }, { 0, -1 }, { 1, -1 }
	}
};


static int run()
{
	int moves, locX, locY, dir, expected;
	int coordX, coordY;
	int sensor[12], map[MAX_N + 8][MAX_N + 8];

	for (int i = 0; i < N + 8; i++)
		for (int j = 0; j < N + 8; j++)
			map[i][j] = 1;

	//scanf("%d", &expected);
	expected = -1;

	/*
	   for (int i = 4; i < N + 4; i++)
	   for (int j = 4; j < N + 4; j++)
	   scanf("%d", &map[i][j]);
	   */

	for (int i = 4; i < N + 4; i++)
		for (int j = 4; j < N + 4; j++)
		{
			if ((rand() % 100) + 1 > 30) //OBS_ratio)
				map[i][j] = 0;
			//else
			//int d = 0;
		}


	map[4][4] = map[N + 3][N + 3] = 0;

	locY = locX = 4;
	dir = 0;

	moves = 0;

	while (moves < LIMIT)
	{
		for (int i = 0; i < 12; i++)
		{
			coordX = locX + offset[dir][i][0];
			coordY = locY + offset[dir][i][1];
			sensor[i] = map[coordY][coordX];
		}

		switch (go(sensor))
		{
			case CMD_GO:
				if (map[locY + dy[dir]][locX + dx[dir]] == 0) {
					locY += dy[dir];
					locX += dx[dir];
				}
				break;

			case CMD_BACK:
				if (map[locY - dy[dir]][locX - dx[dir]] == 0) {
					locY -= dy[dir];
					locX -= dx[dir];
				}
				break;

			case CMD_ROTATE_LEFT:
				dir = (dir + 3) % 4;
				break;

			case CMD_ROTATE_RIGHT:
				dir = (dir + 1) % 4;
				break;

			case CMD_QUIT:
				return (expected == -1) ? moves : LIMIT;
		}

		if (locX == N + 3 && locY == N + 3)
			break;

		moves++;
	}
	return moves;
}

int main()
{
	setbuf(stdout, NULL);
	//freopen("sample_input.txt", "r", stdin);

	int T;
	int total_moves = 0;

	//scanf("%d", &T);
	T = 100;

	for (int t = 1; t <= T; ++t)
	{
		//scanf("%d", &N);

		N = 50;

		init(N);
		int moves = run();

		if (moves == LIMIT)
			moves = PENALTY;

		printf("#%d %d\n", t, moves);
		total_moves += moves;
	}

	printf("Total Move Count = %d\n", total_moves);
	return 0;
}
