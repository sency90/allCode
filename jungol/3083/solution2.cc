#pragma optimize "-O2"
#include <stdio.h>
#define HOUSE_SIZE 20000
#define BLANK_SIZE 64
#define MAX_HOUSE 10
#define MAX_COUNT (HOUSE_SIZE*2*50)

extern int gethouseSize();
extern int readhouse(int *blank,int address,int size);
extern int move(int from,int to,int size);

int sz,numcnt,mxsum,zp;
int h[HOUSE_SIZE+1], th[HOUSE_SIZE+1];
int buf[HOUSE_SIZE+1], cnt[MAX_HOUSE][HOUSE_SIZE+1];
int v[10], targetIdx[10], target[10];
int lowStart[10], highStart[10];
bool chk[10];

inline int min(int x, int y) { return x<y?x:y; }
inline void m_init() {
    numcnt=mxsum=0;
    sz = gethouseSize();
    readhouse(h+1,0,sz);
    for(int i=1; i<10; i++) {
        for(int j=1; j<=sz; j++) {
            cnt[i][j]=0;
        }
    }

    for(int i=0; i<10; i++) {
        chk[i]=false;
        v[i]=target[i]=targetIdx[i]=0;
    }
    for(int i=1; i<=sz; i++) {
        th[i]=0;
        if(chk[h[i]]) continue;
        chk[h[i]]=true;
        if(h[i]!=0) v[numcnt++] = h[i];
    }
    for(int i=0; i<10; i++) chk[i]=false;
}

inline void getPartialSum() {
    for(int hno=1; hno<10; hno++) {
        for(int i=1; i<=sz; i++) {
            cnt[hno][i]+=cnt[hno][i-1]+(h[i]==hno);
        }
    }
}
int num[10];
inline void dfs(int x) {
    if(x>numcnt) {
        for(int i=1; i<=numcnt; i++) targetIdx[i] = targetIdx[i-1]+cnt[num[i]][sz];
        int sum=0;
        for(int i=1; i<=numcnt; i++) sum+=cnt[num[i]][targetIdx[i]]-cnt[num[i]][targetIdx[i-1]];
        if(mxsum<sum) {
            mxsum=sum;
            for(int i=1; i<=numcnt; i++) target[i]=num[i];
        }
        return;
    }

    for(int i=0; i<numcnt; i++) {
        if(chk[i]) continue;
        chk[i]=true;
        num[x]=v[i];
        dfs(x+1);
        chk[i]=false;
    }
}
inline void assignTarget() {
    for(int i=1; i<=numcnt; i++) {
        lowStart[i]=0;
        targetIdx[i] = targetIdx[i-1]+cnt[target[i]][sz];
        highStart[i]=targetIdx[i]+1;
    }
    for(int i=1; i<=numcnt; i++) {
        for(int j=targetIdx[i-1]+1; j<=targetIdx[i]; j++) {
            th[j]=target[i];
        }
    }
    zp=targetIdx[numcnt]+1;
}
inline void findTarget() {
    getPartialSum();
    dfs(1);
    assignTarget();
}

inline void mmove(int from, int to, int size) {
    for(int i=0; i<size; i++) {
        buf[i]=h[from];
        h[from++]=0;
    }
    for(int i=0; i<size; i++) h[to++]=buf[i];
    move(from-1,to-1,size);
}


void cleanup() {
    m_init();
    findTarget();

    for(int i=1; i<=sz; i++) printf("%d",h[i]);
    puts("");
    for(int i=1; i<=sz; i++) printf("%d",th[i]);
    puts(""); puts("");



}

