/// ***** main.cpp *****
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <memory.h>
#include <time.h>

extern int encode(char* enc_str, char* str, int STRN);
extern void decode(char* dec_str, char* enc_str, int encn);

static unsigned int SEED = 5;     // can be changed.
const int STRN = 65535;
const int WORDN = 1024;
const int CHARN = 26;

int cnt[CHARN] = { 79,13,24,48,129,20,25,51,76,3,22,18,32,54,110,10,1,55,40,95,16,8,34,2,29,1 };
char enc_str[STRN];
char charlist[996];
int wordlen[WORDN];
char words[WORDN][8];
char str[STRN];
char dummy1[11111];    // can be changed.
char dec_str[STRN];
char dummy2[22222];    // can be changed.
char str_bak[STRN];

unsigned int myrand(void) // RAND_MAX assumed to be 32767
{
	static unsigned int seed = SEED;
	return (unsigned int)((seed = seed * 1103515245 + 12345) >> 16) & 0x7fff;
}

void build1()
{
	int i, j, k = 0;
	for (i = 0; i < CHARN; i++)
		for (j = 0; j < cnt[i]; j++)
			charlist[k++] = 'a' + i;

	for (i = 0; i < WORDN; i++) {
		wordlen[i] = myrand() % 7 + 1;
		for (j = 0; j < wordlen[i]; j++)
			words[i][j] = charlist[myrand() % 995];
	}
}

void build2()
{
	int len = 0, i, k;

	for (i = 0; i < STRN; i++)
		str[i] = str_bak[i] = enc_str[i] = dec_str[i] = 0;


	while (1) {
		k = myrand() % WORDN;
		if (len + wordlen[k] >= STRN) break;
		for (i = 0; i < wordlen[k]; i++) str[len++] = words[k][i];
		str[len++] = ' ';
	}
	for (i = 0; i < STRN; i++)
		str_bak[i] = str[i];
}

int main()
{
	int i, TC = 100;
	long long score = 0;

	build1();

	double start = clock();
	for (int t = 0; t < TC; t++) {

		build2();

		int encn = encode(enc_str, str, STRN);

		for (i = encn; i < STRN; i++) enc_str[i] = 0;
		for (i = 0; i < STRN; ++i) str[i] = charlist[myrand() % 995];

		decode(dec_str, enc_str, encn);

		if (memcmp(dec_str, str_bak, STRN) != 0)
			score += 10000000;
		else score += encn;
	}

	score += (long long)(((double)clock() - start) / CLOCKS_PER_SEC * 1000);

	if (score > 2000000) puts("FAIL");
	else puts("PASS");

	printf("SCORE: %lld\n", score);

	return 0;
}

