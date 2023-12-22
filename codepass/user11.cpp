#define rint register int
int v[1000];
inline int bitcounts(int x) {
	rint cnt=0;
	for(rint i=0; i<12; i++) {
		if(x&1) cnt++;
		x>>=1;
	}
	return cnt;
}
bool isfirst = true;
int encoding(int x, int y){
	if(isfirst) {
		rint lim = 1<<12;
		rint cnt=0;
		for(rint i=(1<<6)-1; i<lim; i++) {
			if(bitcounts(i) == 6) v[cnt++] = i;
		}
		isfirst = false;
	}

	rint t=((v[x]^v[y])&v[x]), k=0;
	for(rint i=0; i<12; i++) {
		k++;
		if(t&1) break;
		t>>=1;
	}
	return k;
}
char answer(int p, int k){
	if(v[p] & (1<<(k-1))) return 'x';
	else return 'y';

}
