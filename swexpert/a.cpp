#include <cstdio>
using namespace std;
typedef int(*T)(int);

int f(int x) {
	return x+1;
}
int main() {
	printf("%X:%X\n", &f, *****************f);
	//printf("%X:%X\n", f+1, &f+1);
	return 0;
}
