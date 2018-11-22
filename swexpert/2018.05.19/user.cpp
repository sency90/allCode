#ifndef SIZE
#define SIZE 4096
#endif
#define CHKCNT 4
typedef unsigned char uchar;
struct Block{
    bool isFix;
    uchar top[256], bottom[256], left[256], right[256];
    int x,y;
};

Block blocks[256];
Block puzzle[16][16];

inline int getScore(uchar *edge1, uchar *edge2) {
    register int diff=0;
    for(register int i=0; i<256; i++) {
        diff += (*edge1++!=*edge2++);
        if(diff&0x4) return 0;
    }
    return 256-diff;
}

uchar edge[256];
int matched;
void matchPuzzle(int nx, int ny, unsigned char (*map)[SIZE]) {
    register uchar *topEdge = (nx==0)?        edge:(puzzle[nx-1][ny].isFix? puzzle[nx-1][ny].bottom:0);
    register uchar *bottomEdge = (nx==15)?    edge:(puzzle[nx+1][ny].isFix? puzzle[nx+1][ny].top:0);
    register uchar *leftEdge = (ny==0)?       edge:(puzzle[nx][ny-1].isFix? puzzle[nx][ny-1].right:0);
    register uchar *rightEdge = (ny==15)?     edge:(puzzle[nx][ny+1].isFix? puzzle[nx][ny+1].left:0);

    register int edgeCnt=0;
    if(topEdge) edgeCnt++;
    if(bottomEdge) edgeCnt++;
    if(leftEdge) edgeCnt++;
    if(rightEdge) edgeCnt++;

    if(edgeCnt<2) return;

    register int ansIdx = -1, mxScore=0;
    for(register int i=0; i<256; i++) {
        if(blocks[i].isFix) continue;

        int score = 0;
        if(topEdge) score += getScore(blocks[i].top, topEdge);
        if(bottomEdge) score += getScore(blocks[i].bottom, bottomEdge);
        if(leftEdge) score += getScore(blocks[i].left, leftEdge);
        if(rightEdge) score += getScore(blocks[i].right, rightEdge);
        if(mxScore < score) {
            mxScore = score;
            ansIdx = i;
        }
    }

    if(ansIdx!=-1) {
        matched++;
        blocks[ansIdx].isFix = true;
        puzzle[nx][ny] = blocks[ansIdx];
    }
}

int _cnt[256];
inline uchar getMost(uchar *buf) {
    for(register int i=0; i<CHKCNT; i++) {
        _cnt[buf[i]]=0;
    }
    register int mxcnt=0; uchar mxUchar;
    for(register int i=0; i<CHKCNT; i++) {
        _cnt[buf[i]]++;
        if(mxcnt<_cnt[buf[i]]) {
            mxcnt = _cnt[buf[i]];
            mxUchar = buf[i];
        }
    }
    return mxUchar;
}

unsigned char tmpmap[SIZE][SIZE];
void recover(unsigned char map[SIZE][SIZE]) {
    uchar buf[4][CHKCNT];
    for(register int i=0; i<16; i++) {
        for(register int j=0; j<16; j++) {
            register int nx=i<<8, ny=j<<8;
            Block &curBlock = blocks[i*16+j];
            curBlock.x = nx, curBlock.y = ny;
            puzzle[i][j].isFix=curBlock.isFix=false;

            for(register int u=0; u<256; u++) {
                for(register int v=0; v<CHKCNT; v++) {
                    buf[0][v] = map[nx+v][ny+u];
                    buf[1][v] = map[nx+255-v][ny+u];
                    buf[2][v] = map[nx+u][ny+v];
                    buf[3][v] = map[nx+u][ny+255-v];
                }
                curBlock.top[u] = getMost(buf[0]);
                curBlock.bottom[u] = getMost(buf[1]);
                curBlock.left[u] = getMost(buf[2]);
                curBlock.right[u] = getMost(buf[3]);
            }
        }
    }

    matched=0;
    while(matched<256) {
        for(register int i=0; i<16; i++) {
            for(register int j=0; j<16; j++) {
                if(!puzzle[i][j].isFix) {
                    matchPuzzle(i,j,map);
                }
            }
        }
    }

    register uchar *p1;
    register uchar *p2;
    for(register int i=0; i<16; i++) {
        for(register int j=0; j<16; j++) {
            register int x=puzzle[i][j].x, y=puzzle[i][j].y;
            register int tx=i<<8, ty=j<<8;
            for(register int u=0; u<256; u++) {
                p1 = &map[x+u][y];
                p2 = &tmpmap[tx+u][ty];
                for(register int v=0; v<256; v++) {
                    *p2++ = *p1++;
                }
            }
        }
    }

    p1 = &map[0][0];
    p2 = &tmpmap[0][0];
    for(register int i=0; i<SIZE; i++) {
        for(register int j=0; j<SIZE; j++) {
            *p1++ = *p2++;
        }
    }
}
