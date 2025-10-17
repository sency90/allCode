#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;
string board[5];
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

struct Coord {
    int x, y;
    Coord() {}
    Coord(int x, int y) : x(x), y(y) {}
    bool operator<(const Coord& rhs) const {
        if (x == rhs.x)
            return y < rhs.y;
        else
            return x < rhs.x;
    }
};

unordered_map<string, Coord> udic;
string s[11];
set<string> str_set[11][5][5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            str_set[0][i][j].clear();
            str_set[0][i][j].insert("");
        }
    }

    while (tc--) {
        //init
        for(int len=1; len<=10; len++) {
            for(int i=0; i<5; i++) {
                for(int j=0; j<5; j++) {
                    str_set[len][i][j].clear();
                }
            }
        }
        udic.clear();

        //input
        for (int i = 0; i < 5; i++) {
            cin >> board[i];
        }

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> s[i];
        }

        string sub_str;
        for (int len = 1; len <= 10; len++) {
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    for (int a = 0; a < N; a++) {
                        if (s[a].size() < len) continue;
                        if (s[a][len-1] != board[i][j]) continue;
                        sub_str.clear();
                        if(len>1) sub_str = s[a].substr(0,len-1);

                        for (int k = 0; k < 8; k++) {
                            int pi = i + dx[k];
                            int pj = j + dy[k];
                            if (pi < 0 || pj < 0 || pi >= 5 || pj >= 5) continue;
                            if(str_set[len-1][pi][pj].count(sub_str)) {
                                str_set[len][i][j].insert(sub_str+string(1,board[i][j]));
                                udic[sub_str+string(1,board[i][j])] = Coord(i,j);
                            }
                        }
                    }
                }
            }
        }

        for (int i = 0; i < N; i++) {
            printf("%s ", s[i].c_str());
            if (udic.count(s[i]))
                puts("YES");
            else
                puts("NO");
        }
    }
    return 0;
}