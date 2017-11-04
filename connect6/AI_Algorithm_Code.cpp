// Samsung Go Tournament Form C (g++-4.8.3)

/*
[AI 코드 작성 방법]
1. char info[]의 배열 안에                    "TeamName:자신의 팀명,Department:자신의 소속"                    순서로 작성합니다.
( 주의 ) Teamname:과 Department:는 꼭 들어가야 합니다.
"자신의 팀명", "자신의 소속"을 수정해야 합니다.
2. 아래의 myturn() 함수 안에 자신만의 AI 코드를 작성합니다.
3. AI 파일을 테스트 하실 때는 "육목 알고리즘대회 툴"을 사용합니다.
4. 육목 알고리즘 대회 툴의 연습하기에서 바둑돌을 누른 후, 자신의 "팀명" 이 들어간 알고리즘을 추가하여 테스트 합니다.
[변수 및 함수]
myturn(int cnt) : 자신의 AI 코드를 작성하는 메인 함수 입니다.
int cnt (myturn()함수의 파라미터) : 돌을 몇 수 둬야하는지 정하는 변수, cnt가 1이면 육목 시작 시  한 번만  두는 상황(한 번), cnt가 2이면 그 이후 돌을 두는 상황(두 번)
int  x[0], y[0] : 자신이 둘 첫 번 째 돌의 x좌표 , y좌표가 저장되어야 합니다.
int  x[1], y[1] : 자신이 둘 두 번 째 돌의 x좌표 , y좌표가 저장되어야 합니다.
void domymove(int x[], int y[], cnt) : 둘 돌들의 좌표를 저장해서 출력
//int board[BOARD_SIZE][BOARD_SIZE]; 바둑판 현재상황 담고 있어 바로사용 가능함. 단, 원본데이터로 수정 절대금지
// 놓을수 없는 위치에 바둑돌을 놓으면 실격패 처리.
boolean ifFree(int x, int y) : 현재 [x,y]좌표에 바둑돌이 있는지 확인하는 함수 (없으면 true, 있으면 false)
int showBoard(int x, int y) : [x, y] 좌표에 무슨 돌이 존재하는지 보여주는 함수 (1 = 자신의 돌, 2 = 상대의 돌, 3 = 블럭킹)
<-------AI를 작성하실 때, 같은 이름의 함수 및 변수 사용을 권장하지 않습니다----->
*/

#include <Windows.h>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <algorithm>
#include <queue>
#include "Connect6Algo.h"
using namespace std;

// "샘플코드[C]"  -> 자신의 팀명 (수정)
// "AI부서[C]"  -> 자신의 소속 (수정)
// 제출시 실행파일은 반드시 팀명으로 제출!
char info[] ={"TeamName:plzrun,Department:EDS"};

#define N 19
#define EMPTY 0
//PLAYER와 OPPLAYER는 myturn()함수 안에서만 사용 가능하다.
#define PLAYER 1
#define OPPLAYER 2
#define BLOCK 3
#define MARK 4
#define MARK7 5
const double Inf = 1600000.0;
const double D[]={1.0,1.00000181862,1.00000363725,1.00000726562};
const double W[]={3.4,2.8532,2.5938,2.358,2.144};
const double E=1.1;

char buff[200];
//extern inline int showBoard(int x, int y);
//extern void writeLog(char *myLog);


struct HalfMove{
	int x,y;
	HalfMove(){} HalfMove(int x, int y):x(x),y(y){}
	inline bool operator==(const HalfMove &rhs) const { return (x==rhs.x && y==rhs.y); }
	inline bool operator!=(const HalfMove &rhs) const { return (x!=rhs.x || y!=rhs.y); }
	inline bool isOutOfBound() const { return (x<0 || y<0 || x>=N || y>=N); }
	inline bool isNone() const { return x<0; }
};
const HalfMove NoneHalfMove(-1,-1);

struct Move{
	HalfMove first,second;
	Move():first(NoneHalfMove),second(NoneHalfMove){} Move(HalfMove first, HalfMove second):first(first),second(second){}
	inline bool operator==(const Move &rhs) const { return (first==rhs.first && second==rhs.second); }
	inline bool operator!=(const Move &rhs) const { return (first!=rhs.first || second!=rhs.second); }
	inline bool isNone() const { return first.x<0; }
};
const Move NoneMove(NoneHalfMove,NoneHalfMove);

