#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <string.h>
#include <time.h>
#define TC (100)   // This will be changed

extern void test(char[], char result[]);

using ULL = unsigned long long;

ULL seed = 5;     // This will be changed

static inline unsigned short myRand(void)
{
	seed = seed * 0x5DEECE66Dull + 11ull;
	return (unsigned short)(seed >> 16);
}

static void makeFormula(char formula[10000])
{
	size_t fp = 0;
	int openBracketCnt = 0;
	char str[32];
	sprintf(str, "%d", myRand());
	strcpy(formula, str);
	fp = strlen(str);

	for (int c = 0; c < 1000; c++)
	{
		int cmd = myRand() % 18;
		if (cmd < 3) {
			sprintf(str, " + %d", myRand());
			strcpy(formula + fp, str);
			fp += strlen(str);
		}
		else if (cmd < 6) {
			sprintf(str, " - %d", myRand());
			strcpy(formula + fp, str);
			fp += strlen(str);
		}
		else if (cmd < 9) {
			sprintf(str, " * %d", myRand());
			strcpy(formula + fp, str);
			fp += strlen(str);
		}
		else if (cmd == 9) {
			sprintf(str, " + ( %d", myRand());
			strcpy(formula + fp, str);
			fp += strlen(str);
			openBracketCnt++;
		}
		else if (cmd == 10) {
			sprintf(str, " - ( %d", myRand());
			strcpy(formula + fp, str);
			fp += strlen(str);
			openBracketCnt++;
		}
		else if (cmd == 11) {
			sprintf(str, " * ( %d", myRand());
			strcpy(formula + fp, str);
			fp += strlen(str);
			openBracketCnt++;
		}
		else {
			if (openBracketCnt > 0) {
				sprintf(str, " )");
				strcpy(formula + fp, str);
				fp += strlen(str);
				openBracketCnt--;
			}
		}
	}
	while (openBracketCnt > 0) {
		sprintf(str, " )");
		strcpy(formula + fp, str);
		fp += strlen(str);
		openBracketCnt--;
	}
}

int main()
{
	freopen("input32.txt", "r", stdin);
	int sd;
	scanf("%d", &sd);
	seed = sd;

	static char result[TC][10000];
	static char formula[TC][10000];
	static char ans[TC][10000];

	for (int tc = 0; tc < TC; ++tc) {
		makeFormula(formula[tc]);
		scanf("%s", ans[tc]);
	}

	ULL SCORE = 0;
	time_t perf = clock();
	for (int tc = 0; tc < TC; tc++)
	{
		test(formula[tc], result[tc]);
		if (strcmp(ans[tc], result[tc]) != 0)
		{
			SCORE += 10000000;    // Wrong Result
			//break;
		}
	}
	perf = (clock() - perf) / (CLOCKS_PER_SEC / 1000);
	SCORE += perf;

	printf("%lld\n", perf);

	if (SCORE < 40) puts("PASS");
	else puts("FAIL");
	return 0;
}
