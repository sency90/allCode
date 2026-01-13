#include <bits/stdc++.h>
using namespace std;
int H, W, R[4], C[4];
int mcnt, blkcnt;
string m[11];
string ppblk[4][11]; //전처리 blk
struct Coord {
    int x, y;
    Coord() {}
    Coord(int x, int y) :x(x), y(y) {}
    inline bool operator<(const Coord& rhs) const {
        if (x == rhs.x) return y < rhs.y;
        else return x < rhs.x;
    }
    inline bool operator==(const Coord& rhs) const {
        return x == rhs.x && y == rhs.y;
    }
};
vector<vector<Coord>> blks;
void Rotate(int x) { //x-1 -> x
    R[x] = C[x - 1];
    C[x] = R[x - 1];

    //주의1. string변수가 비어있는 상태에서 char단위로 다룰 때, resize()를 먼저 해줘야 한다.
    for (int i = 0; i < R[x]; i++) {
        ppblk[x][i].resize(C[x]);
    }
    for (int i = 0; i < R[x - 1]; i++) {
        for (int j = 0; j < C[x - 1]; j++) {
            ppblk[x][j][C[x] - i - 1] = ppblk[x - 1][i][j];
        }
    }
}
void MakeBlksVector() {
    blks.clear();
    blks.resize(4);
    Coord gz;
    for (int z = 0; z < 4; z++) {
        for (int i = 0; i < R[z]; i++) {
            for (int j = 0; j < C[z]; j++) {
                if (ppblk[z][i][j] == '#') {
                    gz = Coord(i, j);
                    goto BRK;
                }
            }
        }
    BRK:
        for (int i = 0; i < R[z]; i++) {
            for (int j = 0; j < C[z]; j++) {
                if (ppblk[z][i][j] == '#') {
                    blks[z].emplace_back(i - gz.x, j - gz.y);
                }
            }
        }
       //sort(blks[z].begin(), blks[z].end()); 
       //-> 위에서 반복문 순서에 의해 항상 정렬된 상태로 남아있기 때문에 여기서 sort()를 굳이 해줄 필요 없다.
        blks.emplace_back(blks[z]);
    }

    //주의5. 중복처리 안하면 시간초과로 WA받는다.
    //vector<Coord>에 대한 동등비교가 가능한지 의문이라 이 코드가 되려나 싶었는데, 중복처리가 잘 되는 것 같다.
    sort(blks.begin(), blks.end());
    blks.erase(unique(blks.begin(), blks.end()), blks.end());
}
bool CanPutDownBlks(int z, int x, int y) {
    for (int i = 0; i < blks[z].size(); i++) {
        const Coord& co = blks[z][i];
        int nx = x + co.x;
        int ny = y + co.y;
        if (nx < 0 || ny < 0 || nx >= H || ny >= W) return false;
        if (m[nx][ny] == '#') return false;
    }
    return true;
}
void PutDownBlks(int z, int x, int y) {
    for (int i = 0; i < blks[z].size(); i++) {
        const Coord& co = blks[z][i];
        m[x + co.x][y + co.y] = '#';
    }
    mcnt -= blkcnt;
}
void RestoreBlks(int z, int x, int y) {
    for (int i = 0; i < blks[z].size(); i++) {
        const Coord& co = blks[z][i];
        m[x + co.x][y + co.y] = '.';
    }
    mcnt += blkcnt;
}
int ans;
//주의4. 가지치기를 해야하기 때문에 dfs()가 BLOCK을 놓는 최대개수를 return하는 식으로 만들어선 안되고,
//      아래 처럼 현재까지 몇개의 BLOCK을 놓았는지(placed)를 인자로 전달하는 식으로 구현해야한다.
void dfs(int x, int y, int placed) {
    ans = max(ans, placed);

    if (x == H) return;
    if (y == W) {
        dfs(x + 1, 0, placed);
        return;
    }
    //주의3. 아래의 가지치기가 핵심이다.
    if (placed + mcnt / blkcnt <= ans) return;
    if (m[x][y] == '#') {
        dfs(x, y + 1, placed);
        return;
    }

    for (int z = 0; z < blks.size(); z++) {
        if (!CanPutDownBlks(z, x, y)) continue;
        PutDownBlks(z, x, y);
        dfs(x, y + 1, placed + 1);
        RestoreBlks(z, x, y);
    }
    //주의2. map이 '.'인 곳을 BLOCK으로 채우지 않고 넘어가는 경우,
    //      아래와 같이 mcnt값을 하나 빼주는게 키포인트! 
    //      여기서 속도가 엄청나게 줄어든다. 가장 핵심인 부분
    m[x][y] = '#';
    mcnt--;
    dfs(x, y + 1, placed);
    m[x][y] = '.';
    mcnt++;
}
int main() {
    int tc; cin >> tc;
    while (tc--) {
        cin >> H >> W >> R[0] >> C[0];
        for (int i = 0; i < H; i++) {
            cin >> m[i];
        }
        for (int i = 0; i < R[0]; i++) {
            cin >> ppblk[0][i];
        }

        mcnt = 0;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (m[i][j] == '.') mcnt++;
            }
        }

        for (int i = 1; i < 4; i++) Rotate(i);
        MakeBlksVector();

        blkcnt = blks[0].size();

        ans = 0;
        dfs(0, 0, 0);
        printf("%d\n", ans);
    }
    return 0;
}