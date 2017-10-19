#include <stdio.h>
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

class Integer{
public:
	//operator overloading
	Integer& operator=(Integer &rhs) {
		this->sz = rhs.sz;
		for(int i=0; i<rhs.sz; i++) {
			this->room[i] = rhs.room[i];
		}
		this->p = rhs.p;
		return *this;
	}

private:
	//etc operations
	template <typename T> inline uint lower(T x) { return x&0xffffffff; }
	template <typename T> inline uint upper(T x) { return uint(x>>32); }
	inline void zip() {
		for(int i=sz-1; i>=1; i--) {
			if(room[i]==0) sz--;
			else break;
		}
	}
	inline int strlen(char *s) { int i=0; while(s[i++]); return i; }
	void stringToBinary(char *s) {
		int len = strlen(s);

	}

public:
	//constructor
	bool p;
	uint room[201];
	int sz;
	Integer():p(true),sz(1){ room[0]=0; }
	Integer(int x):p(x>=0),sz(1){ room[0]=x; }
	Integer(uint x):p(true),sz(1){ room[0]=x; }
	Integer(ll x):p(x>=0LL){
		room[0]=lower(x); room[1]=upper(x);
		sz=2; zip();
	}
	Integer(ull x):p(true) {
		room[0]=lower(x); room[1]=upper(x);
		sz=2; zip();
	}
	Integer(char *s) {
		p=true;
		if(s[0]=='+') stringToBinary(s+1);
		else if(s[0]=='-') {
			stringToBinary(s+1);
			*this = signSwitch();
		} else stringToBinary(s);
	}

private:
	//basic arithmetic operations
	Integer signSwitch() {
		zip();
		for(int i=0; i<sz; i++) room[i]=~room[i];

		uint carry=1;
		for(int i=0; i<sz; i++) {
			uint ori = room[i];
			room[i]+=carry;
			if(ori>room[i]) carry=1U;
			else break;
		}
		p^=1;
	}


};


int main(){

	return 0;
}
