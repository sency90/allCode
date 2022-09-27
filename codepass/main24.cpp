/// *****  main.cpp *****
#include  <stdio.h>
#include  <time.h>

extern void test();

static const int MAIN_MAX = 50000000;
static double    SCORE = 0.0;
static char      tray[MAIN_MAX * 2];

char virus_checkup(int n)
{
	SCORE += 1.0;
	if (n < 0 || n >= MAIN_MAX * 2) return tray[0];
	return tray[n];
}

void culture(int n, int a, int b)
{
	if (n < MAIN_MAX || n >= MAIN_MAX * 2) return;
	if (a < 0 || a >= MAIN_MAX * 2) return;
	if (b < 0 || b >= MAIN_MAX * 2) return;
	tray[n] = tray[a] | tray[b];
}

void clear(int n)
{
	if (n < 0 || n >= MAIN_MAX * 2) return;
	SCORE += 10.0;
	tray[n] = 0;
}

static unsigned long long seed = 5;

static unsigned int random(void)
{
	seed = (seed = seed * 25214903917ULL + 11ULL);
	return ((unsigned int)(seed >> 16));
}

int main(void)
{
	freopen("input24.txt", "r", stdin);

	bool ok = true;

	for (int i = 0; i < 10; ++i) {

		int sd;
		scanf("%d", &sd);
		seed = sd;
		SCORE = 0;

		for (register int c = 0; c < MAIN_MAX * 2; c++) tray[c] = 0;

		for (register int c = 0; c < MAIN_MAX / 1000; c++) tray[random() % MAIN_MAX] = 1;

		clock_t time = clock();
		test();
		time = clock() - time;

		for (register int c = 0; c < MAIN_MAX; c++) {
			if (tray[c] != 0) {
				SCORE += 10000.0;
				puts("oops!");
			}
		}

		SCORE += ((double)(time) / CLOCKS_PER_SEC / 100);

		printf("SCORE: %.3f\n", SCORE);

		int cut;
		scanf("%d", &cut);
		if (SCORE > cut) ok = false;
	}

	if (ok) puts("PASS");
	else puts("FAIL");

	return 0;
}

