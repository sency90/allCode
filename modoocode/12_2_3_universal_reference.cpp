#include <iostream>
#include <cstdio>
using namespace std;
template <typename T>
void show_value(T && x) {
	printf("r-value: %d\n", x);
}
int main() {
	show_value(3);
	int x = 3;
	show_value(x);
	show_value(move(x));
	return 0;
}