struct MoveScore{
	Move mv;
	double score;
	MoveScore():mv(NoneMove),score(-Inf){}
	MoveScore(Move mv, double score):mv(mv),score(score){}
	bool operator<(const MoveScore &rhs) const { return score>rhs.score; }
	bool operator==(const MoveScore &rhs) const { return score==rhs.score; }
};

const int dx[]={-1,0,1,1}, dy[]={1,1,1,0};
int B[N][N];

inline bool isOutOfBound(int x, int y) { return (x<0 || y<0 || x>=N || y>=N); }
inline Move getBoardInfo(int player) {
	Move ret;
	int tmp, opp=3-player;
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			if(B[i][j]>=MARK) B[i][j]=EMPTY;
			tmp=showBoard(i,j);
			if(tmp!=B[i][j] && tmp==opp){
				B[i][j]=tmp;
				if(ret.isNone()) ret.first = HalfMove(i,j);
				else{
					ret.second = HalfMove(i,j);
					//return ret; //2개만 발견하면 이전 보드상태와 다른 점을 발견할 수 없으므로 여기서 바로 끝낸다.
				}
			}
			B[i][j]=tmp;
		}
	}
	return ret;
}

//(x,y) ~ (x+5*dx[dir],y+5*dx[dir])를 window라 할 때, window 밖의 점으로 인해 7목 이상이 만들어질 수 있는지 확인한다.
//단, 해당 함수가 window내부에서 반드시 4목이상이 만들어질 수 있는지 보장하지는 않는다.
inline bool couldMakeConnect7(int x,int y,int player,int dir){
	return !(isOutOfBound(x-dx[dir],y-dy[dir]) || B[x-dx[dir]][y-dy[dir]]!=player) && (isOutOfBound(x+6*dx[dir],y+6*dx[dir] || B[x+6*dx[dir]][y+6*dy[dir]]));
}

Move moveForConnect6(int player){
	int opplayer = 3-player;
	for(int x=0; x<N; x++){
		for(int y=0; y<N; y++){
			if(B[x][y]!=player) continue;
			for(int dir=0; dir<4; dir++){
				int playerStone=1; //(x,y)는 자기 자신이므로 1개는 세어두고 시작한다.
				if(isOutOfBound(x+5*dx[dir],y+5*dy[dir])) continue; //window에 6개의 돌을 놓지 못한다면 skip
				if(couldMakeConnect7(x,y,player,dir)) continue; //7목의 우려가 있는 경우는 skip
				for(int k=0,nx=x+dx[dir],ny=y+dy[dir]; k<5; k++,nx+=dx[dir],ny+=dy[dir]){
					//if(isOutOfBound(nx,ny)) break; //위에서 걸러냈으므로 (nx,ny)가 Board범위 밖인 곳을 가리킬 일은 없다.
					if(B[nx][ny]==player) playerStone++;
					else if(B[nx][ny]==EMPTY) continue;
					else break;
				}
				if(playerStone>=4){
					Move ret;
					for(int k=0,nx=x+dx[dir],ny=y+dy[dir]; k<5; k++,nx+=dx[dir],ny+=dy[dir]){
						if(B[nx][ny]==EMPTY){
							if(ret.isNone()) ret.first = HalfMove(nx,ny);
							else ret.second = HalfMove(nx,ny);
						}
					}
					return ret; //connet6를 만들 수 있는 경우, 여기서 return됨
				}
			}
		}
	}
	return NoneMove;
}

