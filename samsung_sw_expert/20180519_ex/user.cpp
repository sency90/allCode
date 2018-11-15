#include <cstdio>
#ifndef SIZE
#define SIZE 4096
#endif

#define ELEN 256
#define BLOCK_CNT 256
struct Block{
    bool isFix = false;
    int x,y,idx;
    int originalPos = 0;
    int leftIdx=-1, rightIdx=-1, topIdx=-1, bottomIdx=-1;
    unsigned char top[ELEN], bottom[ELEN], left[ELEN], right[ELEN];
    Block(){}
};

int mem[4], cnt[256];
unsigned char getNumBT(int x, int y, unsigned char (*map)[4096]) {
    for(int i=0; i<4; i++) {
        mem[i] = map[x+i][y];
        cnt[map[x+i][y]]++;
    }
    int mxcnt=0, mxidx=0;
    for(int i=0; i<4; i++) {
        if(mxcnt<cnt[mem[i]]) {
            mxcnt = cnt[mem[i]];
            mxidx = i;
        }
        cnt[map[x+i][y]]--;
    }
    return map[x+mxidx][y];
}

unsigned char getNumLR(int x, int y, unsigned char (*map)[4096]) {
    for(int i=0; i<4; i++) {
        mem[i] = map[x][y+i];
        cnt[map[x][y+i]]++;
    }
    int mxcnt=0, mxidx=0;
    for(int i=0; i<4; i++) {
        if(mxcnt<cnt[mem[i]]) {
            mxcnt = cnt[mem[i]];
            mxidx = i;
        }
        cnt[map[x][y+i]]--;
    }
    return map[x][y+mxidx];
}

Block blocks[256];
bool matchBlock(unsigned char (*map)[SIZE]) {
    for(int i=0; i<16; i++) {
        for(int j=0; j<16; j++) {
            int blockIdx = i*16+j;
            if(blocks[blockIdx].isFix) continue;
            Block &lBlock = blocks[blockIdx];
        }
    }
}

void recover(unsigned char map[SIZE][SIZE]) {
    int idx=0;
    for(int i=0; i<16; i++) {
        for(int j=0; j<16; j++) {
            int nx=(i<<8), ny=(j<<8);
            blocks[idx].x=nx; blocks[idx].y=ny; blocks[idx].isFix=false;
            //int topZero=1,bottomZero=1,leftZero=1,rightZero=1;
            for(int k=0; k<ELEN; k++) {
                blocks[idx].top[k] = getNumBT(nx,ny+k,map);
                blocks[idx].bottom[k] = getNumBT(nx+252,ny+k,map);
                blocks[idx].left[k] = getNumLR(nx,ny+k,map);
                blocks[idx].right[k] = getNumLR(nx+252,ny+k,map);
                //if(blocks[idx].top[k] != 0) topZero = 0;
                //if(blocks[idx].bottom[k] != 0) bottomZero = 0;
                //if(blocks[idx].left[k] != 0) leftZero = 0;
                //if(blocks[idx].right[k] != 0) rightZero = 0;
            }
            //if(topZero + bottomZero + leftZero + rightZero )
        }
    }

    int matched=0;
    while(matched<256) {
        for(int i=0; i<16; i++) {
            for(int j=0; j<16; j++) {
                int blockIdx = i*16+j;
                Block &curBlock = blocks[blockIdx];
                if(curBlock.isFix) continue;

                //find left
                int correctCnt=0, mxscore=-1;
                for(int k=0; k<256; k++) {
                    if(k==blockIdx) continue; //skip itself

                    correctCnt = getScore(curBlock.left, blocks[k].right);
                    if(correctCnt == 256) {
                        mxscore = score;
                        curBlock.leftIdx = k;
                    }


                    if(leftDiff<0) leftDiff = getScore(curBlock.left, blocks[k].right);
                    if(rightDiff<0) rightDiff = getScore(curBlock.right, blocks[k].left);
                    if(topDiff<0) topDiff = getScore(curBlock.top, blocks[k].bottom);
                    if(bottomDiff<0) bottomDiff = getScore(curBlock.bottom, blocks[k].top);

                    if(blocks[k].isFix) {
                        if(leftDiff<0) leftDiff = getScore(curBlock.left, blocks[k].right);
                        if(rightDiff<0) rightDiff = getScore(curBlock.right, blocks[k].left);
                        if(topDiff<0) topDiff = getScore(curBlock.top, blocks[k].bottom);
                        if(bottomDiff<0) bottomDiff = getScore(curBlock.bottom, blocks[k].top);
                    }






                    int diffCnt=0, score=0;
                    Block &leftBlock = blocks[k];
                    for(int u=0; u<256; u++) {
                        if(leftBlock.right[u] != curBlock.left[u]) {
                            diffCnt++;
                            if(diffCnt>5) 
                        }
                    }
                }
            }
        }
    }
}
