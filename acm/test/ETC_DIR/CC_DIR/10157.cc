#include <cstdio>
#include <cstdlib>
#include <cstring>
bool bd[1002][1002];
int main()
{
    int C, R, K;
    scanf("%d%d%d", &C, &R, &K);

    if (K > C * R)
    {
        printf("0");
        exit(0);
    }

    int wid = R, ht = C, y = 1, x = 1, k = 1;
    char dir = 'E';

    memset(bd, false, sizeof(bd));
    for (int i = 0; i <= ht + 1; i++) bd[i][0] = bd[i][wid + 1] = true;
    for (int j = 0; j <= wid + 1; j++) bd[0][j] = bd[ht + 1][j] = true;

    bd[1][1] = true;
    while (k != K) {
        printf("%d %d\n", y, x);
        if (dir == 'E') {
            if (bd[y][x + 1]) dir = 'S';
            else {
                k++;
                bd[y][++x] = true;
            }
        } else if (dir == 'W') {
            if (bd[y][x - 1]) dir = 'N';
            else {
                k++;
                bd[y][--x] = true;
            }
        } else if (dir == 'S') {
            if (bd[y + 1][x]) dir = 'W';
            else {
                k++;
                bd[++y][x] = true;
            }
        } else {
            if (bd[y - 1][x]) dir = 'E';
            else {
                k++;
                bd[--y][x] = true;
            }
        }
    }
    printf("%d %d", y, x);
    return 0;
}
