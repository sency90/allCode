#include <iostream>
#include <list>
using namespace std;
int main() {
	int i = 0;
	char cmd[10] = "xbasd";
	list<char> lt;
	list<char>::iterator it;
	it = lt.end();

	cout<<"before: "<<*it<<endl;

	return 0;
}
