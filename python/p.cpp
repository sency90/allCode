#include <cstdio>
using namespace std;
int inc(int x) { return x+1; }
int dec(int x) { return x-1; }
int (*f(int x))(int) {
	if(x==1) return inc;
	else return dec;
}
int main() {
	printf("f(1)(3): %d\n", f(1)(3));
	return 0;
}
