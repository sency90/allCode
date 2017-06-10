#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
char s[5][10];
int dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, 1, -1 };
int dx2[] = { 2, -2, 0, 0 }, dy2[] = { 0, 0, 2, -2 };
int pincnt, mncnt, mnn;
const int inf = 0x3f3f3f3f;
vector<pii> co;
inline bool validboard(int x, int y) {
    return !(x < 0 || y < 0 || x >= 5 || y >= 9);
}
void dfs(int idx, int cnt, int n) {
    if (idx >= pincnt) {
        if ((mnn > n) || ((mnn == n) && (mncnt > cnt))) {
            mnn = n; mncnt = cnt;
        }
        return;
    }
    int x = co[idx].first, y = co[idx].second;
    if (s[x][y]=='o') {
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (!validboard(nx, ny)) continue;
            if(s[nx][ny]!='o') continue;

            int nx2 = x + dx2[i], ny2 = y + dy2[i];
            if (!validboard(nx2, ny2)) continue;
            if(s[nx2][ny2]!='.') continue;
            s[x][y] = s[nx][ny] = '.';
            s[nx2][ny2] = 'o';
            co[idx] = pii(nx2, ny2);
            dfs(0, cnt + 1, n - 1);
            co[idx] = pii(x, y);
            s[x][y] = s[nx][ny] = 'o';
            s[nx2][ny2] = '.';
        }
    }
    dfs(idx + 1, cnt, n);
}
int main() {
    //freopen("input.txt", "r", stdin);
    int tc; scanf("%d", &tc);
    while (tc--) {
        co.clear();
        pincnt = 0;
        mncnt = inf;
        for (int i = 0; i < 5; i++) {
            scanf("%s", s[i]);
            for (int j = 0; j < 9; j++) {
                if (s[i][j] == 'o') {
                    co.push_back(pii(i, j));
                    pincnt++;
                }
            }
        }

        mncnt=inf; mnn=pincnt;
        dfs(0,0,pincnt);
        printf("%d %d\n", mnn, mncnt);
    }

    return 0;
}
