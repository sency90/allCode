#if 0

#define HOUSE_SIZE  20000
#define BLANK_SIZE   64
#define MAX_HOUSE   10
#define MAX_COUNT (HOUSE_SIZE * 2 * 50)
extern int gethouseSize();
extern int readhouse(int* blank,int address,int size);
extern int move(int from,int to,int size);

int sz, msz;
int h[HOUSE_SIZE];

inline int min(int x,int y) { return x<y?x:y; }
void m_init() {
    sz=gethouseSize();
    readhouse(h,0,sz);
}

int buf[BLANK_SIZE];
void m_move(int from,int to,int size) {
    move(from,to,size);
    for(int i=0; i<size; i++) buf[i]=h[to+i];
    for(int i=0; i<size; i++) h[to+i]=h[from+i];
    for(int i=0; i<size; i++) h[from+i]=buf[i];
}

void alignZero() {
    int s,len,zp=sz;
    for(s=0; s<sz;) {
        if(h[s]==0) {
            for(len=0; s+len<sz && len<BLANK_SIZE && h[s+len]==0; len++);
            if(s+len>=zp) break;

            int d = min(zp-(s+len), len);
            zp-=d;

            m_move(zp,s,d);
        } else s++;
    }
    for(s=sz-1; s>=0 && h[s]==0; s--);
    msz = min(BLANK_SIZE,sz-1-s);
}

void alignAll() {
    int start = 0;
    for(int i = 1; i < MAX_HOUSE;i++) {
        for(;h[start]==i; start++);

        for(int s=start; s<sz; ) {
            if(h[s] == i) {
                int len=0;
                for(; h[s+len]==i && len<msz && (s+len)<sz; len++);
                int d = min(s-start,len);

                m_move(start,sz - d,d);
                m_move(s,start,d);
                m_move(sz - d,s,d);

                start += d;
                s += d;
            } else s++;
        }
    }
}

void cleanup() {
    m_init();
    alignZero();
    alignAll();
    return;
}

#endif
