#include <stdio.h>
#define MAX_STOCK_LEN 10
#define HASH_MAX 10000000
#define MAX_N 100000
#define SEG_N (MAX_N*4)

bool haveToUpdate = false;
const int inf = 0x3f3f3f3f;
static int N;
char namesDic[MAX_N+1][11];
int hashDic[HASH_MAX+1];
int init_price[MAX_N+1];
int seg_price[SEG_N+1];
int lazy[SEG_N+1];
struct Info{
    int val, idx;
    Info(){}
    Info(int val, int idx):val(val),idx(idx) {}
    inline bool operator>(const Info & rhs) const {
        if(val == rhs.val) return idx < rhs.idx;
        else return val > rhs.val;
    }
    void print() const {
        //printf("Info(val:%d, idx:%d)\n", val, idx);
    }
};
Info seg_max[MAX_N*4+1];

template <typename T>
T max(T x, T y) { return x>y?x:y; }

inline void swap(int & x, int & y) { x^=y; y^=x; x^=y; }

void str_cpy(char * dest, const char * src) { int i=0; while(src[i]) { dest[i] = src[i]; i++; } dest[i] = 0; }
int str_cmp(const char * s1, const char * s2) {
    register int i=0;
    while(s1[i] && s2[i]) {
        if(s1[i]!=s2[i]) return s1[i]-s2[i];
        i++;
    }
    if(s1[i]) return 1;
    else if(s2[i]) return -1;
    else return 0;
}

int regi_hash(const char *s) {
    unsigned int ret = s[0]-'a';
    for(int i=1; s[i]; i++) {
        int c = s[i]-'a';
        ret *= 29;
        ret += s[i]-'a';
    }
    ret %= HASH_MAX;
    ret++;
    while(hashDic[ret]!=0) {
        ret++;
        if(ret>HASH_MAX) ret=1;
    }
    return ret;
}
int hash(const char *s) {
    unsigned int ret = s[0]-'a';
    for(int i=1; s[i]; i++) {
        int c = s[i]-'a';
        ret *= 29;
        ret += s[i]-'a';
    }
    ret %= HASH_MAX;
    ret++;

    while(str_cmp(namesDic[hashDic[ret]], s)!=0) {
        //printf("hash %d collision: [%s] [%s]\n", ret, namesDic[hashDic[ret]], s); //for debug
        ret++;
        if(ret>HASH_MAX) ret=1;
    }
    return ret;
}
int A[MAX_N+1], B[MAX_N+1];
void msort(int s, int e, const char (*names)[MAX_STOCK_LEN+1]) {
    if(s+1 == e) return;

    int m= (s+e)>>1;
    msort(s,m,names), msort(m,e,names);

    int i=s, j=m, k=s;
    while(i<m && j<e) {
        int cmp = str_cmp(names[A[i]],names[A[j]]);
        if(cmp<0) B[k++] = A[i++];
        else if(cmp>0) B[k++] = A[j++];
    }
    while(i<m) B[k++] = A[i++];
    while(j<e) B[k++] = A[j++];

    for(i=s; i<e; i++) A[i] = B[i];
}
void init(int N, char names[][MAX_STOCK_LEN + 1], int prices[])
{
    for(register int i=0; i<=HASH_MAX; i++) hashDic[i] = 0;
    for(int i=0; i<N; i++) A[i] = i;
    msort(0,N,names);
    //puts("***************************************");
    //for(int i=0; i<N; i++) {
    //    printf("[%d]: %s\n", i, names[i]);
    //}
    //puts("***************************************");
    //for(int i=0; i<N; i++) {
    //    printf("%s: %d\n", names[A[i]], prices[A[i]]);
    //}
    //puts("***************************************");
    //for(int i=0; i<N; i++) B[A[i]+1] = i;
    haveToUpdate = true;
    for(int i=0; i<N; i++) {
        int h = regi_hash(names[A[i]]);
        hashDic[h] = i+1;
    }
    for(int i=0; i<N; i++) {
        str_cpy(namesDic[i+1], names[A[i]]);
    }
    for(int i=0; i<N; i++) {
        init_price[i+1] = prices[A[i]];
    }
    ::N = N+1;

    for(int i=0; i<=SEG_N; i++) {
        seg_max[i].val = -inf;
        seg_price[i] = 0;
        lazy[i] = 0;
    }
}

