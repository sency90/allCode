#include <bits/stdc++.h>
using namespace std;
struct Coord {
    int x, y;
    Coord() {}
    Coord(int x, int y) : x(x), y(y) {}
};

struct Block {
    Coord co[3];
    Block(Coord co1, Coord co2, Coord co3) {
        co[0] = co1;
        co[1] = co2;
        co[2] = co3;
    }
};

Block blks[4] = {{{0, 0}, {1, 0}, {1, -1}},
                 {{0, 0}, {0, 1}, {1, 0}},
                 {{0, 0}, {0, 1}, {1, 1}},
                 {{0, 0}, {1, 0}, {1, 1}}};

string board[21];
int h, w, ans;
int empty_space_cnt;

bool CanPutBlockDown(int x, int y, const Block& blk) {
    int cnt = 0;
    for(int z = 0; z < 3; z++) {
        int nx = x + blk.co[z].x;
        int ny = y + blk.co[z].y;
        if(nx < 0 || ny < 0 || nx >= h || ny >= w) return false;
        if(board[nx][ny] == '.') cnt++;
    }
    return cnt == 3;
}
void PutBlockDown(int x, int y, const Block& blk) {
    for(int z = 0; z < 3; z++) {
        board[x + blk.co[z].x][y + blk.co[z].y] = '!';
    }
}
void RemoveBlock(int x, int y, const Block& blk) {
    for(int z = 0; z < 3; z++) {
        board[x + blk.co[z].x][y + blk.co[z].y] = '.';
    }
}

void Dfs(int x, int y, int cnt) {
    if(cnt == empty_space_cnt) {
        ans++;
        return;
    }
    if(x == h - 1 && y == w || x == h) {
        return;
    }
    if(y == w) {
        Dfs(x + 1, 0, cnt);
        return;
    }

    if(board[x][y] == '.') {
        bool is_in = false;
        for(int k = 0; k < 4; k++) {
            if(CanPutBlockDown(x, y, blks[k])) {
                is_in = true;
                PutBlockDown(x, y, blks[k]);
                Dfs(x, y + 1, cnt + 3);
                RemoveBlock(x, y, blks[k]);
            }
        }

        if(!is_in) return;
    } else {
        Dfs(x, y + 1, cnt);
    }
}
void Init() {
    empty_space_cnt = 0;
    ans = 0;
}
int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        Init();
        cin >> h >> w;
        for(int i = 0; i < h; i++) {
            cin >> board[i];
        }

        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(board[i][j] == '.') empty_space_cnt++;
            }
        }

        Dfs(0, 0, 0);
        printf("%d\n", ans);
    }
    return 0;
}
