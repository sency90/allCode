#include <stdio.h>
typedef long long ll;
const int N = 100;
const ll MOD = 1e8;

inline int max(int x, int y) { return x>y?x:y; }
inline int min(int x, int y) { return x<y?x:y; }

const int BASE = 10;

struct BigInt{
	ll room[N];
	int sign, len;

	void print() const {
		printf("len: %d\n", len);
		if(sign) printf("-");

		if(len-1>=0) printf("%lld ", room[len-1]);
		for(int i=len-2; i>=0; i--) {
			printf("%08lld ", room[i]);
		}
		puts("");
	}

	BigInt() { init(); }
	BigInt(int x) {
		init();
		room[0] = x;
	}
	BigInt& operator=(int x) {
		init();
		room[0] = x;
		return *this;
	}
	BigInt(const BigInt & rhs) {
		this->sign = rhs.sign;
		this->len = rhs.len;
		register int i=0;
		for(; i<rhs.len; i++) room[i] = rhs.room[i];
		for(; i<N; i++) room[i] = 0LL;
	}
	BigInt& operator=(const BigInt & rhs) {
		this->sign = rhs.sign;
		this->len = rhs.len;
		register int i=0;
		for(; i<rhs.len; i++) room[i] = rhs.room[i];
		for(; i<N; i++) room[i] = 0LL;
		return *this;
	}

	void init() {
		sign=0; len=1; //sign=0:positive, 1:negative
		for(register int i=0; i<N; i++) room[i] = 0;
	}

	int cmp(const BigInt & rhs) const {
		if(len < rhs.len) return -1;
		else if(len > rhs.len) return 1;
		for(register int i=len-1; i>=0; i--) {
			if(room[i] < rhs.room[i]) return -1;
			else if(room[i] > rhs.room[i]) return 1;
		}
		return 0;
	}

	bool isZero() const {
		return len==1 && room[0]==0LL;
	}

	void add(BigInt & ret, const BigInt & lhs, const BigInt & rhs) {
		int mxlen = max(lhs.len, rhs.len);
		for(register int i=0; i<mxlen; i++) {
			ret.room[i] += lhs.room[i] + rhs.room[i];
			if(ret.room[i] >= MOD) {
				ret.room[i]-=MOD;
				ret.room[i+1]++;
			}
		}
		ret.len = mxlen;
		if(ret.room[ret.len]) ret.len++;
	}

	//lhs must be greater than rhs.
	void sub(BigInt & ret, const BigInt & lhs, const BigInt & rhs) {
		int mxlen = lhs.len;
		for(register int i=0; i<mxlen; i++) {
			ret.room[i] += lhs.room[i] - rhs.room[i];
			if(ret.room[i]<0LL) {
				ret.room[i] += MOD;
				ret.room[i+1]--;
			}
		}
		while(mxlen>=2 && ret.room[mxlen-1]==0) mxlen--;
		ret.len = mxlen;
	}

	BigInt& operator+=(const BigInt & rhs) {
		BigInt ret;
		if(sign == rhs.sign) add(ret, *this, rhs), ret.sign=this->sign;
		else {
			int res = cmp(rhs);
			if(res<0) sub(ret, rhs, *this), ret.sign=rhs.sign;
			else if(res>0) sub(ret, *this, rhs), ret.sign=this->sign;
			else { init(); return *this; }
		}
		return *this = ret;
	}

	//lhs must be greater than rhs.
	BigInt& operator-=(const BigInt & rhs) {
		this->sign^=1;
		*this += rhs;
		this->sign^=1;
		return *this;
	}

	void mul(BigInt& ret, const BigInt & lhs, const BigInt & rhs) {
		for(register int i=0; i<lhs.len; i++) {
			for(register int j=0; j<rhs.len; j++) {
				ret.room[i+j] += lhs.room[i] * rhs.room[j];
			}
		}
		ret.len = lhs.len + rhs.len - 1;
		for(int i=0; i<=ret.len; i++) {
			if(ret.room[i]>=MOD) {
				ret.room[i+1] += ret.room[i]/MOD;
				ret.room[i] %= MOD;
			}
		}
		if(ret.room[ret.len]) ret.len++;
		ret.sign = lhs.sign ^ rhs.sign;
	}
	BigInt& operator*=(const BigInt & rhs) {
		BigInt ret;
		mul(ret, *this, rhs);
		return *this=ret;
	}

	void toString(char * s) const {
		if(isZero()) s[0]='0', s[1]=0;
		else {
			char c[8];
			if(sign) s[0]='-';
			register int sidx = sign;
			if(len-1>=0) {
				ll tmp = room[len-1];
				register int j=0;
				while(tmp) {
					c[j++] = (tmp%BASE)+'0';
					tmp/=BASE;
				}
				for(--j; j>=0; j--) s[sidx++] = c[j];
			}

			for(register int i=len-2; i>=0; i--) {
				ll tmp = room[i];
				register int j=0;
				for(; j<8; j++) {
					c[j] = (tmp%BASE)+'0';
					tmp/=BASE;
				}
				for(--j; j>=0; j--) s[sidx++] = c[j];
			}
			s[sidx]=0;
		}
	}
};


int L;
char * str;
int strlen(const char * s) {
	int ret = 0;
	while(s[ret]) ret++;
	return ret;
}
inline bool isdigit(char c) {
	return '0'<=c && c<='9';
}
inline int mkdigit(int & idx) {
	while(str[idx] == ' ') { idx++; continue; }
	int ret = 0;
	while(isdigit(str[idx])) {
		ret *= BASE;
		ret += (str[idx++]-'0');
	}
	while(str[idx] == ' ') { idx++; continue; }
	return ret;
}

BigInt ex(int &);
BigInt term(int &);
BigInt factor(int &);

//ex = term {'+'|'-', term}
BigInt ex(int & idx) {
	while(str[idx] == ' ') { idx++; continue; }
	BigInt ret = term(idx);
	while(idx<L) {
		char sym = str[idx];
		if(sym == '+') ret += term(++idx);
		else if(sym == '-') ret -= term(++idx);
		else return ret;
	}
	while(str[idx] == ' ') { idx++; continue; }
	return ret;
}
//term = factor {'*'|'/', factor}
BigInt term(int & idx) {
	while(str[idx] == ' ') { idx++; continue; }
	BigInt ret = factor(idx);
	while(idx<L) {
		char sym = str[idx];
		if(sym == '*') ret *= factor(++idx);
		//else if(sym == '/') ret /= factor(++idx);
		else return ret;
	}
	while(str[idx] == ' ') { idx++; continue; }
	return ret;
}
//factor = (['+'|'-'], digit) | ( '(', ex, ')' )
BigInt factor(int & idx) {
	BigInt ret;
	while(str[idx] == ' ') { idx++; continue; }
	if(str[idx]=='+') ret = mkdigit(++idx);
	else if(str[idx]=='-') ret = -mkdigit(++idx);
	else if(isdigit(str[idx])) ret = mkdigit(idx);
	else if(str[idx] == '(') {
		ret = ex(++idx);
		idx++;
	}
	while(str[idx] == ' ') { idx++; continue; }
	return ret;
}

void test(char form[10000], char result[10000]) {
	str = form;
	L = strlen(str);
	int idx = 0;
	BigInt res = ex(idx);
	res.toString(result);
	//printf("my result: %s\n", result);
	//res.print();
}
