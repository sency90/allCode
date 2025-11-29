#include <bits/stdc++.h>
using namespace std;
vector<string> board;
struct Coord{
    int x,y;
};
bool IsWin(vector<string> & b, char player) {
    for(int i=0; i<3; i++) {
        int cnt=0;
        for(int j=0; j<3; j++) {
            if(b[i][j]==player) {
                cnt++;
            }
            else break;
        }
        if(cnt==3) return true;
    }
    for(int j=0; j<3; j++) {
        int cnt=0;
        for(int i=0; i<3; i++) {
            if(b[i][j]==player) {
                cnt++;
            }
            else break;
        }
        if(cnt==3) return true;
    }

    static const Coord co[2][3] = {
        {{0, 0}, {1, 1}, {2, 2}},
        {{0, 2}, {1, 1}, {2, 0}}
    };

    for(int i=0; i<2; i++) {
        int cnt=0;
        for(int j=0; j<3; j++) {
            if(b[co[i][j].x][co[i][j].y] == player) cnt++;
            else break;
        }
        if(cnt==3) return true;
    }

    return false;
}
const int LOSE = -1;
const int TIE = 0;
const int WIN = 1;
map<vector<string>, int> dp;
int go(char p, vector<string> & b) {
    if(dp.count(b)) return dp[b];
    else {
        if(IsWin(b, 'x'+'o'-p)) {
            return dp[b] = LOSE;
        }
    }

    int & ret = dp[b];
    ret = 2;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(b[i][j]=='.') {
                b[i][j]=p;
                ret = min(ret, go('x'+'o'-p, b));
                b[i][j]='.';
            }
        }
    }
    if(ret==2 || ret==0) return ret=TIE;
    return ret*=-1;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tc; cin >> tc;
    while(tc--) {
        board.clear();
        board.resize(3);
        dp.clear();
        for(int i=0; i<3; i++) {
            cin >> board[i];
        }
        int xcnt=0, ocnt=0;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(board[i][j] == 'x') xcnt++;
                else if(board[i][j] == 'o') ocnt++;
            }
        }
        char player;
        if(xcnt == ocnt) player='x';
        else player='o';

        int res = go(player, board);
        if(res==WIN) printf("%c\n", player);
        else if(res==LOSE) printf("%c\n", 'x'+'o'-player);
        else puts("TIE");
    }
    return 0;
}