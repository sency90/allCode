#include <algorithm>
#include <cstring>
using namespace std;
const int inf = 0x3f3f3f3f;
int block[30000][4][4];
struct Info{
	int idx,h,hash;
	Info(){}
	Info(int idx, int h, int hash):idx(idx),h(h),hash(hash){}

	bool operator<(const Info &rhs) const {
		if(hash == rhs.hash) return h>rhs.h;
		else return hash<rhs.hash;
	}

	void print() {
		printf("idx:%d height:%d hash:%d\n",idx,h,hash);
	}
};

inline int lHashing(const int (*block)[4]) {
	int ret=0;
	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++) {
			ret*=3;
			ret+=block[i][j];
		}
	}
	return ret;
}

inline int rHashing(const int (*block)[4]) {
	int ret=0;
	for(int i=0; i<4; i++) {
		for(int j=3; j>=0; j--) {
			ret*=3;
			ret+=block[i][j];
		}
	}
	return ret;
}

int tmp[4][4];
inline void rotate(int (*block)[4]) {
	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++) {
			tmp[j][3-i] = block[i][j];
		}
	}
	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++) {
			block[i][j]=tmp[i][j];
		}
	}
}

Info L[30000],R[30000];
int lBlock[4][4], rBlock[4][4];
bool chk[30000];
int makeTree(int module[][4][4]) {
	int ans = 0;

	for(int z=0; z<30000; z++) {
		int mxh=0, mnh=inf;
		for(int i=0; i<4; i++) {
			for(int j=0; j<4; j++) {
				mxh = max(mxh, module[z][i][j]);
				mnh = min(mnh, module[z][i][j]);
			}
		}

		for(int i=0; i<4; i++) {
			for(int j=0; j<4; j++) {
				lBlock[i][j]=module[z][i][j]-mnh;
				rBlock[i][j]=mxh-module[z][i][j];
			}
		}

		int leftHash=lHashing(lBlock), rightHash=rHashing(rBlock);
		for(int i=0; i<3; i++) {
			rotate(lBlock); rotate(rBlock);
			leftHash=min(leftHash,lHashing(lBlock));
			rightHash=min(rightHash,rHashing(rBlock));
		}
		L[z] = Info(z,mnh,leftHash);
		R[z] = Info(z,mxh,rightHash);
	}

	sort(L,L+30000);
	sort(R,R+30000);

	memset(chk,false,sizeof(chk));
	int prv=0;
	for(int i=0; i<30000; i++) {
		int lo=0,hi=29999;
		if(chk[L[i].idx]) continue;
		chk[L[i].idx]=true;
		while(lo<=hi) {
			int mid = (lo+hi)>>1;
			if(R[mid].hash < L[i].hash) lo=mid+1;
			else hi=mid-1;
		}

		while(chk[R[lo].idx]) {
			lo++;
			if(lo>=30000) break;
			if(R[lo].hash != L[i].hash) break;
		}
		if(lo>=30000) continue;
		if(R[lo].hash == L[i].hash) {
			ans+=L[i].h+R[lo].h;
			chk[R[lo].idx]=true;
		}
	}
	return ans;
}
