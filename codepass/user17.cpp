#define SIZE (1048576)
typedef unsigned int uint;

const uint UINT_MSB = (1U<<30);
const uint SHORT_MSB = (1U<<15);
const uint SHORT_SZ = (1U<<16);
#define Z 1024
extern void hw_sort(short data[Z]);

uint msk(uint x) { return x&0xFFFFU; }
uint sft(uint x) {return msk(x>>16); }
void swap(uint *x, uint *y) {
	uint t = *x;
	*x = *y;
	*y = t;
}
void mkroom(int s, int e, int sbit, int ebit, uint *cnt, uint *data) {
	const uint mask = (1U<<(ebit-sbit))-1U;

	for(int i=0; i<=mask; i++) cnt[i] = 0; //cnt배열 초기화
	for(int i=s; i<e; i++) cnt[(data[i]>>sbit)&mask]++; //cnt배열로 counting
	for(int i=1; i<=mask; i++) cnt[i] += cnt[i-1]; //cnt sum구하기
	for(int i=e-1; i>=s; i--) {
		if(data[i]&UINT_MSB) {
			//원래대로 돌려놓는다.
			data[i]^=UINT_MSB;
		}
		else {
			while(true) {
				int j = --cnt[((data[i] >> sbit) & mask)]+s;
				if(i==j) break; //i자리에 와야하는 data[]가 온 경우
								// data[i]는 data[j]가 있는 곳으로 가야 한다.
								//그럼 data[j]와 data[i]를 swap하고
								//다시 data[i]에 대해서 진행해보자.
				swap(&data[i], &data[j]);
				//근데 j가 자기 자리를 찾았으니 뭔가 표시해보자.
				data[j] |= UINT_MSB;
			}
		}
	}
}
void test(unsigned int data[SIZE]) {
	bool chk[SHORT_SZ];
	for(int i=0; i<SHORT_SZ; i++) chk[i] = false;
	for(int i=0; i<SIZE; i++) {
		chk[msk(data[i])] = chk[sft(data[i])] = true;
	}
	//order: 값을 넣으면 순서를 알 수 있다.
	//val: 순서를 넣으면 값을 알 수 있다.
	int order[SHORT_SZ] = {0, };
	int val[2048] = {0, };
	int no = 0;
	for(int i=SHORT_SZ-1; i>=0; i--) {
		if(chk[i]) {
			order[i] = no;
			val[no++] = i;
		}
	}

	//32bit->22bit
	for(int i=0; i<SIZE; i++) {
		int upper = order[sft(data[i])];
		int lower = order[msk(data[i])];
		data[i] = (upper<<11) | lower;
	}

	uint cnt[1<<11];
	const int intv_i = (1<<11);
	mkroom(0,SIZE,11,22,cnt,data);
	int s=0;
	for(int i=1; i<SIZE; i++) {
		if((data[s]>>11) != (data[i]>>11)) {
			mkroom(s, i, 0,11,cnt,data);
			s = i;
		}
	}
	mkroom(s,SIZE,0,11,cnt,data);
	s=SIZE;

	//복원
	for(int i=0; i<SIZE; i++) {
		uint upper = val[data[i]>>11];
		uint lower = val[data[i]&0x7FF];
		data[i] = (upper<<16) | lower;
	}
}
