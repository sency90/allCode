#include <stdio.h>
#include <iostream>

using namespace std; 

int n,m, cnt; 
int map[105][105]; 
int x[105], y[105], l[105]; 
bool chk[105][105];


void enqueue(int _x, int _y, int _l)
{
    x[cnt] = _x;
    y[cnt] = _y;
    l[cnt] = _l;
    cnt++;
}

void BFS(int _x, int _y)
{
    int pos = 0;
    enqueue(_x, _y, 1);
    chk[_x][_y]=true;
    while (pos < cnt && (x[pos] != n - 1 || y[pos] != m - 1))
    {
        map[x[pos]][y[pos]] = 0;
        int a=x[pos], b=y[pos];

        if (y[pos] > 0 && map[x[pos]][y[pos] - 1] == 1 && !chk[a][b-1]) {
            chk[a][b-1]=true;
            enqueue(x[pos], y[pos] - 1, l[pos] + 1);
        }
        if (y[pos] < m - 1 && map[x[pos]][y[pos] + 1] == 1 && !chk[a][b+1]) {
            chk[a][b+1]=true;
            enqueue(x[pos], y[pos] + 1, l[pos] + 1);
        }
        if (x[pos] > 0 && map[x[pos] - 1][y[pos]] == 1 && !chk[a-1][b]) {
            chk[a-1][b]=true;
            enqueue(x[pos] - 1, y[pos], l[pos] + 1);
        }
        if (x[pos] < n - 1 && map[x[pos] + 1][y[pos]] == 1 && !chk[a+1][b]) {
            chk[a+1][b]=true;
            enqueue(x[pos] + 1, y[pos], l[pos] + 1);
        }
        pos++;
    }

    if (pos < cnt)
        printf("%d\n", l[pos]);
}

int main()
{
    int i, j;
    cin>>n>>m;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%1d", &map[i][j]);
    BFS(0, 0);
    return 0;
}
