#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define N 20
#define EMPTY 0
#define BLOCK 3
int b[N][N];
extern int getBoard(int x, int y);
struct Co{
    int x, y;
    Co(){} Co(int x, int y):x(x),y(y){}
};
inline bool isValidBound(int x, int y) { return 0<=x && x<N && 0<=y && y<N; }
vector<Co> getPrevStones(int me) {
    vector<Co> ret(2,Co(-1,-1));
    int cnt=0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            int res = getBoard(i,j);
            if(res != b[i][j]) {
                ret[cnt++]=Co(i,j);
                b[i][j]=res;
            }
        }
    }
    return ret;
}
vector<Co> getMoveList(int x, int y) {
    vector<Co> ret;
    for(int i=x-2; i<=x+2; i++) {
        for(int j=y-2; j<=y+2; j++) {
            if(isValidBound(i,j) && b[i][j]==EMPTY) ret.emplace_back(Co(i,j));
        }
    }
    return ret;
}
vector<Co> tryConnect6(int me) {
    vector<Co> ret;
    int opp = 3-me;
    int p=0,s=0,cnt=0;
    for(int i=0; i<N; i++) {
        while(p<N) {
            if(p==s+6) {
                cnt-=(b[i][s++]==me);
                cnt+=(b[i][p++]==me);
            } else {
                for(p=s; p<s+6; p++) {
                    if(b[i][p]==opp||b[i][p]==BLOCK) {
                        cnt=0;
                        s=++p;
                        break;
                    } else if(b[i][p]==me) cnt++;
                }
            }
            if(cnt>=4) {
                for(int j=s; j<p; j++) if(b[i][j]==EMPTY) ret.emplace_back(Co(i,j));
                return ret;
            }
        }
    }

    s=p=cnt=0;
    for(int j=0; j<N; j++) {
        while(p<N) {
            if(p==s+6) {
                cnt-=(b[s++][j]==me);
                cnt+=(b[p++][j]==me);
            } else {
                for(p=s; p<s+6; p++) {
                    if(b[p][j]==opp||b[p][j]==BLOCK) {
                        cnt=0;
                        s=++p;
                        break;
                    } else if(b[p][j]==me) cnt++;
                }
            }
            if(cnt>=4) {
                for(int i=s; i<p; i++) if(b[i][j]==EMPTY) ret.emplace_back(Co(i,j));
                return ret;
            }
        }
    }

    int lim = N*2-1;
    for(int z=0; z<lim; z++) {
        if(min(z+1,lim-z)<6) continue;
        int k=max(0,z-N+1);
        int s=k,i=k,j=z-k;
        while(j>=k) {
            if(i-s==5) {
                cnt-=(b[s++][j+(s-k)]==me);
                cnt+=(b[i++][j--]==me);
            } else {
                for(i=s,j=z-s; i-s<6; i++,j--) {
                    if(b[i][j]==opp||b[i][j]==BLOCK) {
                        cnt=0;
                        s=i+1;
                        break;
                    } else if(b[i][j]==me) cnt++;
                }
            }
            if(cnt>=4) {
                for(int u=s,v=)
            }
        }
    }
    return ret;
}
void fillBoard(int cnt, vector<Co> &moveList) {

}
vector<Co> threatSpaceSearch(int me) {
    vector<Co> ret;//(2,Co(-1,-1));
    int opp=3-me;

    ret = tryConnect6(opp);
    if(!ret.empty()) return ret;
    ret = tryConnect6(me);
    if(!ret.empty()) return ret;

    ret = calThreatCnt(me);
    if(ret.size()>=3) {
        fillBoard(2, ret);
    }
    if(canWin(me)||calThreatCnt(me)>=3) 
}
int main() {
    return 0;
}
