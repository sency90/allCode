#include <stdio.h>
int main() {
	int a[4] = {0x10, 0x20, 0x30, 0x40};
	printf("a[4] = {0x10, 0x20, 0x30, 0x40};\n");
	printf("a[0]: %08x\n", a[0]);
	printf("&a[0]: %08x\n", &a[0]);
	printf("a: %08x\n", a);
	printf("a[0]+1: %08x\n", a[0]+1);
	printf("a+1: %08x\n", a+1);
	printf("*a: %08x\n", *a);
	printf("*(a+1): %08x\n", *(a+1));
	printf("&a: %08x\n", &a);
	printf("*&a: %08x\n", *&a);
	printf("a+1: %08x\n", a+1);
	printf("&a+1: %08x\n", &a+1);
	return 0;
}
