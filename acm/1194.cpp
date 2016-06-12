//실수하지 말아야 하는 부분
//nkey를 반드시 선언해서 p.key를 대입해서 써줘야 함.
//그렇지 않으면 나중에 queue에서 꺼낸 p.key가 변질되어 있기 때문에 문제가 된다.
//그리고 bfs이므로 cnt의 최소를 계속해서 구해나갈 필요가 없다.
//즉, map[p.x][p.y]=='1'인 지점을 bfs를 돌다가 보았다면, 그곳에서의 p.cnt가 바로 답이 된다.
#include <cstdio>
#include <cctype>
#include <queue>
using namespace std;
char map[50][51];
bool chk[50][50][1<<6];
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
struct Coord{
    int x, y, key, cnt;
    Coord(int _x, int _y, int _key, int _cnt) {
        x=_x; y=_y; key=_key; cnt=_cnt;
    }
};
queue<Coord> q;
int main() {
    int n, m, sx, sy;
    bool hStart = false;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++) {
        scanf("%s", map[i]);
        if(!hStart) {
            for(int j=0; j<m; j++) {
                if(map[i][j]=='0') {
                    sx = i; sy = j;
                    hStart = true;
                }
            }
        }
    }

    int nx,ny,nkey;
    Coord p(sx,sy,0,0);
    chk[sx][sy][0] = true;
    q.push(p);
    while(!q.empty()) {
        p=q.front(); q.pop();
        if(map[p.x][p.y]=='1') {
            printf("%d", p.cnt);
            return 0;
        }
        for(int i=0; i<4; i++) {
            nx = p.x + dx[i]; ny = p.y + dy[i]; nkey = p.key;
            if(nx<0 || ny<0 || nx>=n || ny>=m || map[nx][ny]=='#') continue;
            if(islower(map[nx][ny])) nkey |= ( 1 << (map[nx][ny]-'a') );
            else if(isupper(map[nx][ny])) {
                if((nkey & (1 << (map[nx][ny]-'A'))) == 0) continue;
            }
            if(chk[nx][ny][nkey]) continue;
            chk[nx][ny][nkey] = true;
            q.push(Coord(nx, ny, nkey, p.cnt+1));
        }
    }
    puts("-1");
    return 0;
}
