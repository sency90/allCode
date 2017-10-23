#define HOUSE_SIZE 20000
#define BLANK_SIZE 64
#define MAX_HOUSE 10
#define MAX_COUNT (HOUSE_SIZE*2*50)
#include <cstdio>
#include <cassert>
using namespace std;

extern int gethouseSize();
extern int readhouse(int *blank, int address, int size);
extern int move(int from, int to, int size);

int sz,msz;
int h[HOUSE_SIZE];

inline int min(int x, int y) { return x<y?x:y; }
inline void m_init() {
	sz=gethouseSize();
	printf("real size: %d\n", sz);
	readhouse(h,0,sz);
}

int buf[BLANK_SIZE];
inline void mv(int from, int to, int size) {
	move(from,to,size);
	for(int i=0; i<size; i++) {
		buf[i]=h[i+from];
		h[i+from]=0;
	}
	for(int i=0; i<size; i++) {
		h[i+to]=buf[i];
	}
}

inline int alignZero() {
	for(int i=0,zp=sz,len=0; i<zp;) {
		if(h[i]==0) {
			for(len=0; i+len<zp && len<BLANK_SIZE && h[i+len]==0; len++);
			if(i+len==zp) break;
			int mn = min(zp-(i+len),len);
			//if(mn==0) break;
			zp-=mn;
			mv(zp,i,mn);
		} else i++;
	}

	int zp=0;
	for(int i=sz-1; i>=0 && h[i]==0; i--) zp=i;
	msz = min(sz-zp,BLANK_SIZE);

	printf("sz:%d, zp:%d\n",sz,zp);
	for(int z=0; z<zp; z++) assert(h[z]!=0);
	//        if(!h[z]) printf("h[%d]:%d\n", z,h[z]);
	//    }
	return zp;
	}

inline void swap(int from, int to, int size, int zp) {
	mv(from,zp,size);
	mv(to,from,size);
	mv(zp,to,size);
}

inline void alignAll(int zp) {
	for(int hno=1,i=0,j=0,ilen=0,jlen=0; hno<MAX_HOUSE; hno++) {
		for(ilen=0; h[i+ilen]==hno; ilen++);
		i+=ilen;

		while(j<zp) {
			for(ilen=0; i+ilen<sz; ilen++) if(h[i+ilen]==hno) break;
			for(j=i+ilen, jlen=0; j+jlen<zp && jlen<msz; jlen++) if(h[j+jlen]!=hno) break;

			int d = min(ilen,jlen);
			swap(i,j,d,zp);

			i+=d; j+=d;
		}
	}
}

void cleanup() {
	m_init();
	int zp = alignZero();
	alignAll(zp);
	return;
}


