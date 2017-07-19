#include <cstdio>
using namespace std;
int main() {
	char c = -1;
   	if (c == 0xff) printf("aaa%#x", c - 2);
   	else printf("bbbb%#x", c);
    return 0;
}
