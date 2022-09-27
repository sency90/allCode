#include <iostream>
using namespace std;

template <typename T>
void print(T arg) {
	cout << arg << "\n";
}

template <typename T, typename... Types>
void print(T arg, Types... args) {
	cout << arg << ", ";
	print(args...);
}

int main() {
	print(1, 3.1, "abc");
	print(1,2,3,4,5,6,7);
}
