#include <cstdio>
using namespace std;
char g[9];
char gear[4][26*8+1];
char *p[4];
void Strcpy(char *dst, const char *src) {
	while(*dst++ = *src++);
}
void rotateR(int th, int dir) {
	if(th<3 && (p[th][2]^p[th+1][6])==1) {
		rotateR(th+1, -dir);
		if(-dir>0) p[th+1]--;
		else p[th+1]++;
	}
}
void rotateL(int th, int dir) {
	if(th>0 && (p[th][6]^p[th-1][2])==1) {
		rotateL(th-1, -dir);
		if(-dir>0) p[th-1]--;
		else p[th-1]++;
	}
}
int main() {
	for(int i=0; i<4; i++) {
		scanf("%s", g);
		for(int j=0; j<26; j++) {
			Strcpy(gear[i]+8*j,g);
		}
		p[i] = gear[i]+8*13;
	}

	int k; scanf("%d", &k);
	for(int i=0; i<k; i++) {
		int th, dir;
		scanf("%d%d", &th, &dir);
		rotateR(th-1, dir);
		rotateL(th-1, dir);
		if(dir>0) p[th-1]--;
		else p[th-1]++;
	}
	int ans=0;
	for(int i=3; i>=0; i--) {
		ans <<= 1;
		ans |= (p[i][0]-'0');
	}
	printf("%d\n", ans);
	return 0;
}
