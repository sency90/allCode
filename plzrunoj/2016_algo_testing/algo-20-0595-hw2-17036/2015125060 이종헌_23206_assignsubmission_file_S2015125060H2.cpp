#include <stdio.h>

int main() {
	int num, index = -1;
	int arr[1000] = {0, };
	int result[1000] = {0, };

	scanf("%i", &num);
	for(int i  = 0; i < num; i++) {
		scanf("%i", &arr[i]);
	}

	for(int i = 0; i < num; i++) {
		int tmp = 0;

		for(int j = 0; j < num; j++) {
			if(arr[j] >= arr[i]) {		
				tmp++;
			}
		}
		if(tmp >= arr[i]) {
			result[i]++;
		}
	}

	for(int i = 0; i < num; i++) {
		if(result[i] == 1) {
			if(index == -1) {
				index = i;
			} else {
				if(arr[i] > arr[index]) {
					index = i;
				}
			}
		}
	}

	printf("%i\n", arr[index]);
	return 0;
}