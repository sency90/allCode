/// ***** main.cpp *****
#include <stdio.h>
#include <time.h>

#define DATA_SIZE 1048576
#define DIGIT_SIZE 2048

extern void test(unsigned int data[DATA_SIZE]);

static unsigned int data[DATA_SIZE];
static unsigned int user_data[DATA_SIZE];

static int SCORE = 0;
static short tmp[1024];
static unsigned int digit[DIGIT_SIZE];
static int SEED;

static unsigned int myrand(void) {
	static unsigned int seed = SEED;
	return ((seed = seed * 0x343fd + 0x269ec3) >> 16);
}

void m_sort(short data[1024], int s, int e) {
	if (s >= e)
		return;

	int m = (s + e) / 2;
	m_sort(data, s, m);
	m_sort(data, m + 1, e);

	int i = s, j = m + 1, k = s;
	while (i <= m && j <= e)
	{
		if (data[i] < data[j]) tmp[k++] = data[i++];
		else tmp[k++] = data[j++];
	}
	while (i <= m)
		tmp[k++] = data[i++];
	while (j <= e)
		tmp[k++] = data[j++];

	for (int i = s; i <= e; i++)
		data[i] = tmp[i];
}

void hw_sort(short data[1024]) {
	clock_t start = clock();
	m_sort(data, 0, 1023);
	SCORE -= clock() - start;
}

int main() {
	SEED = 5;
	int TestCase = 1; //=10;
	for (int TC = 0; TC < TestCase; TC++) {
		for (int i = 0; i < DIGIT_SIZE; i++) {
			digit[i] = myrand() % 65536;
		}
		for (int i = 0; i < DATA_SIZE; i++) {
			int x = myrand() % DIGIT_SIZE;
			int y = myrand() % DIGIT_SIZE;
			data[i] = user_data[i] = ((digit[x] << 16) | digit[y]);
		}

		clock_t start = clock();
		test(user_data);
		SCORE += clock() - start;

		for (int i = 0; i < DATA_SIZE - 1; i++) {
			if (user_data[i] < user_data[i + 1]) {
				SCORE = 100000000;
				break;
			}
		}
		for (int i = 0; i < 100; i++) {
			int k = myrand() % DATA_SIZE, flag = 0;
			for (int j = 0; j < DATA_SIZE; j++) {
				if (user_data[j] == data[k]) {
					flag = 1;
					break;
				}
			}
			if (flag == 0)
				SCORE = 100000000;
		}
	}
	int score = SCORE / (CLOCKS_PER_SEC / 1000);
	//printf("SCORE : %d\n", score);
	if (score > 1000) puts("FAIL");
	else puts("PASS");
	return 0;
}
