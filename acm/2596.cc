#include <stdio.h>
#include <string.h>
char dic[8][7] = {
	"000000",
	"001111",
	"010011",
	"011100",
	"100110",
	"101001",
	"110101",
	"111010"
};
int idic[8];
int ans[8];
int chg(const char * s) {
	int i, ret=0;
	for(i=0; s[i]; i++){
		ret |= (s[i]-'0');
		ret <<= 1;
	}
	return ret;
}
int chk(int d) {
	int i,t;
	for(i=0; i<8; i++) {
		t=d^idic[i];
		if(t==0 || ((t&-t)^t)==0) {
			return i;
		}
	}
	return -1;
}
int main() {
	char w[7];
	int i,n;
	for(i=0; i<8; i++) {
		idic[i] = chg(dic[i]);
	}
	scanf("%d", &n);

	for(i=0; i<n; i++) {
		scanf("%6s", w);
		ans[i] = chk(chg(w));
		if(ans[i]<0) {
			printf("%d\n", i+1);
			return 0;
		}
	}

	for(i=0; i<n; i++) {
		printf("%c", ans[i]+'A');
	}
	puts("");

	return 0;
}
