#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
template <typename T>
void print(T x) {
	cout << x << "\n";
}
template <typename T, typename... Ts>
void print(T x, Ts... xs) {
	cout << x << ", ";
	print(xs...);
}

template <typename T>
string strcat(const T & s) {
	return string(s);
}

template <typename T, typename... Ts>
string strcat(const T & s, const Ts... ss) {
	return string(s) + strcat(ss...);
}

int main() {
	string s1="abc", s2="def", s3=" plzrun";
#if 0
	string s;
	s.reserve(s1.size() + s2.size() + s3.size());
	s.append(s1);
	s.append(s2);
	s.append(s3);
#endif

	string s = strcat(s1, s2, "hoho", s3);
	printf("s:%s\n", s.c_str());
	return 0;
}
