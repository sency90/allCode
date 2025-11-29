#include <bits/stdc++.h>
using namespace std;
const signed char LOSE = 0;
const signed char WIN = 1;
vector<string> board;
signed char dp[1<<25];
struct Coord{
    int x,y;
    Coord(){}
    Coord(int x, int y):x(x),y(y) {}
};
vector<vector<Coord>> blks = {
    {{0,1}},
    {{0,1},{1,1}},
    {{0,1},{1,0}},
    {{1,0}},
    {{1,0},{1,1}},
    {{1,0},{1,-1}}
};
bool CanPutDownBlk(int bit, int x, int y, int k) {
    for(int i=0; i<blks[k].size(); i++) {
        int nx = x+blks[k][i].x;
        int ny = y+blks[k][i].y;

        if(nx<0||ny<0||nx>=5||ny>=5) return false;
        if(bit & (1<<(nx*5+ny))) return false;
    }
    return true;
}
void TogBlk(int & bit, int x, int y, int k) {
    bit ^= (1<<(x*5+y));
    for(int i=0; i<blks[k].size(); i++) {
        int nx = x+blks[k][i].x;
        int ny = y+blks[k][i].y;
        bit ^= (1<<(nx*5+ny));
    }
}
signed char dfs(int bit, int cnt) {
    if(dp[bit]>=0) return dp[bit];
    else if(cnt<=1) return LOSE; //lose
    signed char & ret = dp[bit];

    signed char tmp;
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            if(bit&(1<<(i*5+j))) continue;
            for(int k=0; k<6; k++) {
                if(CanPutDownBlk(bit,i,j,k)) {
                    TogBlk(bit,i,j,k);
                    tmp = dfs(bit,cnt-blks[k].size());
                    TogBlk(bit,i,j,k);
                    if(tmp == LOSE) return ret=WIN;
                }
                else {
                    if(k==0) k=2;
                    else if(k==3) break;
                    else if(k==2) break;
                }
            }
        }
    }
    return ret=LOSE;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    board.resize(5);
    while(tc--) {
        memset(dp,-1,sizeof(dp));
        int cnt=0, bit=0;
        for(int i = 0; i < 5; i++) {
            cin >> board[i];
            for(int j = 0; j < 5; j++) {
                if(board[i][j] == '#') {
                    cnt++;
                    bit |= (1 << (i * 5 + j));
                }
            }
        }

        // State s{board, 0};
        if(dfs(bit, 25 - cnt) == WIN) puts("WINNING");
        else puts("LOSING");
    }
    return 0;
}