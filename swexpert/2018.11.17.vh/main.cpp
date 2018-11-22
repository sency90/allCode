#include <cstdio>
const int SIZE = 100;
const int NUM_RECT = 64;
const int MIN_RECT_SIZE = 10;
int COUNT, SCORE;
int seed = 1117;

int image[SIZE][SIZE];
extern int recog(int image[SIZE][SIZE]);
static int pseudo_rand(void){
	seed = seed * 214013 + 2531011;
	return (seed >> 16) & 0x7FFF;
}

void rect() {
	int sx, sy, ex, ey, tmp;
	while (true) {
		sx = pseudo_rand() % SIZE;
		ex = pseudo_rand() % SIZE;
		sy = pseudo_rand() % SIZE;
		ey = pseudo_rand() % SIZE;

		if (sx > ex) {
			tmp = sx;
			sx = ex;
			ex = tmp;
		}

		if (sy > ey) {
			tmp = sy;
			sy = ey;
			ey = tmp;
		}
		if (ex - sx < MIN_RECT_SIZE) continue;
		if (ey - sy < MIN_RECT_SIZE) continue;
		break;
	}
	int height = pseudo_rand()%5 + 1;
	for (register int y = sy; y <= ey; y++)
		for (register int x = sx; x <= ex; x++)
			image[y][x] += height;
	if (ex - sx == ey - sy) 
		COUNT++;
}

void _build() {
	for (int y = 0; y < SIZE; y++)
		for (int x = 0; x < SIZE; x++)
			image[y][x] = 0;
	COUNT = 0;
	for (int i = 0; i < NUM_RECT; i++) rect();
}

int main() {
	//scanf("%d", &seed);
	SCORE = 0;
	for (int T = 0; T < 3000; T++)
	{
		_build();
		if ( recog(image) == COUNT) SCORE++;
	}

    printf("%d\n", SCORE);
	if (SCORE >= 2700)
		printf("PASS\n");
	else
		printf("FAIL\n");
	//printf("RESULT: %d\n", SCORE);

	return 0;
}
