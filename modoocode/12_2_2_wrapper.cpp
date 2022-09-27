#include <cstdio>
#include <iostream>
using namespace std;
template <typename T>
void wrapper(T&& u) {
	g(forward<T>(u));
}

class A {};

void g(A &a) { printf("l-value reference call\n");}
void g(const A &a) { printf("l-value const reference call\n");}
void g(A &&a) { printf("r-value reference call\n"); }
int main() {
	A a;
	const A ca;

	printf("<ORIGINAL>\n");
	g(a);
	g(ca);
	g(A());

	printf("\n<Wrapper>\n");
	wrapper(a);
	wrapper(ca);
	wrapper(A());
	return 0;
}
