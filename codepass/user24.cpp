/// *****  user.cpp *****
static const int M = 50000000;

extern char virus_checkup(int n);
extern void culture(int n, int a, int b);
extern void clear(int n);

const int INTV = 512;
const int SEGEND = INTV<<2;
int seg[SEGEND];
inline int min(int x, int y) { return x<y?x:y; }
inline void update(int idx, int s, int e) {
	if(s+1==e) {
		culture(M+idx,s,s);
		return;
	}

	const int m=(s+e)>>1, l=(idx<<1), r=(idx<<1)+1;
	update(l,s,m); update(r,m,e);
	culture(M+idx, M+l, M+r);
}
inline int clean(int idx, int s, int e) {
	if(s+1==e) {
		clear(s);
		return s+1;
	}

	const int m=(s+e)>>1, l=(idx<<1), r=(idx<<1)+1;
	if(virus_checkup(M+l)) return clean(l,s,m);
	else return clean(r,m,e);
}
void test() {
	for(register int s=0; s<M; ) {
		register int e = min(s+INTV, M);
		update(1,s,e);
		if(virus_checkup(M+1)) s=clean(1,s,e);
		else s=e;
	}
}