void push_down(int idx, int s, int e) {
    if(lazy[idx]) {
        if(s+1!=e) {
            lazy[idx<<1]+=lazy[idx];
            lazy[(idx<<1)+1]+=lazy[idx];
        }
        seg_price[idx]+=lazy[idx];
        lazy[idx]=0;
    }
}

void update_price(int idx, int s, int e, int qs, int qe, int val) {
    push_down(idx,s,e);
    if(qe<=s || e<=qs) return; //Info(-inf,s);
    else if(qs<=s && e<=qe) {
        lazy[idx]+=val;
        push_down(idx,s,e);
        return;
    }
    //else if(s+1==e) {
    //    seg_price[idx] += val;
    //    return;
    //}
    int m = (s+e)>>1;
    update_price(idx<<1,s,m,qs,qe,val);
    update_price((idx<<1)+1,m,e,qs,qe,val);
}

int query_price(int idx, int s, int e, int q) {
    push_down(idx,s,e);
    if(q<s || e<=q) return 0;
    else if(s+1 == e) return seg_price[idx];

    int m = (s+e)>>1;
    return query_price(idx<<1,s,m,q)+query_price((idx<<1)+1,m,e,q);
}

void change(char from[], char to[], int priceDiff)
{
    //printf("from:%s, to:%s\n", from, to);
    int from_idx = hashDic[hash(from)];
    int to_idx = hashDic[hash(to)];
    if(from_idx>to_idx) swap(from_idx, to_idx);
    //printf("-> hashed_from:%s, hashed_to:%s\n\n", namesDic[from_idx], namesDic[to_idx]);
    haveToUpdate = true;

    //printf("update: [%d,%d] val:%d\n", from_idx, to_idx, priceDiff);
    update_price(1,1,N,from_idx, to_idx+1, priceDiff);
}

Info update_max(int idx, int s, int e) {
    push_down(idx,s,e);
    if(s+1 == e) {
        return seg_max[idx] = Info(seg_price[idx],A[s-1]);
    }

    int m = (s+e)>>1;
    return seg_max[idx] = max(update_max(idx<<1,s,m), update_max((idx<<1)+1,m,e));
}

Info query_max(int idx, int s, int e, int qs, int qe) {
    if(qe<=s || e<=qs) return Info(-inf, inf);
    else if(qs<=s && e<=qe) {
        //printf("query_max(%d,%d,%d,%d,%d) -> ",idx,s,e,qs,qe);
        //seg_max[idx].print();
        return seg_max[idx];
    }

    int m = (s+e)>>1;
    return max(query_max(idx<<1,s,m,qs,qe), query_max((idx<<1)+1,m,e,qs,qe));
}
 
int getPrice(char name[])
{
    int idx = hashDic[hash(name)];
    int res = init_price[idx] + query_price(1,1,N,idx);
    //printf("getPrice(%s) -> %d\n", name, res);
    return res;
}
 
int getMostIncreased(char from[], char to[])
{
    int from_idx = hashDic[hash(from)];
    int to_idx = hashDic[hash(to)];
    if(from_idx>to_idx) swap(from_idx, to_idx);
    //printf("from:%s, from_idx:%d, to:%s, to_idx:%d\n", from, from_idx, to, to_idx);
    if(haveToUpdate) {
        update_max(1,1,N);
        haveToUpdate = false;
    }
    Info info = query_max(1,1,N,from_idx, to_idx+1);
    //int ans = from_idx;
    //if(info.val != -inf) ans = info.idx;
    //printf("getMostIncreased(%s, %s) -> %d", from, to, info.idx);
    //info.print();

    //for(int i=8; i<=15; i++) {
    //    printf("seg_max[%d]: ", i);
    //    seg_max[i].print();
    //}
    return info.idx;
}
