#include <cstdio>
#define N 20
#define EMPTY 0
using namespace std;
int b[N][N];
int dx[]={-1,0,1,1},dy[]={1,1,1,0};
inline bool isValidBound(int x, int y) { return 0<=x && x<N && 0<=y && y<N; }
const int e=10,w[]={60,40,35,30,25};
int hmove_evaluation(int x, int y, int me) {
    int E=0, Edir=1;
    for(int dir=0; dir<4; dir++) {
        Edir=1;

        //To do:
        //개수세서 7목 예외를 걸러줘야 한다.
        if(isValidBound(x+5*dx[dir],y+5*dy[dir])) {
            for(int nx=x+dx[dir],ny=y+dy[dir],i=0; i<5; nx+=dx[dir],ny+=dy[dir],i++) {
                if(b[nx][ny]==EMPTY) Edir*=e;
                else if(b[nx][ny]==me) Edir*=w[i];
                else break;
            }
        }
        if(isValidBound(x-5*dx[dir],y-5*dy[dir])) {
            for(int nx=x-dx[dir],ny=y-dy[dir],i=0; i<5; nx-=dx[dir],ny-=dy[dir],i++) {
                if(b[nx][ny]==EMPTY) Edir*=e;
                else if(b[nx][ny]==me) Edir*=w[i];
                else break;
            }
        }
        if(Edir!=1) E+=Edir;
    }
    return E;
}
int main() {
    return 0;

