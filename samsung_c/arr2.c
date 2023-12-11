#include <stdio.h>
int sum(int b[4]) {
	int i, ret = 0, lim = sizeof(b)/sizeof(b[0]);
	printf("sizeof(b): %d\n", sizeof(b));
	printf("sizeof(b[0]): %d\n", sizeof(b[0]));
	printf("lim: %d\n", lim);

	for(i=0; i<lim; i++) {
		ret += b[i];
	}
	return ret;
}
int main() {
	int a[] = {0x10, 0x20, 0x30, 0x40};
	printf("%x\n", sum(a));
	return 0;
}
