#include <stdio.h>
inline int Strlen(char *a) { int i=0; while(a[i++]); return i-1; }
int ret[11000];
int x[103],y[103];
void mul(char *p,char *q,bool isMinus) {
	int pl=Strlen(p),ql=Strlen(q);
	for(int i=0; i<pl; i++) x[i]=p[i]-'0';
	for(int i=0; i<ql; i++) y[i]=q[i]-'0';

	for(int i=ql-1,u=0; i>=0; i--,u++) {
		for(int j=pl-1,v=0; j>=0; j--,v++) {
			ret[u+v]+=y[i]*x[j];
		}
	}
	for(int i=0;i<11000;i++) {
		if(ret[i]>=10) {
			ret[i+1]+=ret[i]/10;
			ret[i]%=10;
		}
	}
	int lastNZ=pl+ql-1;
	for(int i=lastNZ; i<11000; i++) {
		if(ret[i]>0) lastNZ=i+1;
	}
	if(!isMinus) putchar('-');
	for(int i=lastNZ-1; i>=0; i--) printf("%d",ret[i]);
	puts("");
}
inline void init() { for(int i=0; i<11000; i++) ret[i]=0; }
char p[103],q[103];
int main() {
	while(true) {
		init();
		scanf("%s",p);
		int plen=Strlen(p);
		if(plen==1 && p[0]=='0') return 0;
		else {
			scanf("%s",q);
			int qlen=Strlen(q);
			if(qlen==1 && q[0]=='0') {
				puts("0");
				continue;
			}
			if(p[0]=='-' && q[0]=='-') mul(p+1,q+1,true);
			else if(p[0]=='-') mul(p+1,q,false);
			else if(q[0]=='-') mul(p,q+1,false);
			else mul(p,q,true);
		}
	}

	return 0;
}
