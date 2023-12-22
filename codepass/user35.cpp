#include <stdio.h>
#include <stdlib.h>
#include <cassert>
#define MAX_STOCK_LEN 10
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;
const uint HASH_MAX = (1U<<17);
const int MAX_N = 100000;

template <typename T> inline T max(const T & x, const T & y) { return x>y?x:y; }
template <typename T> inline T min(const T & x, const T & y) { return x<y?x:y; }
template <typename T> inline void swap(T & x, T & y) { T tmp = x; x = y; y = tmp; }
inline int str_cmp(const char *s1, const char *s2) {
	int i=0; for(; s1[i] && s2[i]; i++) {
		if(s1[i]!=s2[i]) return s1[i]-s2[i];
	}
	return s1[i]-s2[i];
}
inline void str_cpy(char *dest, const char * src) {
	int i=0; for(; src[i]; i++) { dest[i] = src[i]; }
	dest[i]=0;
}

template <typename T>
struct Vector{
	T *v;
	int idx,sz;
	Vector():v(NULL),idx(0),sz(0) {}
	virtual ~Vector() {
		if(v) { free(v); v=NULL; }
		idx=sz=0;
	}

	inline void clear() { idx=0; }
	inline void expand(int fsz) {
		if(sz==0) {
			v = (T*)malloc(fsz*sizeof(T));
			sz = fsz;
		}
		else {
			T *tmp = NULL;
			while(true) {
				tmp = (T*)realloc(v, fsz*sizeof(T));
				if(tmp) { v = tmp; break; }
			}
			sz = fsz;
		}
	}
	inline void push_back(const T & x) {
		if(idx>=sz) expand(sz==0?2:(sz<<1));
		v[idx++] = x;
	}
	inline void resize(int fsz) { if(sz<fsz) expand(fsz); }
	inline int size() const { return idx; }
	inline bool empty() const { return idx==0; }
	inline T& operator[](int at) { return v[at]; }
	inline T& back() { return v[idx-1]; }
};

int I[MAX_N+1], rI[MAX_N+1];
char names[MAX_N+1][MAX_STOCK_LEN+1];
int prices[MAX_N+1];

void msort(char (*names)[MAX_STOCK_LEN+1], int s, int e) {
	if(s+1==e) return;
	int m = (s+e)>>1;
	msort(names, s,m); msort(names, m,e);

	int i=s, j=m, k=s;
	while(i<m && j<e) {
		if(str_cmp(names[I[i]], names[I[j]])<0) rI[k++] = I[i++];
		else rI[k++] = I[j++];
	}
	while(i<m) rI[k++] = I[i++];
	while(j<e) rI[k++] = I[j++];
	for(i=s; i<e; i++) I[i]=rI[i];
}

struct HashNode{
	ull hashVal;
	int real_idx, seg_idx;
	HashNode():hashVal(-1) {}
	HashNode(ull hashVal, int real_idx, int seg_idx):hashVal(hashVal), real_idx(real_idx), seg_idx(seg_idx) {}
	bool operator==(const HashNode & rhs) const {
		return hashVal == rhs.hashVal;
	}
};

const HashNode NA;
struct HashTable{
	Vector<HashNode> v[HASH_MAX+1];

	void clear() {
		for(int i=0; i<=HASH_MAX; i++) v[i].clear();
	}

	ull hashing_ull(const char *s) {
		if(s==NULL || s[0]==0) return 0;
		ull ret = 0ULL;
		for(int i=0; s[i]; i++) {
			ret*=29ULL;
			ret+=s[i]-'a';
		}
		ret++;
		return ret;
	}
	uint conv_hashing(ull hashVal) const {
		if(hashVal==0) return 0;
		//return hashVal & (HASH_MAX-1);
		uint hashIdx = (hashVal&(HASH_MAX-1))+1U;
		if(hashIdx > HASH_MAX) hashIdx=1ULL;
		return hashIdx;
	}

	HashNode& regi(const char *s, int real_idx, int seg_idx) {
		ull hashVal = hashing_ull(s);
		uint hashIdx = conv_hashing(hashVal);
		v[hashIdx].push_back(HashNode(hashVal, real_idx, seg_idx));
		return v[hashIdx].back();
	}

