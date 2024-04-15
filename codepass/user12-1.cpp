typedef unsigned long long ull;
typedef unsigned int uint;

bool isRegistered(ull h, ull *hmap, int hmap_cnt) {
	for(int j=0; j<hmap_cnt; j++) {
		if(hmap[j] == h) {
			return true;
		}
	}
	return false;
}
ull hashing(const char * s, int & i) {
	ull ret = 0ULL;
	for(; s[i]!=' '; i++) {
		ret *= 27ULL;
		ret += s[i]-'a';
	}
	return ret;
}
ull hashing(const char * s, int & i, int & len) {
	ull ret = 0ULL;
	len = 0;
	for(; s[i]!=' '; i++, len++) {
		ret *= 27ULL;
		ret += s[i]-'a';
	}
	return ret;
}

void str_cpy(char * dest, const char * src) {
	int i=0; for(; src[i]!=' '; i++) dest[i] = src[i];
	dest[i]=0;
}
int str_len(const char * s) {
	int ret = 0;
	while(s[ret]) ret++;
	return ret;
}

void msort(int s, int e, ull *hmap, int *o2i, int *tmp) {
	int m= (s+e)/2;
	msort(s,m,hmap,o2i,tmp); msort(m,e,hmap,o2i,tmp);

	int i=s, j=m, k=s;
	while(i<m && j<e) {
		if(hmap[o2i[i]]<hmap[o2i[j]]) tmp[k++] = o2i[i++];
		else tmp[k++] = o2i[j++];
	}
	while(i<m) tmp[k++] = o2i[i++];
	while(j<e) tmp[k++] = o2i[j++];

	for(i=s; i<e; i++) o2i[i] = tmp[i];
}

void write(uint x, int bit, char * enc_str, int & encn_bit) {
	uint *p = (uint *)&enc_str[encn_bit>>3];

	*p |= ((x & ((1<<bit)-1)) << (encn_bit&7));
	encn_bit += bit;
}

void regi_wordsbook(const char * word, int i, char *enc_str, int & encn_bit) {
	write(i, 10, enc_str, encn_bit);
	for(int i=0; word[i]; i++) {
		write(word[i]-'a', 5, enc_str, encn_bit);
	}
}

int bs(int s, int e, ull h, ull *hmap, int *o2i) {
	if(s+1==e) return s;
	int mid = (s+e)/2;
	if(hmap[o2i[mid]] >= h) return bs(s, mid+1, h, hmap, o2i);
	else return bs(mid+1, e, h, hmap, o2i);
}
int encode(char* enc_str, char* str, int STRN) {
	ull hmap[1024];
	int hmap_cnt=0;
	int o2i[1024], tmp[1024];
	char dic[1024][8];
	int len_s[9];
	int encn_bit=0;
	int prev_len = 1;

	for(int i=0; i<1024; i++) o2i[i]=i;
	for(int i=0; i<STRN; i++) {
		int j=i;
		ull h = hashing(str, i);
		if(isRegistered(h, hmap, hmap_cnt)) {
			hmap[hmap_cnt] = h;
			str_cpy(dic[hmap_cnt], str+j);
		}
	}

	msort(0, hmap_cnt, hmap, o2i, tmp);

	//1. 단어길이가 다른 시작점 index를 enc_str에 기록 (단어index 8bit * 7개)
	int prvlen = 1, len=1;
	len_s[1]=0;
	for(int o=0; o<hmap_cnt; o++) {
		len = str_len(dic[o2i[o]]);
		if(prvlen != len) {
			write(o, 8, enc_str, encn_bit);
			prvlen = len;
			len_s[len] = o;
			if(len == 7) break;
		}
	}
	len_s[len+1]=hmap_cnt;
	write(hmap_cnt, 8, enc_str, encn_bit);

	//2. 단어장을 기록 (단어번호 10bit | 단어 5~35bit)
	for(int o=0; o<hmap_cnt; o++) {
		regi_wordsbook(dic[o2i[o]], o2i[o], enc_str, encn_bit);
	}

	write(hmap_cnt, 14, enc_str, encn_bit);

	len = 0;
	for(int i=0; i<STRN; i++) {
		ull h = hashing(str, i, len);
		int idx = bs(len_s[len], len_s[len+1], h, hmap, o2i);
		write(idx, 10, enc_str, encn_bit);
	}
	return (encn_bit+7)>>3;
}
uint read(int bit, char *enc_str, int & encn_bit) {
	uint *p = (uint*)&enc_str[encn_bit>>3];
	int r = encn_bit&7;
	uint ret = (*p & (((1U<<bit)-1) << r)) >> r;
	encn_bit += bit;
	return ret;
}
void decode(char* dec_str, char* enc_str, int encn) {
	int len_s[9] = {0, };
	int encn_bit=0;
	for(int i=2; i<=8; i++) {
		len_s[i] = read(8, enc_str, encn_bit);
	}

	int dic[1024][7];
	int diclen[1024];
	for(int i=1; i<=7; i++) {
		for(int j=len_s[i]; j<len_s[i+1]; j++) {
			int dic_no = read(10, enc_str, encn_bit);
			for(int k=0; k<i; k++) {
				dic[dic_no][diclen[dic_no]++] = read(5, enc_str, encn_bit)+'a';
			}
		}
	}

	int hmap_cnt = read(14, enc_str, encn_bit);
	
}
