#include <stdio.h>
char s[9];
bool sign=true;
int main() {
	scanf("%s",s);
	if(s[0]=='1') {
		sign=false;
		for(int i=0; i<8; i++) {
			if(s[i]=='1') s[i]='0';
			else s[i]='1';
		}
		s[7]++;
		for(int i=7; i>=0; i--) {
			if(i==0) s[i]='0';
			else if(s[i]=='2') {
				s[i]='0';
				s[i-1]++;
			}
		}
	}
	int res=0;
	for(int i=0; i<8; i++) {
		res<<=1;
		res+=(s[i]-'0');
	}
	if(sign) printf("%d\n",res);
	else printf("%d\n",-res);
	return 0;
}
