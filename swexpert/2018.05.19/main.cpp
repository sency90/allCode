#include <stdio.h>
#include <memory.h>
#include <time.h>

#define SIZE 4096

extern void recover(unsigned char map[SIZE][SIZE]);

static int seed = 1124; 
static unsigned char org_map[SIZE][SIZE];
static unsigned char new_map[SIZE][SIZE];
static unsigned char xoverlay[SIZE][SIZE];
static unsigned char yoverlay[SIZE][SIZE];
static unsigned char dummy1[256]; 
static unsigned char dummy2[SIZE];

bool check_map(unsigned char map[SIZE][SIZE]){
    if (memcmp(org_map, map, SIZE*SIZE)) return false;
    return true;
}

static int pseudo_rand(void){
    seed = seed * 214013 + 2531011;
    return (seed >> 16) & 0x7FFF;
}

static bool check_line(int x1, int y1, int x2, int y2)
{
    if (x2 - x1 < 16) return false;
    if (y2 - y1 < 16) return false;
    if (memcmp(&xoverlay[y1][x1], dummy2, x2 - x1 + 1)) return false;
    if (memcmp(&xoverlay[y2][x1], dummy2, x2 - x1 + 1)) return false;
    if (memcmp(&yoverlay[x1][y1], dummy2, y2 - y1 + 1)) return false;
    if (memcmp(&yoverlay[x2][y1], dummy2, y2 - y1 + 1)) return false;
    return true;
}

static void draw_rect(void)
{
    register int x1;
    register int y1;
    register int x2;
    register int y2;

    while (true)	{
        x1 = 16 + (pseudo_rand() % 4064);
        y1 = 16 + (pseudo_rand() % 4064);
        x2 = 16 + (pseudo_rand() % 4064);
        y2 = 16 + (pseudo_rand() % 4064);

        if (x1 > x2){
            int tmp = x1;
            x1 = x2;
            x2 = tmp;
        }

        if (y1 > y2){
            int tmp = y1;
            y1 = y2;
            y2 = tmp;
        }

        if (check_line(x1, y1, x2, y2))
        {
            memset(&xoverlay[y1][x1], 1, x2 - x1 + 1);
            memset(&xoverlay[y2][x1], 1, x2 - x1 + 1);
            memset(&yoverlay[x1][y1], 1, y2 - y1 + 1);
            memset(&yoverlay[x2][y1], 1, y2 - y1 + 1);
            break;
        }
    }

    register int c = pseudo_rand() % 255 + 1;
    for (register int x = x1; x <= x2; x++) {
        org_map[y1][x] = c;
        org_map[y2][x] = c;
    }
    for (register int y = y1; y <= y2; y++) {
        org_map[y][x1] = c;
        org_map[y][x2] = c;
    }
}

static void mixing_map() {
    for (register int c = 0; c < 256; c++)
    {
        register int x1 = pseudo_rand() % 16;
        register int y1 = pseudo_rand() % 16;
        register int x2 = pseudo_rand() % 16;
        register int y2 = pseudo_rand() % 16;

        for (register int cy = 0; cy < 256; cy++) {
            memcpy(dummy1, &new_map[y1 * 256 + cy][x1 * 256], 256);
            memcpy(&new_map[y1 * 256 + cy][x1 * 256], &new_map[y2 * 256 + cy][x2 * 256], 256);
            memcpy(&new_map[y2 * 256 + cy][x2 * 256], dummy1, 256);
        }
    }
}

static void create_map(void)
{
    for (register int y = 0; y < SIZE; y++)
        for (register int x = 0; x < SIZE; x++) {
            org_map[y][x] = 0;
            xoverlay[y][x] = 0;
            yoverlay[y][x] = 0;
        }

    for (int c = 0; c < 1024; c++)
        draw_rect();

    for (register int y = 0; y < SIZE; y++)
        for (register int x = 0; x < SIZE; x++) 
            new_map[y][x] = org_map[y][x];

    mixing_map();	
}



int main(void)
{
    int N;
    //freopen("output.txt", "w", stdout);
    //scanf("%d", &N); // no meaning, but at least one input is required to the marking system.

    //setbuf(stdout, NULL);
    int score = 1000000;
    memset(dummy2, 0, SIZE);
    for (int T = 0; T < 10; T++){
        create_map();
        time_t START = clock();
        recover(new_map);
        score += (int)((clock() - START) / (CLOCKS_PER_SEC / 1000));
        if (check_map(new_map))
            score -= 100000;
    }
    if ( score <= 3000 )
        printf("PASS\n");
    else
        printf("FAIL\n");
    printf("SCORE : %d\n", score);

    return 0;
}
