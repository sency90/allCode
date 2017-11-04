// Samsung Go Tournament Form C (g++-4.8.3)

/*
[AI �ڵ� �ۼ� ���]
1. char info[]�� �迭 �ȿ�                    "TeamName:�ڽ��� ����,Department:�ڽ��� �Ҽ�"                    ������ �ۼ��մϴ�.
( ���� ) Teamname:�� Department:�� �� ���� �մϴ�.
"�ڽ��� ����", "�ڽ��� �Ҽ�"�� �����ؾ� �մϴ�.
2. �Ʒ��� myturn() �Լ� �ȿ� �ڽŸ��� AI �ڵ带 �ۼ��մϴ�.
3. AI ������ �׽�Ʈ �Ͻ� ���� "���� �˰����ȸ ��"�� ����մϴ�.
4. ���� �˰��� ��ȸ ���� �����ϱ⿡�� �ٵϵ��� ���� ��, �ڽ��� "����" �� �� �˰����� �߰��Ͽ� �׽�Ʈ �մϴ�.
[���� �� �Լ�]
myturn(int cnt) : �ڽ��� AI �ڵ带 �ۼ��ϴ� ���� �Լ� �Դϴ�.
int cnt (myturn()�Լ��� �Ķ����) : ���� �� �� �־��ϴ��� ���ϴ� ����, cnt�� 1�̸� ���� ���� ��  �� ����  �δ� ��Ȳ(�� ��), cnt�� 2�̸� �� ���� ���� �δ� ��Ȳ(�� ��)
int  x[0], y[0] : �ڽ��� �� ù �� ° ���� x��ǥ , y��ǥ�� ����Ǿ�� �մϴ�.
int  x[1], y[1] : �ڽ��� �� �� �� ° ���� x��ǥ , y��ǥ�� ����Ǿ�� �մϴ�.
void domymove(int x[], int y[], cnt) : �� ������ ��ǥ�� �����ؼ� ���
//int board[BOARD_SIZE][BOARD_SIZE]; �ٵ��� �����Ȳ ��� �־� �ٷλ�� ������. ��, ���������ͷ� ���� �������
// ������ ���� ��ġ�� �ٵϵ��� ������ �ǰ��� ó��.
boolean ifFree(int x, int y) : ���� [x,y]��ǥ�� �ٵϵ��� �ִ��� Ȯ���ϴ� �Լ� (������ true, ������ false)
int showBoard(int x, int y) : [x, y] ��ǥ�� ���� ���� �����ϴ��� �����ִ� �Լ� (1 = �ڽ��� ��, 2 = ����� ��, 3 = ��ŷ)
<-------AI�� �ۼ��Ͻ� ��, ���� �̸��� �Լ� �� ���� ����� �������� �ʽ��ϴ�----->
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

// "�����ڵ�[C]"  -> �ڽ��� ���� (����)
// "AI�μ�[C]"  -> �ڽ��� �Ҽ� (����)
// ����� ���������� �ݵ�� �������� ����!
char info[] ={"TeamName:plzrun,Department:EDS"};

#define N 19
#define EMPTY 0
//PLAYER�� OPPLAYER�� myturn()�Լ� �ȿ����� ��� �����ϴ�.
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
					//return ret; //2���� �߰��ϸ� ���� ������¿� �ٸ� ���� �߰��� �� �����Ƿ� ���⼭ �ٷ� ������.
				}
			}
			B[i][j]=tmp;
		}
	}
	return ret;
}

//(x,y) ~ (x+5*dx[dir],y+5*dx[dir])�� window�� �� ��, window ���� ������ ���� 7�� �̻��� ������� �� �ִ��� Ȯ���Ѵ�.
//��, �ش� �Լ��� window���ο��� �ݵ�� 4���̻��� ������� �� �ִ��� ���������� �ʴ´�.
inline bool couldMakeConnect7(int x,int y,int player,int dir){
	return !(isOutOfBound(x-dx[dir],y-dy[dir]) || B[x-dx[dir]][y-dy[dir]]!=player) && (isOutOfBound(x+6*dx[dir],y+6*dx[dir] || B[x+6*dx[dir]][y+6*dy[dir]]));
}

Move moveForConnect6(int player){
	int opplayer = 3-player;
	for(int x=0; x<N; x++){
		for(int y=0; y<N; y++){
			if(B[x][y]!=player) continue;
			for(int dir=0; dir<4; dir++){
				int playerStone=1; //(x,y)�� �ڱ� �ڽ��̹Ƿ� 1���� ����ΰ� �����Ѵ�.
				if(isOutOfBound(x+5*dx[dir],y+5*dy[dir])) continue; //window�� 6���� ���� ���� ���Ѵٸ� skip
				if(couldMakeConnect7(x,y,player,dir)) continue; //7���� ����� �ִ� ���� skip
				for(int k=0,nx=x+dx[dir],ny=y+dy[dir]; k<5; k++,nx+=dx[dir],ny+=dy[dir]){
					//if(isOutOfBound(nx,ny)) break; //������ �ɷ������Ƿ� (nx,ny)�� Board���� ���� ���� ����ų ���� ����.
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
					return ret; //connet6�� ���� �� �ִ� ���, ���⼭ return��
				}
			}
		}
	}
	return NoneMove;
}

HalfMove getAnyValidHalfMove(int player){
	for(int x=0; x<N; x++){
		for(int y=0; y<N; y++){
			if(B[x][y]!=EMPTY) continue; //(x,y)�� ����ִ� ���� �����Ѵ�.
			bool good=true;
			for(int dir=0; dir<4; dir++){
				int playerStone = 1; //(x,y)�� player�� ���� �״ٰ� �����Ѵ�.
				//if(isOutOfBound(x+5*dx[dir],y+5*dy[dir])) continue; //6���� ���� �� ���� ���� good
				//if(couldMakeConnect7(x,y,player,dir)) continue; //7���� ����� �ִ� ���� good
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
					//7���̻��� �����Ǵ°�� �����̹Ƿ� ���� �ξ�� �ȵȴ�.
					good=false;
					break;
				}
			}
			if(good) return HalfMove(x,y);
		}
	}
	return HalfMove(0,0); //�� �̻� �� ���� �����Ƿ� �ƹ����̳� �����Ѵ�.
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
						//����7���� ��������� EMPTY�κи� MARK7���� �ٲ��ش�.
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
				if(threatList.size()>=3) return threatList; //����
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
			return Move(threatList[0].first,threatList[1].second); //���дϱ� �ƹ��ų� ����.
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

	// �� �κп��� �˰��� ���α׷�(AI)�� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����Ͻø� �˴ϴ�.
	// ���� Sample code�� AI�� Random���� ���� ���� Algorithm�� �ۼ��Ǿ� �ֽ��ϴ�.

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

	//domymove()�� ȣ���ϱ� ���� ���� �� ���� B(board)�� ������Ʈ�Ѵ�.
	/*
	for(int i=0; i<cnt; i++) B[x[i]][y[i]]=PLAYER;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(B[i][j]>=MARK) B[i][j]=EMPTY;
		}
	}*/

	// �� �κп��� �ڽ��� ���� ���� ����Ͻʽÿ�.
	// �ʼ� �Լ� : domymove(x�迭,y�迭,�迭ũ��)
	// ���⼭ �迭ũ��(cnt)�� myturn()�� �Ķ���� cnt�� �״�� �־���մϴ�.
	domymove(x,y,cnt);
}