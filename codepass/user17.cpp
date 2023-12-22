//SCORE: 157
typedef unsigned int uint;
typedef unsigned short ushort;
#define SIZE (1048576)

extern void hw_sort(short data[1024]);
void merge_dsc(int s, int m, int e,ushort *v) {
	ushort tmp[2048];
	int i=m-1,j=e-1,k=s;
	while(i>=0 && j>=m) {
		if(v[i]>v[j])  tmp[k++] = v[i--];
		else tmp[k++] = v[j--];
	}
	while(i>=0) tmp[k++] = v[i--];
	while(j>=m) tmp[k++] = v[j--];

	//assert(k==e);
	for(i=s; i<e; i++) v[i]=tmp[i];
}

void merge_asc(int s, int m, int e, ushort *v) {
	ushort tmp[2048];
	int i=s,j=m,k=s;
	while(i<m && j<e) {
		if(v[i]<v[j])  tmp[k++] = v[i++];
		else tmp[k++] = v[j++];
	}
	while(i<m) tmp[k++] = v[i++];
	while(j<e) tmp[k++] = v[j++];

	for(i=s; i<e; i++) v[i]=tmp[i];
}

template <typename T> void swap(T &x,T &y) { T tmp=x; x=y; y=tmp; }
void test(uint data[SIZE]) {
	const ushort M = 1U<<15;
	ushort en[2048],chk[1<<16];
	int en_i=0;

	for(register int i=0; i<(1<<16); i++) chk[i]=0;
	for(int i=0; i<SIZE; i++) {
		uint a = ((data[i] >> 16)&0xffff)^M;
		uint b = (data[i] & 0xffff)^M;
		if(!chk[a]) {
			chk[a] = 1;
			en[en_i++] = a;
		}
		if(!chk[b]) {
			chk[b] = 1;
			en[en_i++] = b;
		}
	}

	const ushort inf = 0xffffU;
	for(int i=en_i; i<2048; i++) {
		en[i]=inf^M;
	}

	hw_sort((short*)en);
	hw_sort((short*)en+1024);

	for(int i=0; i<en_i; i++) {
		en[i]^=M;
	}

	merge_dsc(0,1024, en_i, en);
	for(int i=0; i<en_i; i++) {
		//printf("[%4d] %04X\n", i, en[i]);
		chk[en[i]] = i;
	}

	int tcnt=0;

	int cnt[2048]={0,},cnt2[2049]={0,};
	for(int i=0; i<SIZE; i++) {
		uint a = ((data[i] >> 16)&0xffff);
		uint b = (data[i] & 0xffff);

		data[i] = ((((uint)chk[a])<<11) | (uint)chk[b]);
		cnt[chk[a]]++;
	}

	for(int i=1; i<2048; i++) cnt[i]+=cnt[i-1];
	for(int i=0; i<2048; i++) cnt2[i+1]=cnt[i];

	const uint f = 1U<<30;
	const ushort MASK = (1U<<11)-1;
	uint x;
	for(int i=0; i<SIZE; i++) {
		while((data[i]&f) == 0) {
			data[i]|=f;
			ushort a = (data[i] >> 11)&MASK;
			swap(data[--cnt[a]],data[i]);
		}
	}


	ushort tmp[2048];
	for(int i=0; i<2048; i++) {
		int len = cnt2[i+1]-cnt2[i];
		if(len==0) break;
		else if(len<=1024) {
			int j=0; for(; j<len; j++) tmp[j]=data[cnt2[i]+j]&MASK;
			for(; j<1024; j++) tmp[j] = inf^M;
			hw_sort((short*)tmp);
			for(j=0; j<len; j++) data[cnt2[i]+j] = (data[cnt2[i]+j]&0x3FF800U) | tmp[j];
		}
		else if(len<=2048) {
			int j=0; for(; j<len; j++) tmp[j]=data[cnt2[i]+j]&MASK;
			for(; j<2048; j++) tmp[j] = inf^M;
			hw_sort((short*)tmp);
			hw_sort((short*)tmp+1024);
			merge_asc(0,1024,len,tmp);
			for(j=0; j<len; j++) data[cnt2[i]+j] = (data[cnt2[i]+j]&0x3FF800U) | tmp[j];
		}
		//else {
		//	printf("len:%d, i:%d\n",len,i);
		//}
	}

	for(int i=0; i<SIZE; i++) {
		data[i] = ((uint)en[(data[i]>>11)&MASK]<<16) | en[data[i]&MASK];
	}
}
