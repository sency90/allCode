#include <cstdio>
using namespace std;
int n, l, r;
int v[51][51];
int chk[51][51];
int CHKVAL;
int g[51][51];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
struct Info{
    int sum, cnt;
    Info():sum(0),cnt(0) {}
    Info(int sum, int cnt):sum(sum),cnt(cnt) {}
    Info & operator+=(const Info & rhs) {
        this->sum += rhs.sum;
        this->cnt += rhs.cnt;
        return *this;
    }
};
struct Coord{
    int x,y;
};
Coord co_list[2501];
int co_N;
inline int ABS(int x) { return x<0?-x:x; }
Info dfs(int x, int y, int gno) {
    chk[x][y] = CHKVAL;
    g[x][y] = gno;
    Info ret(v[x][y], 1);
    co_list[co_N++] = {x,y};
    for(int i=0; i<4; i++) {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<0||ny<0||nx>=n||ny>=n) continue;
        int diff = ABS(v[nx][ny]-v[x][y]);
        if(chk[nx][ny] == CHKVAL) continue;
        if (l <= diff && diff <= r) {
            ret += dfs(x, y, gno);
        }
    }
    return ret;
}
int main() {
    #ifdef _WIN32
    freopen("C:\\Users\\User\\Documents\\allCode\\samsung_codingtest\\in", "r", stdin);
    #endif
    scanf("%d%d%d",&n,&l,&r);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &v[i][j]);
        }
    }

    int z=1;
    for(; z<=2000; z++) {
        int gno=0;
        CHKVAL++;
        Info info;
        bool has_changed = false;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(chk[i][j] == CHKVAL) continue;
                co_N=0;
                info = dfs(i,j,++gno);
                if (info.cnt > 1) {
                    has_changed = true;
                    int val = info.sum / info.cnt;
                    for (int k = 0; k < co_N; k++) {
                        v[co_list[k].x][co_list[k].y] = val;
                    }
                }
            }
        }
        if(!has_changed) break;
    }
    printf("%d\n", z);
    return 0;
}