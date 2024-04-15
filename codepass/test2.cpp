#include <stdio.h>
#include <string.h>
struct Info{
	int x[128];
	Info() {
		memset(x, 0, sizeof(x));
	}
	void print() const {
		for(int i=0; i<128; i++) {
			printf("%d ", x[i]);
		}
		puts("");
	}
};
int main() {
	Info info[2];
	for(int i=0; i<128; i++) {
		info[0].x[i] = i;
	}

	info[1].print(); puts("");
	info[1] = info[0];
	info[1].print();
	return 0;
}
