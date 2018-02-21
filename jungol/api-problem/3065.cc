/**************************************************************
    Problem: 3065
    User: sency90
    Language: C++
    Result: Success
    Time:13 ms
    Memory:1208 kb
****************************************************************/


#include <stdio.h>
int block[3][3],tmp[3][3],board[30001];
int bin[3],lastH=0,fullPat;
inline void rotate(int k) {
	if(k==0) return;
	for(int i=2; i>=0; i--) {
		for(int j=0; j<3; j++) {
			tmp[2-j][i]=block[i][j];
		}
	}
	for(int i=2; i>=0; i--) {
		for(int j=0; j<3; j++) {
			block[i][j]=tmp[i][j];
		}
	}
	rotate(k-1);
}
inline void makeBinary() {
	for(int i=0; i<3; i++) {
		bin[i]=0;
		for(int j=2; j>=0; j--) {
			bin[i]<<=1;
			bin[i]|=block[i][j];
		}
	}
	for(int i=0,k=0; k<3; k++) {
		if(bin[i]==0) {
			for(int j=i; j<2; j++) {
				bin[j]=bin[j+1];
				bin[j+1]=0;
			}
		} else i++;
	}
}
inline void shiftLeftandMove(int s) {
	bool haveToShift=true;
	for(int i=0; i<3; i++) {
		if((bin[i]&1) != 0) {
			haveToShift = false;
			break;
		}
	}
	if(haveToShift) {
		for(int i=0; i<3; i++) bin[i]>>=1;
		shiftLeftandMove(s);
	} else for(int i=0; i<3; i++) bin[i]<<=s;
}
inline void chkLim(int N) {
	int pat = ~fullPat;
	bool haveToShift=false;
	for(int i=0; i<3; i++) {
		if((pat&bin[i])!=0) {
			haveToShift=true;
			break;
		}
	}
	if(haveToShift) {
		for(int i=0; i<3; i++) bin[i]>>=1;
		chkLim(N);
	}
}
inline int rmLine(int h) {
	for(int i=0,k=0; i<3 && k<3; k++) {
		if(board[i+h]==fullPat) {
			for(int j=i+h; j<=lastH+2; j++) {
				board[j]=board[j+1];
				board[j+1]=0;
			}
		} else i++;
	}
	for(int i=lastH+3; i>=h; i--) {
		if(board[i]==0) continue;
		return i+1;
	}
	return h;
}

int main() {
	int n,m; scanf("%d%d",&n,&m);
	fullPat=(1<<n)-1;
	while(m--) {
		for(int i=2; i>=0; i--) {
			for(int j=0; j<3; j++) {
				scanf("%d",&block[i][j]);
			}
		}
		int k,s; scanf("%d%d",&k,&s);
		rotate(k);
		makeBinary();
		shiftLeftandMove(s);
		chkLim(n);

		int okH=lastH;
		for(int h=lastH; h>=0; h--) {
			bool isOK=true;
			for(int j=0; j<3 && h+j<=lastH; j++) {
				if((board[h+j]&bin[j]) != 0) {
					isOK=false;
					break;
				}
			}
			if(isOK) okH=h;
			else break;
		}
		for(int i=0; i<3; i++) {
			board[okH+i]|=bin[i];
		}

		lastH=rmLine(okH);
	}
	printf("%d\n",lastH);
	return 0;
}
