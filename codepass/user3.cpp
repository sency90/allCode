#include <stdio.h>

typedef long long ll;
char s[65];
int strlen(const char *s) {
	int len=0;
	while(s[len]) len++;
	return len;
}

int num(char c) {
	if((int)(c-'0') < 10) return c-'0';
	else return c-'A'+10;
}

char cnum(int x) {
	if(x<10) return x+'0';
	else return x-10+'A';
}

ll chg(const char *s, ll a) {
	ll ret=0LL, val=1LL;
	int len = strlen(s);
	for(int i=len-1; i>=0; i--) {
		ret += num(s[i]) * val;
		val *= a;
	}
	return ret;
}

void swap(char &a, char &b) {
	char c = a;
	a = b;
	b = c;
}

char ans[65];
const char * rchg(ll x, ll b) {
	int len=0;
	while(x) {
		ans[len++] = cnum(x%b);
		x/=b;
	}
	ans[len]=0;

	int lim = len/2;
	for(int i=0; i<lim; i++) {
		swap(ans[i], ans[len-i-1]);
	}
	return ans;
}
int main() {
	int a,b;
	while(true) {
		scanf("%d", &a);
		if(a==0) break;

		scanf("%s %d", s, &b);
		ll x = chg(s,a);
		if(x==0LL) puts("0");
		else printf("%s\n", rchg(x,b));
	}
	return 0;
}


