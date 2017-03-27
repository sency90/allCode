/*지워야 하는 부분*/
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <queue>
#include <cassert>
#include <cstring>
#include <string>
using namespace std;
int board[19][19];
int main() { return 0; }
int showBoard(int x, int y) { return board[x][y]; }
void domyturn(int *x, int *y, int cnt) {}
void domymove(int *x, int *y, int cnt) {}
/////////////////////////////////////-----------절 대 지 워 서 는 안 됨 ! ! !-------------///////////////////////////

const int inf=0x3f3f3f3f;
const int R=19;
struct Co{
    int x,y;
    Co(){} Co(int x, int y):x(x),y(y) {}
    bool operator<(const Co &rhs) const {
        if(x==rhs.x) return y<rhs.y;
        else return x<rhs.x;
    }
};
typedef pair<int, Co> pic;
typedef pair<Co, Co> pcc;
typedef pair<int, pcc> picc;
vector<Co> lastco, block;
int dx[]={-1,-1,0,1,1,1,0,-1}, dy[]={0,1,1,1,0,-1,-1,-1};
int dir[]={0,2,4,8};
int prevBoard[R][R], tmpBoard[R][R];
bool chk[R][R];

int evaluate();
bool hasWon();
void genMoves(vector<pcc> &nextMoves);
void initBoard(vector<Co> &block);
int updateBoard();
Co dofirst(vector<Co> &block);

picc abpruning(int d, int a, int b, int player) {
    vector<pcc> nextMoves;
    genMoves(nextMoves);
    pcc retcc(pcc(Co(0,0),Co(0,0)));

    int score=0;
    if(d==0 || nextMoves.size()==0) score=evaluate();
    else {
        for(pcc &cc: nextMoves) {
            if(player) {
                tmpBoard[cc.first.x][cc.first.y] = tmpBoard[cc.second.x][cc.second.y] = 1;
                picc rcv = abpruning(d-1,a,b,player^1);
                if(a<rcv.first) {
                    a=rcv.first;
                    retcc=cc;
                }
                tmpBoard[cc.first.x][cc.first.y] = tmpBoard[cc.second.x][cc.second.y] = 0;
                if(b<=a) return picc(a,retcc);
            } else {
                tmpBoard[cc.first.x][cc.first.y] = tmpBoard[cc.second.x][cc.second.y] = 2;
                picc rcv = abpruning(d-1,a,b,player^1);
                if(b>rcv.first) {
                    b=rcv.first;
                    retcc=cc;
                }
                tmpBoard[cc.first.x][cc.first.y] = tmpBoard[cc.second.x][cc.second.y] = 0;
                if(b<=a) return picc(b,retcc);
            }
        }
    }
    return picc(score, retcc);
}

void myturn(int cnt) {
    int x[2], y[2];

    if(cnt==1) {
        vector<Co> block;
        initBoard(block);
        Co co = dofirst(block);
        x[0]=co.x; y[0]=co.y;
    } else {
        updateBoard(); //tmpBoard와 prevBoard가 갱신된다.
        picc rcv = abpruning(4,-inf,inf,1);

        int score = rcv.first;
        pcc cc = rcv.second;
        x[0]=cc.first.x; y[0]=cc.first.y;
        x[1]=cc.second.x; y[1]=cc.second.y;
    }
    domymove(x,y,cnt);
}






//-------------------------------------------------for evaluating score---------------------------------------

int evaluate() {
    int score = 0;
    for(int i=0; i<R; i++) {
        for(int j=0; j<R; j++) {

        }
    }
}

int kmp(const string &H, int nidx) {
}
//-----------------------------------------------------------------------------------------------------------




bool hasWon() {
    int sz=lastco.size(), bgn=max(sz-2,0);
    for(int i=bgn; i<sz; i++) { //마지막에 둔 2개의 돌
        int x=lastco[i].x, y=lastco[i].y;

        int cnt=0;
        for(int i=x; i>=max(x-6,0); i--) {
            if(showBoard(i,y) == 1) cnt++;
            else break;
        }
        for(int i=x+1; i<=min(x+6,R-1); i++) {
            if(showBoard(i,y) == 1) cnt++;
            else break;
        }
        if(cnt==6) return true;

        cnt=0;
        for(int i=y; i>=max(y-6,0); i--) {
            if(showBoard(x,i) == 1) cnt++;
            else break;
        }
        for(int i=y+1; i<=min(y+6,R-1); i++) {
            if(showBoard(x,i) == 1) cnt++;
            else break;
        }
        if(cnt==6) return true;

        cnt=0;
        for(int i=x,j=y; i>=max(x-6,0) && j>=max(y-6,0); i--,j--) {
            if(showBoard(i,j) == 1) cnt++;
            else break;
        }
        for(int i=x+1,j=y+1; i<=min(x+6,0) && j<=min(y+6,0); i++,j++) {
            if(showBoard(i,j) == 1) cnt++;
            else break;
        }
        if(cnt==6) return true;

        cnt=0;
        for(int i=x,j=y; i>=max(x-6,0) && j<=min(y+6,0); i--,j++) {
            if(showBoard(i,j) == 1) cnt++;
            else break;
        }
        for(int i=x+1,j=y+1; i<=min(x+6,0) && j>=max(y-6,0); i++,j--) {
            if(showBoard(i,j) == 1) cnt++;
            else break;
        }
        if(cnt==6) return true;
    }
    return false;
}

