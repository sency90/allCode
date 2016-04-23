#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;
static char _buffer[1024];
static int _currentChar = 0;
static int _charsNumber = 0;
 
static inline int _read() {
	if (_charsNumber < 0) {
		exit(1);
	}
	if (!_charsNumber || _currentChar == _charsNumber) {
		_charsNumber = (int)fread(_buffer, sizeof(_buffer[0]), sizeof(_buffer), stdin);
		_currentChar = 0;
	}
	if (_charsNumber <= 0) {
		return -1;
	}
	return _buffer[_currentChar++];
}
 
static inline long long _readLong() {
	int c, s;
	lint x;
	c = _read();
	while (c <= 32) c = _read();
	x = 0;
	s = 1;
	if (c == '-') {
		s = -1;
		c = _read();
	}
	while (c > 32) {
		x *= 10;
		x += c - '0';
		c = _read();
	}
	if (s < 0) x = -x;
	return x;
}
 
static inline int _readInt() {
	int c, x, s;
	c = _read();
	while (c <= 32) c = _read();
	x = 0;
	s = 1;
	if (c == '-') {
		s = -1;
		c = _read();
	}
	while (c > 32) {
		x *= 10;
		x += c - '0';
		c = _read();
	}
	if (s < 0) x = -x;
	return x;
}


int main()
{
	int N = _readInt(), K = _readInt();
	

	static int a[5000001] = {};
	for(int i=0; i < N; i++)
		a[i] = _readInt();
	nth_element(a, a+K-1, a+N);
	printf("%d",a[K-1]);
	return 0;
}