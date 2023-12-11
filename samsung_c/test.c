#include <stdio.h>
int main() {
	signed char c = 0xff;
	if(c == 0xff) 	printf("%x\n", c+1);
	else 		printf("%x\n", c-1);
	return 0;
}
