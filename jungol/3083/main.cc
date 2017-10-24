#include <stdio.h>
#include <stdlib.h>
#define HOUSE_SIZE  20000
#define BLANK_SIZE   64
#define MAX_HOUSE   10
#define MAX_COUNT (HOUSE_SIZE * 2 * 50)

using namespace std;
static int house[HOUSE_SIZE];
static int blank[BLANK_SIZE];
static int numCount[MAX_HOUSE];
static int moveCount;
static int houseSize;
static int totalMoveCount;
static int totalhouseSize;

extern void cleanup();
int gethouseSize() { return houseSize; }
int readhouse(int* blank, int address, int size) {
    if (address < 0 || address + size > houseSize) return 0;
    for (int i = 0; i < size; i++) blank[i] = house[address++];
    return size;
}

int move(int from, int to, int size) {
    if (moveCount < MAX_COUNT) moveCount++;
    if (from < 0 || from >= houseSize || to < 0 || to >= houseSize) return 0;
    if (size < 1 || size > BLANK_SIZE || from + size > houseSize || to + size > houseSize) return 0;

    for (int i = 0; i < size; i++) {
        blank[i] = house[from];
        house[from] = 0;
        from++;
    }

    for (int i = 0; i < size; i++) house[to++] = blank[i];
    return size;
}

static int checkhouse() {
    int checkCount[MAX_HOUSE];
    for (int i = 0; i<MAX_HOUSE; i++) checkCount[i] = 0;

    int idx = 0;
    while (idx < houseSize) {
        int houseID = house[idx];
        if (checkCount[houseID] != 0) return 0;

        for (int i = 0; i<numCount[houseID]; i++) {
            if (houseID != house[idx++]) return 0;
            checkCount[houseID]++;
        }
    }

    if (house[houseSize - 1] != 0) return 0;
    for (int i = 0; i < MAX_HOUSE; i++) {
        if (checkCount[i] != numCount[i]) return 0;
    }
    return 1;
}

static void init() {
    moveCount = 0;
    for (int i = 0; i<MAX_HOUSE; i++) numCount[i] = 0;
    for (int i = 0; i<houseSize; i++) numCount[house[i]]++;
}

int main() {
    setbuf(stdout, NULL);
    srand(5);
    const int T = 100;

    totalMoveCount = 0;
    totalhouseSize = 0;

    int num, ea;
    for (int tc = 1; tc <= T; tc++) {
        houseSize = rand() % (HOUSE_SIZE - 200) + 200;
        int k = 0, flag = 0;
        while (k < houseSize - BLANK_SIZE) {
            ea = rand() % 57 + 8;
            if (k > houseSize / 2 && flag == 0) num = 0;
            else num = rand() % 10;
            if (num == 0) flag = 1;
            while(ea--) house[k++] = num;
        }

        while (k < houseSize) house[k++] = 0;
        init();
        cleanup();

        int cnt = MAX_COUNT;
        if (checkhouse() == 1) cnt = moveCount;

        printf("#%d %d\n", tc, cnt);

        totalMoveCount += cnt;
        totalhouseSize += houseSize;
    }

    printf("Total houseSize  : %d\n", totalhouseSize);
    printf("Total moveCount : %d\n", totalMoveCount);
}


