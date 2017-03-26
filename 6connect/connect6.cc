#include <cstdio>
#include <cassert>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <functional>
#include <set>
using namespace std;
#define BLOCKING 3
#define R 10
#define C 10
int board[R][C], prevBoard[R][C];
struct Coord{
    int x,y;
    Coord() {}
    Coord(int x, int y):x(x),y(y) {}
    bool operator<(const Coord &rhs) const {
        if(x==rhs.x) return y<rhs.y;
        else return x<rhs.x;
    }
};
typedef pair<int, Coord> pic;
set<Coord> hubo;

int ABS(int x) { return (x<0)?-x:x; }
Coord block[BLOCKING], rem[2];
priority_queue<pic, vector<pic>, greater<pic> > mnh;
int dx[]={-1,-1,0,1,1,1,0,-1}, dy[]={0,1,1,1,0,-1,-1,-1};
int memdif(int cnt, Coord *rem, Coord *block);
Coord dofirst();

void print() {
    printf("   ");
    for(int i=0; i<C; i++) { printf("%d",i%10); }
    puts("");
    for(int i=0; i<R; i++) {
        printf("%2d ",i);
        for(int j=0; j<C; j++) {
            if(board[i][j]==0) putchar('+');
            else if(board[i][j]==1) putchar('o');
            else if(board[i][j]==2) putchar('@');
            else putchar('#');
        } puts("");
    }
    puts("");
}
int showBoard(int x, int y) { return board[x][y]; }
void domyturn(int *x, int *y, int cnt) {
    assert(board[x[0]][y[0]]==0);
    board[x[0]][y[0]]=1;
    if(cnt==2) {
        assert(board[x[1]][y[1]]==0);
        board[x[1]][y[1]]=1;
    }
    //print();
}
void myturn(int cnt) {
    int x[2]={0,1},y[2]={0,1};
    if(memdif(cnt, rem, block)==1) {
        Coord co = dofirst();
        x[0]=co.x; y[0]=co.y;
    } else {
        puts("What to do?");
    }
    domyturn(x,y,cnt);
}

vector<int> v[100001];
int evaluate() {

}
int abpruning(int x, int d, int a, int b, int player, int cnt) {
    if(d==0 || v[x].size()==0) return evaluate(curstate);
    if(player) {
        for(int i=0; i<v[x].size(); i++) {
            if(cnt) a = max(a,abpruning(v[x][i],d-1,a,b,player,0));
            else a = max(a,abpruning(v[x][i],d-1,a,b,player^1,1));
            if(b<=a) return a;
        }
    } else {
        for(int i=0; i<v[x].size(); i++) {
            if(cnt) b = min(b,abpruning(v[x][i],d-1,a,b,player,0));
            else b = min(b,abpruning(v[x][i],d-1,a,b,player^1,1));
            if(b<=a) return b;
        }
    }
}
















void doCom(int x, int y) { board[x][y]=2; }
int isEnd() {
    int cnt[3], ans[3];
    memset(ans, 0, sizeof(ans));

    auto winchk = [&](int i, int j){
        if(board[i][j]==1) cnt[1]++, cnt[2]=0;
        else if(board[i][j]==2) cnt[2]++, cnt[1]=0;
        else cnt[1]=cnt[2]=0;

        for(int k=1; k<3; k++) {
            if(cnt[k]==6) ans[k]++;
            else if(cnt[k]==7) ans[k]--;
        }
    };

    for(int i=0; i<R; i++) {
        memset(cnt, 0, sizeof(cnt));
        for(int j=0; j<C; j++) winchk(i,j);
    } for(int k=1; k<3; k++) if(ans[k]>0) return k;

    for(int j=0; j<C; j++) {
        memset(cnt, 0, sizeof(cnt));
        for(int i=0; i<R; i++) winchk(i,j);
    } for(int k=1; k<3; k++) if(ans[k]>0) return k;

    for(int s=0; s<R; s++) {
        for(int i=0,j=s; j<C; i++,j++) winchk(i,j);
        if(s!=0) {
            for(int i=s,j=0; i<R; i++,j++) winchk(i,j);
        }
    } for(int k=1; k<3; k++) if(ans[k]>0) return k;
    return 0;
}
int main() {
    block[0] = Coord(2,3);
    block[1] = Coord(7,8);
    block[2] = Coord(9,6);
    for(int i=0; i<BLOCKING; i++) board[block[i].x][block[i].y]=3;
    myturn(1);
    print();

    int x,y,res=0;

    while(true) {
        //내가 직접 둔다.
        puts("ME: ");
        scanf("%d%d",&x,&y); doCom(x,y);
        scanf("%d%d",&x,&y); doCom(x,y);
        print();
        if(isEnd()) return 0&puts("WIN!!");

        //AI가 둔다.
        puts("AI: ");
        myturn(2); print();
        if(isEnd()) return 0&puts("LOSE!!");
    }
    printf("res: %d\n", res);

    return 0;
}

