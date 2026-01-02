#include <bits/stdc++.h>
using namespace std;
int H, W, R[4], C[4];
int mcnt, blkcnt;
string m[11];
string blk[4][11];
struct Coord {
    int x, y;
    Coord() {}
    Coord(int x, int y) :x(x), y(y) {}
    bool operator<(const Coord& rhs) const {
        if (x == rhs.x) return y < rhs.y;
        else return x < rhs.x;
    }
    bool operator!=(const Coord& rhs) const {
        return x!=rhs.x || y!=rhs.y;
    }
    bool operator==(const Coord& rhs) const {
        return x==rhs.x && y==rhs.y;
    }
};
vector<vector<Coord>> blks;
void Rotate(int x) { //x-1 -> x
    R[x]=C[x-1];
    C[x]=R[x-1];

    for(int i=0; i<R[x]; i++) {
        blk[x][i] = string(C[x],'.');
    }
    for (int i = 0; i < R[x - 1]; i++) {
        for (int j = 0; j < C[x - 1]; j++) {
            blk[x][j][C[x] - i - 1] = blk[x - 1][i][j];
        }
    }
}

const int INF = 0x3f3f3f3f;
void MakeBlksVector() {
    blks.clear();
    blks.resize(4);
    Coord gz;
    for (int z = 0; z < 4; z++) {
        blks[z].clear();
        for (int i = 0; i < R[z]; i++) {
            for (int j = 0; j < C[z]; j++) {
                if (blk[z][i][j] == '#') {
                    gz = Coord(i, j);
                    goto BRK;
                }
            }
        }
    BRK:
        for (int i = 0; i < R[z]; i++) {
            for (int j = 0; j < C[z]; j++) {
                if (blk[z][i][j] == '#') {
                    blks[z].emplace_back(i - gz.x, j - gz.y);
                }
            }
        }
        sort(blks[z].begin(), blks[z].end());
    }
    //sort(blks.begin(), blks.end());
    //blks.erase(unique(blks.begin(), blks.end()), blks.end());
}
bool CanPutDownBlks(int z, int x, int y) {
    for(int i=0; i<blks[z].size(); i++) {
        const Coord& co = blks[z][i];
        int nx = x+co.x;
        int ny = y+co.y;
        if(nx<0||ny<0||nx>=H||ny>=W) return false;
        if(m[nx][ny]=='#') return false;
    }
    return true;
}
void PutDownBlks(int z, int x, int y) {
    for(int i=0; i<blks[z].size(); i++) {
        const Coord& co = blks[z][i];
        m[x+co.x][y+co.y] = '#';
    }
    mcnt-=blkcnt;
}
void RestoreBlks(int z, int x, int y) {
    for(int i=0; i<blks[z].size(); i++) {
        const Coord& co = blks[z][i];
        m[x+co.x][y+co.y] = '.';
    }
    mcnt+=blkcnt;
}
int ans;
void dfs(int x, int y, int placed) {
    ans = max(ans, placed);

    if(x==H) return;
    if(y==W) {
        dfs(x+1,0,placed);
        return;
    }
    if(placed + mcnt/blkcnt <= ans) return;

    if (m[x][y] == '.') {
        for (int z = 0; z < blks.size(); z++) {
            if (!CanPutDownBlks(z, x, y)) continue;
            PutDownBlks(z, x, y);
            dfs(x, y + 1, placed+1);
            RestoreBlks(z, x, y);
        }
        m[x][y] = '#';
        mcnt--;
        dfs(x, y + 1, placed);
        m[x][y] = '.';
        mcnt++;
    }
    else dfs(x, y + 1, placed);
}
int main() {
    int tc; cin >> tc;
    while (tc--) {
        cin >> H >> W >> R[0] >> C[0];
        for (int i = 0; i < H; i++) {
            cin >> m[i];
        }
        for (int i = 0; i < R[0]; i++) {
            cin >> blk[0][i];
        }

        mcnt=0;
        for(int i=0; i<H; i++) {
            for(int j=0; j<W; j++) {
                if(m[i][j]=='.') mcnt++;
            }
        }

        for (int i = 1; i < 4; i++) {
            Rotate(i);
        }
        MakeBlksVector();

        blkcnt=blks[0].size();

        ans=0;
        dfs(0,0,0);
        printf("%d\n", ans);
    }
    return 0;
}