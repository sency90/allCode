//robot_user.cpp
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 50

enum COMMAND
{
	CMD_GO = 0,
	CMD_BACK = 1,
	CMD_ROTATE_LEFT = 2,
	CMD_ROTATE_RIGHT = 3,
	CMD_QUIT = 4
};

const int off[4][12][2] = {
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
int NN, X, Y, D;
int mymap[MAX_N + 8][MAX_N + 8];
int xx[4] = { 1, 0, -1, 0 };/* direction[4] = { RIGHT, DOWN, LEFT, UP }; */
int yy[4] = { 0, 1, 0, -1 };
struct data {
	int x, y, d;
} que[MAX_N * MAX_N * 4];
int fr, re, chk[MAX_N + 8][MAX_N + 8][4], path[MAX_N + 8][MAX_N + 8][4];
int myway[MAX_N + 8][MAX_N + 8];

void init(int N)
{
	NN = N;
	for (int i = 0; i < N + 8; i++) for (int j = 0; j < N + 8; j++) {
		if (i < 4 || j < 4 || i > N + 3 || j > N + 3) mymap[i][j] = 1;
		else mymap[i][j] = 2;
		myway[i][j] = 1;
	}
	mymap[4][4] = mymap[N + 3][N + 3] = 0;
	X = Y = 4, D = 0;
}

int move(int cmd)
{
	switch (cmd) {
		case CMD_GO:
			if (mymap[Y + yy[D]][X + xx[D]] == 0) {
				Y += yy[D];
				X += xx[D];
			}
			break;

		case CMD_BACK:
			if (mymap[Y - yy[D]][X - xx[D]] == 0) {
				Y -= yy[D];
				X -= xx[D];
			}
			break;

		case CMD_ROTATE_LEFT:
			D = (D + 3) % 4;
			break;

		case CMD_ROTATE_RIGHT:
			D = (D + 1) % 4;
			break;
	}
	return cmd;
}

int enq(int y, int x, int d, int p)
{
	if (mymap[y][x] == 1 || chk[y][x][d] == 1) return 0;
	chk[y][x][d] = 1;
	path[y][x][d] = p;
	que[re].y = y, que[re].x = x, que[re].d = d;
	if (y == NN + 3 && x == NN + 3) return 1;
	re++;
	return 0;
}

void path_make(int y, int x, int d, int p)
{
	myway[y][x] = 1;
	if (y == Y && X == x && d == D) return;
	if (p == 0) y -= yy[d], x -= xx[d];
	else if (p == 1) y += yy[d], x += xx[d];
	else if (p == 2) d = (d + 1) % 4;
	else d = (d + 3) % 4;
	int tmp = path[y][x][d];
	path[y][x][d] = p;  
	path_make(y, x, d, tmp);
}

int bfs()
{
	fr = re = 0;
	int y, x, d;
	for (int i = 0; i < NN + 8; i++) for (int j = 0; j < NN + 8; j++) {
		for (int k = 0; k < 4; k++) chk[i][j][k] = 0;
		myway[i][j] = 0;
	}
	enq(Y, X, D, 0);
	while (fr < re) {
		y = que[fr].y, x = que[fr].x, d = que[fr].d;
		fr++;
		if(enq(y + yy[d], x + xx[d], d, 0)) break;
		if (mymap[y - yy[d]][x - xx[d]] == 0) if(enq(y - yy[d], x - xx[d], d, 1)) break;
		enq(y, x, (d + 3) % 4, 2);
		enq(y, x, (d + 1) % 4, 3);
	}
	if (fr >= re) return 1;
	path_make(NN + 3, NN + 3, d, path[NN+3][NN+3][d]);
	return 0;
}

int go(int input[12])
{
	int coordX, coordY, sw = 0;
	for (int i = 0; i < 12; i++)
	{
		coordX = X + off[D][i][0];
		coordY = Y + off[D][i][1];
		mymap[coordY][coordX] = input[i];
		if (input[i] == 1 && myway[coordY][coordX] == 1) sw = 1;
	}
	if (sw == 1) {
		//printf("%d %d %d\n", Y, X, D);
		if(bfs()) return 4;
	}
	return move(path[Y][X][D]);
}
