#pragma optimize "-O2"
#define HOUSE_SIZE 20000
#define BLANK_SIZE 64
#define MAX_HOUSE 10
#define MAX_COUNT (HOUSE_SIZE*2*50)

extern int gethouseSize();
extern int readhouse(int *blank,int address,int size);
extern int move(int from,int to,int size);

int sz,msz,zp,last;
int h[HOUSE_SIZE+1], th[HOUSE_SIZE+1];
int buf[BLANK_SIZE+1];
int cnt[HOUSE_SIZE+1][MAX_HOUSE],mx;
int tar[10],tarIdx[10],rtar[10];
bool chk[10];
int v[10],idx[10];

inline int min(int x,int y) { return x<y?x:y; }
inline int max(int x,int y) { return x>y?x:y; }
inline void m_init() {
    last=0;
    mx=0;
    sz=gethouseSize(); readhouse(h,0,sz);

    tarIdx[0]=0;
    register int i,j;
    for(i=0; i<=sz+1; i++) {
        th[i]=0;
        for(j=0; j<10; j++) {
            cnt[i][j]=0;
        }
    }
    for(i=0; i<10; i++) {
        chk[i]=false;
        tarIdx[i]=tar[i]=v[i]=idx[i]=0;
    }
}

inline int mv(int from,int to,int size) {
    move(from,to,size);
    for(int i=0; i<size; i++) {
        buf[i] = h[from];
        h[from] = 0;
        from++;
    }
    for(int i=0; i<size; i++) h[to++] = buf[i];
    return size;
}

inline void dfs(int x) {
    if(x==10) {
        for(int i=1; i<10; i++) idx[i]=idx[i-1]+cnt[sz][v[i]];
        int sum=0;
        for(int i=1; i<10; i++) sum+=cnt[idx[i]][v[i]]-cnt[idx[i-1]][v[i]];
        if(mx < sum) {
            mx=sum;
            for(int i=1; i<10; i++) {
                tar[i]=v[i];
                rtar[tar[i]]=i;
            }
            for(int i=1; i<10; i++) tarIdx[i]=idx[i];
        }
        return;
    }

    for(int i=1; i<10; i++) {
        if(chk[i]) continue;
        chk[i]=true;
        v[x]=i;
        dfs(x+1);
        chk[i]=false;
    }
}

inline void findTarget() {
    for(int i=0; i<sz; i++) {
        for(int j=0; j<10; j++) {
            cnt[i+1][j] = cnt[i][j] + (h[i]==j);
        }
    }

    dfs(1);
    zp=0;
    for(int i=1; i<10; i++) {
        for(int k=tarIdx[i-1]; k<tarIdx[i]; k++) {
            th[k] = tar[i];
        }
        zp=max(tarIdx[i],zp);
    }

    return;
}

inline bool haveDone() {
    for(int i=last; i<sz; i++) if(th[i]!=h[i]) {
        last=i;
        return false;
    }
    return true;
}


int lastIdx[10];
inline void alignAll() {
    for(int i=0; i<10; i++) lastIdx[i]=tarIdx[i];

    while(true) {
        int totalD=0;
        for(int hno=1; hno<MAX_HOUSE; hno++) {
            int mi = rtar[hno];
            if(tarIdx[mi-1]==tarIdx[mi]) continue;

            bool flag=true;
            for(int i=lastIdx[mi-1]; i<tarIdx[mi];) {
                if(h[i]==0) {
                    flag=false;
                    int ilen=0;
                    for(; ilen<BLANK_SIZE && i+ilen<tarIdx[mi] && h[i+ilen]==0; ilen++);

                    if(ilen==0) break;
                    for(int j=0; j<tarIdx[mi-1];) {
                        if(h[j]==hno) {
                            int jlen=0;
                            for(; jlen<BLANK_SIZE && j+jlen<tarIdx[mi-1] && h[j+jlen]==hno; jlen++);

                            int d = min(ilen,jlen);
                            mv(j,i,d);
                            i+=d; j+=d;
                            ilen-=d;
                            totalD+=d;
                            //lastIdx[mi-1]+=d;
                            if(ilen==0) break;
                        } else j++;
                    }

                    if(ilen==0) break;
                    for(int j=lastIdx[mi]; j<sz;) {
                        if(h[j]==hno) {
                            int jlen=0;
                            for(; jlen<BLANK_SIZE && j+jlen<sz && h[j+jlen]==hno; jlen++);

                            int d = min(ilen,jlen);
                            mv(j,i,d);
                            i+=d; j+=d;
                            ilen-=d;
                            totalD+=d;
                            //lastIdx[mi-1]+=d;
                            if(ilen==0) break;
                        } else j++;
                    }
                } else {
                    if(flag && h[i]==hno) lastIdx[mi-1]++;
                    else flag=false;
                    i++;
                }
            }
        }
        if(haveDone()) break;
        else if(totalD==0) {
            int mj,mjlen=0;
            for(int hno=1; hno<MAX_HOUSE; hno++) {
                int mi = rtar[hno];
                if(tarIdx[mi-1]==tarIdx[mi]) continue;

                for(int j=lastIdx[mi-1]; j<tarIdx[mi];) {
                    if(h[j]!=hno) {
                        int jlen=0;
                        for(; jlen<BLANK_SIZE && j+jlen<tarIdx[mi] && h[j+jlen]!=hno && jlen<sz-zp; jlen++);

                        if(jlen==0) break;
                        else {
                            if(mjlen<jlen) {
                                mjlen=jlen;
                                mj=j;
                            }
                            break;
                        }
                    } else j++;
                }
            }
            mv(mj,zp,mjlen);
        }
BRK:
        totalD=0;
    }
}

void cleanup() {
    m_init();
    findTarget();
    alignAll();
}