	const HashNode& search(const char *s) {
		ull hashVal = hashing_ull(s);
		uint hashIdx = conv_hashing(hashVal);
		if(v[hashIdx].empty()) return NA; //Not Available
		if(v[hashIdx].size() == 1) return v[hashIdx][0];
		for(int i=0; i<v[hashIdx].size(); i++) {
			if(v[hashIdx][i].hashVal == hashVal) {
				if(str_cmp(names[v[hashIdx][i].seg_idx],s) == 0) {
					return v[hashIdx][i];
				}
			}
		}
		return NA;
	}
};

static int N, SEG_MAX;
HashTable htab;
const int inf = 0x3f3f3f3f;

struct Info{
	int mx, idx; //idx is real_idx
	Info():mx(-inf),idx(inf){}
	Info(int mx, int idx):mx(mx),idx(idx) {}
	bool operator>(const Info & rhs) const {
		if(mx == rhs.mx) return idx<rhs.idx;
		return mx>rhs.mx;
	}
};

Vector<int> seg_price, lazy;
Vector<Info> seg_mx;

void init(int N, char names[][MAX_STOCK_LEN + 1], int prices[])
{
	htab.clear();
	::N = N+1;
	::SEG_MAX = ::N*4+1;//::N*4+1;
	for(register int i=0; i<N; i++) I[i]=i;
	msort(names, 0, N);
	for(register int i=0; i<N; i++) rI[i+1]=I[i];

	//I[th] = real_idx -> I[th+1] = real_idx
	for(int th=0; th<N; th++) {
		str_cpy(::names[th+1], names[I[th]]);
		::prices[th+1] = prices[I[th]];
		htab.regi(::names[th+1], I[th], th+1);
	}

	seg_price.clear(); seg_price.resize(::SEG_MAX);
	seg_mx.clear(); seg_mx.resize(::SEG_MAX);
	lazy.clear(); lazy.resize(::SEG_MAX);

	for(int i=0; i<(::SEG_MAX); i++) {
		lazy[i]=seg_price[i]=0;
		seg_mx[i]=Info(-inf,inf);
	}
}

inline void push_down(int r, int s, int e) {
	if(lazy[r]) {
		if(s+1!=e) {
			lazy[r<<1] += lazy[r];
			lazy[(r<<1)+1] += lazy[r];
		}
		seg_price[r] += lazy[r];
		lazy[r]=0;
	}
}
void update(int r, int s, int e, int qs, int qe, int val) {
	push_down(r,s,e);
	if(e<=qs || qe<=s) return;
	if(qs<=s && e<=qe) {
		lazy[r] += val;
		push_down(r,s,e);
		return;
	}
	int m = (s+e)>>1;
	update(r<<1,s,m,qs,qe,val);
	update((r<<1)+1,m,e,qs,qe,val);
}

Info query(int r, int s, int e, int qs, int qe, bool goTerm) {
	push_down(r,s,e);
	if(e<=qs || qe<=s) return Info();
	if(s+1==e) return seg_mx[r] = Info(seg_price[r], rI[s]);
	if(!goTerm && qs<=s && e<=qe) return seg_mx[r];

	int m = (s+e)>>1;
	return seg_mx[r] = max(query(r<<1,s,m,qs,qe,goTerm), query((r<<1)+1,m,e,qs,qe,goTerm));
}

void change(char from[], char to[], int priceDiff)
{
	int fidx = htab.search(from).seg_idx;
	int tidx = htab.search(to).seg_idx;
	if(fidx>tidx) swap(fidx,tidx);
	update(1,1,N,fidx,tidx+1,priceDiff);
}

int getidx(int r, int s, int e, int q) {
	push_down(r,s,e);
	if(q<s || e<=q) return 0;
	if(s+1==e) return r;
	int m=(s+e)>>1;
	return getidx(r<<1,s,m,q)+getidx((r<<1)+1,m,e,q);
}
int getPrice(char name[])
{
	int tidx = htab.search(name).seg_idx;
	//query(1,1,N,tidx,tidx+1,false);
	int ridx = getidx(1,1,N,tidx);
	if(lazy[ridx]>=0) {
		seg_price[ridx]+=lazy[ridx];
		lazy[ridx]=0;
	}
	return prices[tidx] + seg_price[ridx];
}

int getMostIncreased(char from[], char to[])
{
	int fidx = htab.search(from).seg_idx;
	int tidx = htab.search(to).seg_idx;
	if(fidx>tidx) swap(fidx,tidx);
	Info info = query(1,1,N,fidx,tidx+1,true);
	return info.idx;
}