void genMoves(vector<pcc> &nextMoves) {
    if(hasWon()) return;
    else {
        memset(chk,false,sizeof(chk));
        vector<Co> tmp; tmp.clear();
        int sz=lastco.size(), bgn=max(sz-2,0);
        for(int i=bgn; i<sz; i++) {
            int x=lastco[i].x, y=lastco[i].y;

            for(int len=1; len<3; len++) {
                for(int k=0; k<8; k++) {
                    int nx=x+len*dx[k], ny=y+len*dy[k];
                    if(chk[nx][ny]) continue;
                    chk[nx][ny]=true;
                    if(tmpBoard[nx][ny] == 0) tmp.emplace_back(Co(nx,ny));
                    //if(showBoard(nx,ny) == 0) tmp.emplace_back(Co(nx,ny));
                }
            }
        }
        for(int i=0; i<tmp.size(); i++) {
            for(int j=i+1; j<tmp.size(); j++) {
                nextMoves.emplace_back(pcc(tmp[i], tmp[j]));
            }
        }
    }
}

int updateBoard() {
    int cnt=0;
    for(int i=0; i<R; i++) {
        for(int j=0; j<R; j++) {
            if(prevBoard[i][j]!=showBoard(i,j)) {
                prevBoard[i][j]=tmpBoard[i][j]=showBoard(i,j);
                cnt++;
            }
        }
    }
    return cnt;
}

void initBoard(vector<Co> &block) {
    for(int i=0; i<R; i++) {
        for(int j=0; j<R; j++) {
            if(showBoard(i,j)==3) block.emplace_back(Co(i,j));
            prevBoard[i][j]=tmpBoard[i][j]=showBoard(i,j);
        }
    }
}

Co dofirst(vector<Co> &block) {
    priority_queue<pic, vector<pic>, greater<pic>> mnh;
    int tBoard[R][R];
    memset(tBoard, 0, sizeof(tBoard));

    for(int i=0; i<R; i++) {
        for(int j=0; j<R; j++) {
            tBoard[i][j] = min(i,min(j,min(R-1-i,R-1-j)))+1;
        }
    }
    for(auto &p: block) {
        tBoard[p.x][p.y]=0;
        mnh.push(pic(0,p));
    }
    auto outOfRange = [](int nx, int ny) { return (nx>=0 && ny>=0 && nx<R && ny<R); };
    while(!mnh.empty()) {
        pic info = mnh.top(); mnh.pop();
        for(int i=0; i<R; i++) {
            int nx=info.second.x+dx[i],ny=info.second.y+dy[i];
            if(outOfRange(nx,ny)) continue;
            else {
                if(tBoard[nx][ny] > info.first+1) {
                    tBoard[nx][ny] = info.first+1;
                    mnh.push(pic(info.first+1, Co(nx,ny)));
                }
            }
        }
    }
    int mx=0,cnt=0,mxcnt=0;
    for(int i=0; i<R; i++) {
        for(int j=0; j<R; j++) {
            mx = max(mx,tBoard[i][j]);
        }
    }

    vector<Co> v;
    Co ret(0,0);
    for(int i=0; i<R; i++) {
        for(int j=0; j<R; j++) {
            if(tBoard[i][j]==mx) v.emplace_back(Co(i,j));
        }
    }

    memset(chk,false,sizeof(chk));
    function<void(int,int)> dfs = [&](int x, int y) {
        chk[x][y]=true;
        for(int i=0; i<8; i+=2) {
            int nx=x+dx[i], ny=y+dy[i];
            if(outOfRange(nx,ny) || chk[nx][ny]) continue;
            chk[nx][ny]=true;
            if(tBoard[nx][ny]==mx) dfs(nx,ny);
        }
    };

    for(int i=0; i<v.size(); i++) {
        if(chk[v[i].x][v[i].y]) continue;
        cnt=0;
        dfs(v[i].x, v[i].y);
        if(mxcnt < cnt) {
            mxcnt = cnt;
            ret = v[i];
        }
    }
    return ret;
}
