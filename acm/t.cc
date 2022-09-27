#include <stdio.h>
int arr[3];
int main() {
	arr[0] = 3;
	arr[1] = 2;
	arr[0] = arr[0];
	for(int i=0; i<3; i++) {
		printf("%d\n", arr[i]);
	}
	return 0;
}
