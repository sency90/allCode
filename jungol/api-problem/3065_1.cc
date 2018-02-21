/**************************************************************
    Problem: 3065
    User: sency90
    Language: C++
    Result: Success
    Time:13 ms
    Memory:1208 kb
****************************************************************/

//teacher
#include <stdio.h>

int N, M, H, P, board[30000], b[3];

void rotate(int a[3][3])
{
	int tmp[3][3], i, j;
	for (i = 0; i < 3; i++) for (j = 0; j < 3; j++) tmp[i][j] =a[j][2-i];
	for (i = 0; i < 3; i++) for (j = 0; j < 3; j++) a[i][j] = tmp[i][j];
}

void input()
{
	int blk[3][3], rot, mov, i, j;
	for (i = 2; i >= 0; i--) for (j = 0; j < 3; j++) scanf("%d", &blk[i][j]);
	scanf("%d %d", &rot, &mov);
	rot %= 4;
	while (rot--) rotate(blk);
	for (i = 0; i < 3; i++) b[i] = blk[i][2] * 4 + blk[i][1] * 2 + blk[i][0];
	while (b[0] == 0) {
		b[0] = b[1]; b[1] = b[2]; b[2] = 0;
	}
	while((b[0] & 1) + (b[1] & 1) + (b[2] % 2) == 0) for (i = 0; i < 3; i++) b[i] /= 2;
	for (i = 0; i < 3; i++) b[i] <<= mov;
	while (b[0] > P || b[1] > P || b[2] > P) for (i = 0; i < 3; i++) b[i] /= 2;
}

void drop()
{
	int i, j, k;
	for (i = H; i > 0; i--) {
		if ((board[i] & b[0]) + (board[i + 1] & b[1]) + (board[i + 2] & b[2])) break;
	}
	for (j = 2, k = i + 3; j >= 0; j--, k--) {
		board[k] += b[j];
		if (board[k] == P) {
			for (i = k; i <= H; i++) board[i] = board[i + 1];
			H--;
		}
		if (board[k] && k > H) H = k;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	P = (1 << N) - 1;
	while (M--) {
		input();
		drop();
	}
	printf("%d\n", H);
	return 0;
}