HalfMove getAnyValidHalfMove(int player){
	for(int x=0; x<N; x++){
		for(int y=0; y<N; y++){
			if(B[x][y]!=EMPTY) continue; //(x,y)가 비어있는 곳만 조사한다.
			bool good=true;
			for(int dir=0; dir<4; dir++){
				int playerStone = 1; //(x,y)에 player가 돌을 뒀다고 가정한다.
				//if(isOutOfBound(x+5*dx[dir],y+5*dy[dir])) continue; //6목을 만들 수 없는 경우는 good
				//if(couldMakeConnect7(x,y,player,dir)) continue; //7목의 우려가 있는 경우는 good
				for(int k=0,nx=x+dx[dir],ny=y+dy[dir]; k<5; k++,nx+=dx[dir],ny+=dy[dir]){
					if(isOutOfBound(nx,ny)) break;
					if(B[nx][ny]==player) playerStone++;
					else break;
				}
				for(int k=0,nx=x-dx[dir],ny=y-dy[dir]; k<5; k++,nx-=dx[dir],ny-=dy[dir]){
					if(isOutOfBound(nx,ny)) break;
					if(B[nx][ny]==player) playerStone++;
					else break;
				}
				if(playerStone>=7){
					//7목이상이 형성되는경우 필패이므로 절대 두어서는 안된다.
					good=false;
					break;
				}
			}
			if(good) return HalfMove(x,y);
		}
	}
	return HalfMove(0,0); //더 이상 둘 곳이 없으므로 아무곳이나 리턴한다.
}

vector<Move> getDefensiveStrategicMoves(int player,Move oppLastMove){
	vector<Move> threatList;
	int opp=3-player,cnt=2;
	if(oppLastMove.second.isNone()) cnt=1;
	int x[2]={oppLastMove.first.x, oppLastMove.second.x},y[2]={oppLastMove.first.y, oppLastMove.second.y};
	for(int i=0; i<cnt; i++){
		for(int dir=0; dir<4; dir++){
			for(int sx=x[i],sy=y[i],z=0; z<6; z++,sx-=dx[dir],sy-=dy[dir]){
				if(isOutOfBound(sx+5*dx[dir],sy+5*dy[dir])) continue;

				int oppStone=0;
				for(int nx=sx,ny=sy,k=0; k<6; k++,nx+=dx[dir],ny+=dy[dir]){
					if(B[nx][ny]==opp) oppStone++;
					else if(B[nx][ny]==EMPTY || B[nx][ny]==MARK7) continue;
					else{
						oppStone=0;
						break;
					}
				}
				if(oppStone>=4){
					if(couldMakeConnect7(sx,sy,opp,dir)){
						//상대방7목이 만들어지면 EMPTY부분만 MARK7으로 바꿔준다.
						for(int nx=sx,ny=sy,k=0; k<6; k++,nx+=dx[dir],ny+=dy[dir]) if(B[nx][ny]==EMPTY) B[nx][ny]=MARK7;
					} else{
						Move tmpMove;
						for(int nx=sx,ny=sy,k=0; k<6; k++,nx+=dx[dir],ny+=dy[dir]){
							if(B[nx][ny]==EMPTY || B[nx][ny]==MARK7){
								B[nx][ny]=MARK;
								if(tmpMove.isNone()) tmpMove.first = HalfMove(nx,ny);
								else tmpMove.second = HalfMove(nx,ny);
							}
						}
						threatList.push_back(tmpMove);
					}
				}
				if(threatList.size()>=3) return threatList; //필패
			}
		}
	}
	return threatList;
}


double getHalfMoveScore(int player,HalfMove co){
	int opp=3-player;
	int noMeetOppCnt=0;
	double totalScore=0.0;
	for(int dir=0; dir<4; dir++){
		double score=1.0;
		bool everMetOpp=false;
		for(int nx=co.x+dx[dir],ny=co.y+dy[dir],k=0; k<5; k++,nx+=dx[dir],ny+=dy[dir]){
			if(isOutOfBound(nx,ny)) break;
			if(B[nx][ny]==player) score*=W[k];
			else if(B[nx][ny]!=opp) score*=E; //B[nx][ny]==EMPTY
			else{
				everMetOpp=true;
				break;
			}
		}
		for(int nx=co.x-dx[dir],ny=co.y-dy[dir],k=0; k<5; k++,nx-=dx[dir],ny-=dy[dir]){
			if(isOutOfBound(nx,ny)) break;
			if(B[nx][ny]==player) score*=W[k];
			else if(B[nx][ny]!=opp) score*=E; //B[nx][ny]==EMPTY
			else{
				everMetOpp=true;
				break;
			}
		}
		if(!everMetOpp) noMeetOppCnt++;
		totalScore+=score;
	}
	return totalScore*D[noMeetOppCnt];
}

