/// ***** main *****
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <memory.h>
#include <time.h>

static int  TC = 1; // it will be changed in evaluation

void test(unsigned char* freq, const unsigned char* bitMap);
void compress(unsigned char* comp, const unsigned char* freq);
void decompress(unsigned char* freq, const unsigned char* comp);

////////////////////////////////////////////////////////////

static void clear(unsigned char* freq)
{
	for (int y = 0; y < 1000; y++)
		for (int x = 0; x < 1000; x++)
			freq[y * 1000 + x] = 0;
}

static int sample(const unsigned char* bitMap, int x, int y)
{
	unsigned char mask;

	if (((0 <= x) && (x <= 5999)) == 0) return -1;
	if (((0 <= y) && (y <= 5999)) == 0) return -1;

	mask = 0x80 >> (x % 8);

	x = x / 8;
	y = y * (6000 / 8);

	if ((bitMap[y + x] & mask) == mask)
		return 1;
	else
		return 0;
}

static void add(unsigned char* freq, int x, int y)
{
	if (((0 <= x) && (x <= 5999)) == 0) return;
	if (((0 <= y) && (y <= 5999)) == 0) return;

	x = x / 6;
	y = y / 6 * 1000;

	freq[y + x]++;
}

static void count(unsigned char* freq, const unsigned char* bitMap)
{
	for (int y = 0; y < 6000; y++)
		for (int x = 0; x < 6000; x++)
			if (sample(bitMap, x, y) == 1) add(freq, x, y);
}

static void process1(unsigned char* freq)
{
	for (int y = 0; y < 1000; y++)
		for (int x = 0; x < 500; x++)
		{
			unsigned char tmp = freq[y * 1000 + x];
			freq[y * 1000 + x] = freq[y * 1000 + (999 - x)];
			freq[y * 1000 + (999 - x)] = tmp;
		}
}

static void process2(unsigned char* freq)
{
	for (int y = 0; y < 500; y++)
		for (int x = 0; x < 1000; x++)
		{
			unsigned char tmp = freq[y * 1000 + x];
			freq[y * 1000 + x] = freq[(999 - y) * 1000 + x];
			freq[(999 - y) * 1000 + x] = tmp;
		}
}

static void process3(unsigned char* freq)
{
	for (int y = 0; y < 1000; y++)
		for (int x = 0; x < 1000; x++)
			freq[y * 1000 + x] += 'J';
}

static void build(unsigned char* freq, const unsigned char* bitMap)
{
	clear(freq);
	count(freq, bitMap);

		long long sum = 0LL;
		for(int i=0; i<1000000; i++) {
			sum += freq[i];
		}
		printf("sum:%lld, avg:%lf\n", sum, (double)sum/1000000LL);
	process1(freq);
	process2(freq);
	process3(freq); 
}

static unsigned long long seed = 5;

static unsigned int random(void)
{
	seed = seed * 685728378367ULL + 11ULL;
	return (unsigned int)(seed >> 16);
}

int main(void)
{
	static unsigned char bitMap[4500000];
	static unsigned char dummy1[1026];
	static unsigned char freq1[1000000];
	static unsigned char dummy2[8597];
	static unsigned char freq2[1000000];
	static unsigned char dummy3[2329];
	static unsigned char freq3[1000000];
	static unsigned char dummy4[3352];
	static unsigned char comp1[700000];
	static unsigned char dummy5[2607];
	static unsigned char comp2[700000];

	bool ok = true;

	scanf("%d", &TC);

	seed = TC;

	int SCORE = 30000000 * TC;
	for (int tc = 0; tc < TC; tc++)
	{
		for (int c = 0; c < 4500000; c++)
			bitMap[c] = random();

		build(freq1, bitMap);
		break;
		clear(freq2);
		clear(freq3);

		clock_t begin = clock();

		test(freq2, bitMap);

		compress(comp1, freq2);
		memcpy(comp2, comp1, 700000);

		decompress(freq3, comp2);

		SCORE += (clock() - begin) / (CLOCKS_PER_SEC / 1000);

		if (memcmp(freq1, freq2, 1000000) == 0) SCORE -= 20000000;
		if (memcmp(freq1, freq3, 1000000) == 0) SCORE -= 10000000;
	}

	int cut;
	scanf("%d", &cut);
	if (SCORE > cut) ok = false;

	printf("SCORE: %d\n", SCORE);

	if (ok) puts("PASS");
	else puts("FAIL");

	return 0;
}
