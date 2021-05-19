#include <iostream>
#include <stdio.h>
#include <queue>
#include <cctype>
#include <vector>
using namespace std;
vector<pair<int,int> > v;
char map[52][52];
bool check[52][52][1 << 7];
int mov[2][4] = { {0, 0, -1, 1}, {-1, 1, 0, 0} };
int M = 0x3f3f3f3f;
struct Point {
    int x, y, mask, cnt;
    Point (int xx, int yy, int key, int c) {
        x=xx;y=yy;mask=key;cnt=c;
    }
};
queue<Point> q;
int main() {
    int n, m; scanf("%d%d", &n, &m);
    Point start_p(0,0,0,0);
    for (int i = 0; i < n; i++) {
        scanf("%s", map[i]);
        for (int j = 0; j < m; j++) {
            if (map[i][j] == '0') {
                start_p = Point(i, j, 0, 0);
            } else if(map[i][j]=='1') {
                v.push_back(make_pair(i,j));
            }
        }
    }

    bool good = false;
    check[start_p.x][start_p.y][0] = true;
    q.push(start_p);
    while (!q.empty()) {
        Point p = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = p.x + mov[0][i];
            int ny = p.y + mov[1][i];
            int nmask = p.mask;
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || map[nx][ny]=='#') continue;
            if (islower(map[nx][ny])) nmask |= (1 << (map[nx][ny]-'a')); //해당 키를 업뎃해
            else if(isupper(map[nx][ny])) {
                if((nmask & (1 << (map[nx][ny]-'A'))) == 0) continue; //해당 키를 가지고 있지 않으면 꺼져~!
            }
            if(check[nx][ny][nmask]) continue; //처음에 마스크 씌운 애만 고려해주면 되잖앙... 그니까 check[nx][ny][p.mask]는 고려할 필요가 없음. 아니 해서는 안됨!
            check[nx][ny][nmask] = true;
            for(int j=0; j<v.size(); j++) {
                if(nx==v[j].first && ny==v[j].second) {
                    M = p.cnt+1;
                    good = true;
                    break;
                }
            }

            if(good) break;
            q.push(Point(nx,ny,nmask,p.cnt+1));
        }
        if(good) break;
    }
    if(!good) printf("-1\n");
    else printf("%d\n", M);
}
