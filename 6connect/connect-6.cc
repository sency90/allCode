// Samsung Go Tournament Form C (g++-4.8.3)
/*[AI 코드 작성 방법]

  1. char info[]의 배열 안에 "TeamName:자신의 팀명,Department:자신의 소속" 순서로 작성합니다.
  ( 주의 ) Teamname:과 Department:는 꼭 들어가야 합니다.
  "자신의 팀명", "자신의 소속"을 수정해야 합니다.

  2. 아래의 myturn() 함수 안에 자신만의 AI 코드를 작성합니다.
  3. AI 파일을 테스트 하실 때는 "육목 알고리즘대회 툴"을 사용합니다.
  4. 육목 알고리즘 대회 툴의 연습하기에서 바둑돌을 누른 후, 자신의 "팀명" 이 들어간 알고리즘을 추가하여 테스트 합니다.
  [변수 및 함수]myturn(int cnt) : 자신의 AI 코드를 작성하는 메인 함수 입니다.

  int cnt (myturn()함수의 파라미터) : 돌을 몇 수 둬야하는지 정하는 변수,
  cnt가 1이면 육목 시작 시 한 번만  두는 상황(한 번),
  cnt가 2이면 그 이후 돌을 두는 상황(두 번)int  x[0], y[0] : 자신이 둘 첫 번 째 돌의 x좌표 , y좌표가 저장되어야 합니다.
  int  x[1], y[1] : 자신이 둘 두 번 째 돌의 x좌표 , y좌표가 저장되어야 합니다.
  void domymove(int x[], int y[], cnt) : 둘 돌들의 좌표를 저장해서 출력

//int board[BOARD_SIZE][BOARD_SIZE]; 바둑판 현재상황 담고 있어 바로사용 가능함.
단, 원본데이터로 수정 절대금지

// 놓을수 없는 위치에 바둑돌을 놓으면 실격패 처리.
boolean ifFree(int x, int y) : 현재 [x,y]좌표에 바둑돌이 있는지 확인하는 함수 (없으면 true, 있으면 false)
boolean isBlock(int x, int y): 현재 [x,y] 좌표의 블럭킹이 존재하는지 보여주는 함수 (true = 존재)
int showBoard(int x, int y) : [x, y] 좌표에 무슨 돌이 존재하는지 보여주는 함수 (1 = 자신의 돌, 2 = 상대의 돌, 3 = 블럭킹)

<-------AI를 작성하실 때, 같은 이름의 함수 및 변수 사용을 권장하지 않습니다----->*/

#include <algorithm>
#include <cstring>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <memory>
#include <stdio.h>
//#include <Windows.h>
#include <time.h>
//#include "Connect6Algo.h"
using namespace std;

#define L 19
#define BLOCKLIM 30
#define VNSZ 28

// "샘플코드[C]"  -> 자신의 팀명 (수정)
// "AI부서[C]"  -> 자신의 소속 (수정)
// 제출시 실행파일은 반드시 팀명으로 제출!
//global variable
struct Coord{
    int x,y;
    Coord(){} Coord(int x,int y):x(x),y(y){}
    bool operator<(const Coord &rhs) const {
        if(x==rhs.x) return y<rhs.y;
        else return x<rhs.x;
    }
    bool operator==(const Coord &rhs) const { return (x==rhs.x && y==rhs.y); }
};
class Log{
public:
    vector<Coord> co;
    void push(Coord t) { co.emplace_back(t); }
    Coord get(int idx) {
        int lastidx = co.size()-1;
        if(lastidx-idx<0) return Coord(-1,-1);
        else return co[lastidx-idx];
    }
    void del(int cnt) {
        for(int i=0; i<cnt; i++) {
            int lastidx = co.size()-1;
            if(lastidx<0) return;
            co.erase(co.begin()+lastidx, co.end());
        }
    }
};