double getMoveScore(int player,Move mv){
	double score=0.0;
	if(!mv.first.isNone()) score+=getHalfMoveScore(player,mv.first);
	if(!mv.second.isNone()) score+=getHalfMoveScore(player,mv.second);
	return score;
}

Move moveForTheBest(int player,Move &oppLastMove){
	Move ret = moveForConnect6(player);
	if(!ret.isNone()){
		if(ret.second.isNone()){
			B[ret.first.x][ret.first.y] = player;
			ret.second = getAnyValidHalfMove(player);
			B[ret.first.x][ret.first.y] = EMPTY;
		}
		return ret;
	} else{
		//while(1);
		vector<Move> threatList = getDefensiveStrategicMoves(player,oppLastMove);
		if(threatList.size()>=3) {
			//while(1);
			return Move(threatList[0].first,threatList[1].second); //필패니까 아무거나 낸다.
		}
		else if(threatList.size()==2){
			Move tmpMove;
			double mnScore=Inf;
			for(int i=0; i<2; i++){
				if(i==0) tmpMove.first = threatList[0].first;
				else tmpMove.first = threatList[0].second;
				for(int j=0; j<2; j++){
					if(j==0) tmpMove.second = threatList[1].first;
					else tmpMove.second = threatList[1].second;

					if(!tmpMove.first.isNone()) B[tmpMove.first.x][tmpMove.first.y]=player;
					if(!tmpMove.second.isNone()) B[tmpMove.second.x][tmpMove.second.y]=player;
					double score = getMoveScore(player,tmpMove);
					if(mnScore > score){
						mnScore = score;
						ret = tmpMove;
					}
					if(!tmpMove.first.isNone()) B[tmpMove.first.x][tmpMove.first.y]=EMPTY;
					if(!tmpMove.second.isNone()) B[tmpMove.second.x][tmpMove.second.y]=EMPTY;
				}
			}
			return ret;
		} else if(threatList.size()==1){
			while(1);
			return Move(HalfMove(N-1,N-1),HalfMove(N-2,N-2));
			//To Do
		} else{
			//To Do
		}
	}
	return ret;
}

void myturn(int cnt){
	int x[2],y[2];

	// 이 부분에서 알고리즘 프로그램(AI)을 작성하십시오. 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하시면 됩니다.
	// 현재 Sample code의 AI는 Random으로 돌을 놓는 Algorithm이 작성되어 있습니다.

	srand((unsigned)time(NULL));
	Move oppLastMove = getBoardInfo(PLAYER);
	if(cnt!=1){
		Move mv = moveForTheBest(PLAYER,oppLastMove);
		if(!mv.isNone()){
			x[0]=mv.first.x; y[0]=mv.first.y;
			if(!mv.second.isNone()) x[1]=mv.second.x,y[1]=mv.second.y;
			else{
				HalfMove hmv = getAnyValidHalfMove(PLAYER);
				x[1]=hmv.x,y[1]=hmv.y;
			}
		} else{
			HalfMove halfmv1 = getAnyValidHalfMove(PLAYER);
			B[halfmv1.x][halfmv1.y]=PLAYER;
			HalfMove halfmv2 = getAnyValidHalfMove(PLAYER);
			B[halfmv1.x][halfmv1.y]=EMPTY;
			x[0]=halfmv1.x; y[0]=halfmv1.y;
			x[1]=halfmv2.x; y[1]=halfmv2.y;
		}
	} else{
		for(int i = 0; i < cnt; i++){
			do{
				x[i] = rand() % width;
				y[i] = rand() % height;
				if(terminateAI) return;
			} while(!isFree(x[i],y[i]));

			if(x[1] == x[0] && y[1] == y[0]) i--;
		}
	}

	//domymove()를 호출하기 전에 내가 둔 수는 B(board)에 업데이트한다.
	/*
	for(int i=0; i<cnt; i++) B[x[i]][y[i]]=PLAYER;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(B[i][j]>=MARK) B[i][j]=EMPTY;
		}
	}*/

	// 이 부분에서 자신이 놓을 돌을 출력하십시오.
	// 필수 함수 : domymove(x배열,y배열,배열크기)
	// 여기서 배열크기(cnt)는 myturn()의 파라미터 cnt를 그대로 넣어야합니다.
	domymove(x,y,cnt);
}