//두 점이 이루는 직선의 기울기가 0,1,-1,inf 이면 true 리턴.
bool linechk(Coord *co) {
    if(co[0].x==co[1].x && ABS(co[0].y-co[1].y)<=5) return true;
    else if(co[0].y==co[1].y && ABS(co[0].x-co[1].x)<=5) return true;
    else if(co[0].x-co[1].x == co[0].y-co[1].y) return true;
    else return false;
}

//이전 board와 다른 2개의 점을 rem[2]에 저장한다.
int memdif(int cnt, Coord *rem, Coord *block) {
    int idx=0;
    if(cnt == 1) {
        for(int i=0; i<R; i++) {
            for(int j=0; j<C; j++) {
                prevBoard[i][j] = board[i][j];
                if(board[i][j]==3) block[idx++]=Coord(i,j);
            }
        }
    } else {
        for(int i=0; i<R; i++) {
            for(int j=0; j<C; j++) {
                if(prevBoard[i][j] != board[i][j]) {
                    rem[idx++]=Coord(i,j);
                    if(idx==2) return cnt;
                }
            }
        }
    }
    return cnt;
}

int tBoard[R][C];
void tBoardPrint() {
    printf("   ");
    for(int i=0; i<C; i++) { printf("%d",i%10); }
    puts("");
    for(int i=0; i<R; i++) {
        printf("%2d ",i);
        for(int j=0; j<C; j++) {
            printf("%d", tBoard[i][j]);
        } puts("");
    }
    puts("");
}

bool outOfRange(int x, int y) { return !(x>=0 && y>=0 && x<R && y<C); }

//처음 놓는 지점을 blocking지점과 멀리 떨어진 곳에 둔다.
Coord dofirst() {
    bool chk[R][C];
    memset(chk, false, sizeof(chk));
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            tBoard[i][j]=min({i,j,R-1-i,C-1-j})+1;
        }
    }
    for(int i=0; i<BLOCKING; i++) {
        chk[block[i].x][block[i].y]=true;
        mnh.push(pic(0,block[i]));
        tBoard[block[i].x][block[i].y]=0;
    }

    while(!mnh.empty()) {
        pic info = mnh.top(); mnh.pop();
        for(int i=0; i<8; i++) {
            int nx=info.second.x+dx[i], ny=info.second.y+dy[i];
            //printf("%d %d\n", nx,ny);
            if(outOfRange(nx,ny)) continue;
            else {
                //chk[nx][ny]=true;
                if(tBoard[nx][ny]>info.first+1) {
                    tBoard[nx][ny]=info.first+1;
                    mnh.push(pic(info.first+1, Coord(nx,ny)));
                }
            }
        }
    }
    int mx=0;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            mx = max(mx, tBoard[i][j]);
        }
    }
    tBoardPrint();

    vector<Coord> v;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            if(tBoard[i][j]==mx) v.push_back(Coord(i,j));
        }
    }
    int cnt=0;
    function<void(int,int)> dfs = [&](int x, int y) {
        cnt++;
        chk[x][y]=true;
        for(int i=0; i<8; i+=2) {
            int nx=x+dx[i], ny=y+dy[i];
            if(outOfRange(nx,ny)) continue;
            if(chk[nx][ny]) continue;
            else chk[nx][ny]=true;
            if(tBoard[nx][ny]==mx) dfs(nx,ny);
        }

    };
    int mxcnt=0;
    Coord mxCo(0,0);
    for(int i=0; i<v.size(); i++) {
        if(chk[v[i].x][v[i].y]) continue;
        cnt=0;
        dfs(v[i].x, v[i].y);
        if(mxcnt < cnt) {
            mxcnt=cnt;
            mxCo = v[i];
        }
    }

    return mxCo;
}
