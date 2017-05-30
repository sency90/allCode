#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	int a[4] = {1,2,3,4};
	cout << (a[0]-a[1] < sizeof(a));
	if(a[0]-a[1] < sizeof(a)) printf("%d\n", a[sizeof(char)]);
	else printf("%d\n", a[sizeof(short)]);
    return 0;
}