typedef pair<int, Coord> pic;
typedef pair<int, string> pis;
char info[] ={"TeamName:샘플코드[C],Department:AI부서[C]"};
int prevBoard[L][L];
int blocking=0;
bool isFirst=true;
Coord remCo[BLOCKLIM];
int dx[]={-1,-1,0,1,1,1,0,-1}, dy[]={0,1,1,1,0,-1,-1,-1};
set<Coord> s;
map<int, int> mp;
string N[]={"111111","0111110","010111010","100111010","100111001","00111100","111110","111101","111011","1111001","1110011","1110101","1101101","1011101","1101011","111100","111001","110011","110101","101101","00111000","00110100","010110000","100110000","010011000","010101000","111000","1111111"}; //마지막 스트링은 7목
int score[VNSZ]={100000000, 471125, 178408, 968445,136975, 958631, 224804, 745729, 146434, 653420, 406632, 732847, 835834, 180915, 170667, 965425, 294247, 308961, 296802, 919855, 916206, 378982, 262479, 771643, 28720, 437413, 625778, 100}; //마지막 점수는 7목
vector<pis> vn;
vector<vector<int>> pi(VNSZ, vector<int>());
Log lg;

const int inf = 0x3f3f3f3f;
vector<Coord> vco;

//functions
int memdif(int &blocking);
Coord dofirst(int *x,int *y,int cnt);
int abpruning(int x,int d,int a,int b,int player,int cnt);
void initString() {
    for(int i=0; i<27; i++) {
        vn.emplace_back(pis(score[i],N[i]));
        reverse(N[i].begin(),N[i].end());
        vn.emplace_back(pis(score[i],N[i]));
    }
    auto cmp = [](const pis &lhs,const pis &rhs) { return lhs.first > rhs.first; };
    sort(vn.begin(),vn.end(),cmp);
    vn.erase(unique(vn.begin(),vn.end()),vn.end());
    for(int z=0; z<vn.size(); z++) {
        pi[z].resize(vn[z].second.size(),0);
        for(int i=1,matched=0; i<vn[z].second.size(); i++) {
            while(matched!=0 && N[i]!=N[matched]) matched=pi[z][matched-1];
            if(N[i]==N[matched]) {
                matched++;
                pi[z][i]=matched;
            }
        }
    }
}

void makevco(vector<Coord> &vco,int prvcnt) {
    for(int z=prvcnt-1; z>=0; z--) {
        //Coord tco=lg.get(z);
        int x=tco.x,y=tco.y;
        int sx=max(x-8,0),ex=min(x+8,L),sy,ey;
        for(int i=sx; i<=ex; i++) {
            if(showBoard(i,y)==0) vco.emplace_back(Coord(i,y));
        }
        sx=max(x-8,0),ex=min(x+8,L),sy=min(y+8,0),ey=max(y-8,L);
        for(int i=sx,j=sy; i<=ex&&j>=ey; i++,j--) {
            if(showBoard(i,j)==0) vco.emplace_back(Coord(i,y));
        }
        sy=max(y-8,0),ey=min(y+8,L);
        for(int i=sy; i<=ey; i++) {
            if(showBoard(x,i)==0) vco.emplace_back(Coord(x,i));
        }
        sx=max(x-8,0),ex=min(x+8,L),sy=max(y-8,L),ey=min(y+8,0);
        for(int i=sx,j=sy; i<=ex&&j<=ey; i++,j++) {
            if(showBoard(i,j)==0) vco.emplace_back(Coord(i,j));
        }
    }
    sort(vco.begin(),vco.end());
    vco.erase(unique(vco.begin(),vco.end()),vco.end());
}

