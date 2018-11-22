#include <stdio.h>
const int SIZE = 64;

unsigned char dummy1[256];
unsigned char image[SIZE][SIZE];
unsigned char dummy2[256];

int SCORE,COUNT;
int seed = 3;

extern int recog(unsigned char image[SIZE][SIZE]);

static int pseudo_rand() {
	seed = seed * 214013 + 2531011;
	return (seed >> 16) & 0x7FFF;
}

void rect() {
	int sx,sy,ex,ey;
	while(true) {
		sy = pseudo_rand() % SIZE;
		sx = pseudo_rand() % SIZE;
		ey = pseudo_rand() % SIZE;
		ex = pseudo_rand() % SIZE;

		if(sx > ex) sx ^= ex,ex ^= sx,sx ^= ex;
		if(sy > ey) sy ^= ey,ey ^= sy,sy ^= ey;

		if(ex - sx < 9) continue;
		if(ey - sy < 9) continue;

		break;
	}
	for(register int i = sx; i <= ex; i++) {
		for(register int j = sy; j <= ey; j++) {
			image[i][j]++;
		}
	}

	if(ex - sx == ey - sy) COUNT++;
}

void draw() {
	for(register int i = 0; i < SIZE; i++) {
		for(register int j = 0; j < SIZE; j++) {
			image[i][j] = 0;
		}
	}

	COUNT = 0;
	for(register int i = 0; i < 50; i++) {
		rect();
	}
}

int main() {
	SCORE=0;
	for(register int T = 0; T < 10000; T++) {
		draw();
		if(recog(image) == COUNT) SCORE++;
	}
	printf("SCORE: %d\n",SCORE);
	return 0;
}