int idx=0;
void myturn(int cnt) {
    int x[2],y[2];

    // 이 부분에서 알고리즘 프로그램(AI)을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하시면 됩니다.
    // 현재 Sample code의 AI는 Random으로 돌을 놓는 Algorithm이 작성되어 있습니다.

    if(isFirst) {
        initString();
        cntblocking(blocking);
        isFirst=false;
        if(cnt==1) {
            //최대한 blocking을 피해서 놓도록 코딩
            Coord tmp = dofirst(x,y,cnt);
            x[0]=tmp.x; y[0]=tmp.y;
            domymove(x,y,cnt);
            prevBoard[x[0]][y[0]]=1;
            lg.push(Coord(x[0],y[0]));
            return;
        }
    }

    //상대방이 둔 돌의 좌표를 remCo변수에 담는다.
    int prvcnt = memdif(blocking);
    abpruning(4,-inf,inf,1,1);

    //지금까지 돌이 두어진 순서를 lg에 기록한다.
    //for(int i=0; i<prvcnt; i++) lg.push(remCo[i]);
    //makevco(vco,prvcnt);
    abpruning(4,-inf,inf,1,1,idx);
    if(prvcnt==1) {
    } else { // if(prvcnt==2) }


    // 이 부분에서 자신이 놓을 돌을 출력하십시오.
    // 필수 함수 : domymove(x배열,y배열,배열크기)
    // 여기서 배열크기(cnt)는 myturn()의 파라미터 cnt를 그대로 넣어야합니다.
    domymove(x,y,cnt);
}

int search(int x,int y,int dir) {
    string str="";
    if(dir==0) {
        int sx=max(x-8,0),ex=min(x+8,L);
        for(int i=x; i>=sx; i--) {
            int val=showBoard(i,y);
            if(val>=2) break;
            str=char('0'+val)+str;
        }
        for(int i=x+1; i<=ex; i++) {
            int val=showBoard(i,y);
            if(val>=2) break;
            str+=char('0'+val);
        }
    } else if(dir==1) {
        int sx=max(x-8,0),ex=min(x+8,L),sy=min(y+8,0),ey=max(y-8,L);
        for(int i=x,j=y; i>=sx && j<=ey; i--,j++) {
            int val=showBoard(i,j);
            if(val>=2) break;
            str=char('0'+val)+str;
        }
        for(int i=x+1,j=y-1; i<=ex && j>=sy; i++,j--) {
            int val=showBoard(i,j);
            if(val>=2) break;
            str+=char('0'+val);
        }
    }
    else if(dir==2) {
        int sy=max(y-8,0),ey=min(y+8,L);
        for(int i=y; i>=sy; i--) {
            int val=showBoard(x,i);
            if(val>=2) break;
            str=char('0'+val)+str;
        }
        for(int i=y+1; i<=ey; i++) {
            int val=showBoard(x,i);
            if(val>=2) break;
            str+=char('0'+val);
        }
    } else {
        int sx=max(x-8,0),ex=min(x+8,L),sy=max(y-8,L),ey=min(y+8,0);
        for(int i=x,j=y; i>=sx && j>=sy; i--,j--) {
            int val=showBoard(i,j);
            if(val>=2) break;
            str=char('0'+val)+str;
        }
        for(int i=x+1,j=y+1; i<=ex && j<=ey; i++,j++) {
            int val=showBoard(i,j);
            if(val>=2) break;
            str+=char('0'+val);
        }
    }
    int sidx=-1,scr=0,len=0;
    for(int i=0; i<VNSZ-1; i++) {
        sidx=kmp(str,i);
        if(sidx!=-1) {
            len=vn[i].second.size();
            scr=vn[i].first;
            break;
        }
    }
    if(scr==0) {
        bool everStart=false;
        int bn=0,en=0;
        for(int i=0; i<str.size(); i++) {
            if(str[i]=='1' && !everStart) {
                everStart=true;
                bn=i;
            } else if(str[i]=='1') {
                en=i;
            }
        }
        len=en-bn+1;

        //7개씩 봐야함... 다시 짜야해
        auto chglenscr = [](int len)->int{
            if(len<=7) {
                if(len==1) return 2;
                else if(len==2) return 139;
                else if(len==3) return 10321;
                else if(len==4) return 65651;
                else if(len==5) return 100621;
                else if(len==6) return 741071;
                else return 100;
            } else {
                return 1000;
            }
        }
        scr = chglenscr(len);
    }
    return scr;
}

int evaluate(int x,int y) {
    for(int dir=0; dir<4; dir++) {
        search(x,y,dir);
    }
}
int abpruning(int d,int a,int b,int player,int cnt,int idx) {
    int x=vco[idx].x,y=vco[idx].y;
    if(d==0) {
        vector<Coord> hubo;
        makevco(hubo,2);
        hubo.emplace_back();
        return evaluate(x,y);
    }

    if(player) {
        for(int i=0; i<v[x].size(); i++) {
            if(cnt) a = max(a,abpruning(d-1,a,b,player,0,idx+1));
            else a = max(a,abpruning(d-1,a,b,player^1,1,idx+1));
            if(b<=a) return a;
        }
    } else {
        for(int i=0; i<v[x].size(); i++) {
            if(cnt) b = min(b,abpruning(d-1,a,b,player,0,idx+1));
            else b = min(b,abpruning(d-1,a,b,player^1,1,idx+1));
            if(b<=a) return b;
        }
    }
}

void cntblocking(int &blocking) {
    for(int i=0; i<L; i++) {
        for(int j=0; j<L; j++) {
            if((prevBoard[i][j]=showBoard(i,j))==3) blocking++;
        }
    }
}

int memdif(int &blocking) {
    int idx=0;
    for(int i=0; i<L; i++) {
        for(int j=0; j<L; j++) {
            if(prevBoard[i][j]!=showBoard(i,j)) {
                prevBoard[i][j]=showBoard(i,j);
                vco.emplace_back(Coord(i,j));
                //remCo[idx++]=Coord(i,j);
            }
        }
    }
    return idx;
}

Coord dofirst(int *x,int *y,int cnt) {
    priority_queue<pic,vector<pic>,greater<pic>> mnh;
    int tBoard[L][L];
    memset(tBoard,0,sizeof(tBoard));
    for(int i=0; i<L; i++) {
        for(int j=0; j<L; j++) {
            tBoard[i][j]=min(i,min(j,min(L-1-i,L-1-j)))+1;
            if(showBoard(i,j)==3) {
                tBoard[i][j]=0;
                mnh.push(pic(0,Coord(i,j)));
            }
        }
    }

    auto outOfRange = [](int nx,int ny) {
        return (nx>=0 && ny>=0 && nx<L && ny<L);
    };

    while(!mnh.empty()) {
        pic info = mnh.top();
        mnh.pop();
        for(int i=0; i<L; i++) {
            int nx=info.second.x+dx[i],ny=info.second.y+dy[i];
            if(outOfRange(nx,ny)) continue;
            else {
                if(tBoard[nx][ny]>info.first+1) {
                    tBoard[nx][ny]=info.first+1;
                    mnh.push(pic(info.first+1,Coord(nx,ny)));
                }
            }
        }
    }
    int mx=0;
    for(int i=0; i<L; i++) {
        for(int j=0; j<L; j++) {
            mx = max(mx,tBoard[i][j]);
        }
    }

    vector<Coord> v;
    for(int i=0; i<L; i++) {
        for(int j=0; j<L; j++) {
            if(tBoard[i][j]==mx) v.push_back(Coord(i,j));
        }
    }

    int cnt=0;
    bool chk[L][L];
    memset(chk,false,sizeof(chk));

    function<void(int,int)> dfs = [&](int x,int y) {
        cnt++;
        chk[x][y]=true;
        for(int i=0; i<8; i+=2) {
            int nx=x+dx[i],ny=y+dy[i];
            if(outOfRange(nx,ny) || chk[nx][ny]) continue;
            chk[nx][ny]=true;
            if(tBoard[nx][ny]==mx) dfs(nx,ny);
        }
    };

    int mxcnt=0;
    Coord mxco(0,0);
    for(int i=0; i<v.size(); i++) {
        if(chk[v[i].x][v[i].y]) continue;
        cnt=0;
        dfs(v[i].x,v[i].y);
        if(mxcnt < cnt) {
            mxcnt = cnt;
            mxco = v[i];
        }
    }

    return mxco;
}

int kmp(const string &H, int nidx) {
    int ret=-1;
    //vector<int> pi(N.size(),0),ret;
    for(int i=0,matched=0; i<H.size(); i++) {
        while(matched!=0 && H[i]!=vn[nidx].second[matched]) matched=pi[nidx][matched-1];
        if(H[i]==vn[nidx].second[matched]) {
            matched++;
            if(matched==vn[nidx].second.size()) {
                if(vn[nidx].first == 0) {
                    //7목 검사를 여기서
                    string ts="1111111";
                    if(kmp(ts,VNSZ-1)>=0) return -1;
                    else return i-matched+1;
                } else return i-matched+1;
            }
        }
    }
    return ret;
}
