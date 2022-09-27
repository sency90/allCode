#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <utility>
using namespace std;
struct Info{
	int a,b,c,d,e;
	Info() {}
	Info(int a, int b, int c, int d, int e):a(a),b(b),c(c),d(d),e(e) {}

	void println() {
		printf("a:%d, b:%d, c:%d, d:%d, e:%d\n", a,b,c,d,e);
	}
};

template<typename T, typename... Args>
std::unique_ptr<T> mk_unique(Args&&... args)
{
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

#if 0
unique_ptr<vector<unique_ptr<Info>>> func(vector<unique_ptr<Info>> infoList) {
	unique_ptr<vector<unique_ptr<Info>>> ret(move(&infoList));
	return ret;
}
#endif

vector<unique_ptr<Info>> v;
void func(unique_ptr<Info> info) {
	v.push_back(move(info));
}

int main() {
	vector<unique_ptr<Info>> infoList;
	for(int i=0, j=0; j<5; j++, i+=3) {
		infoList.push_back(mk_unique<Info>(i,i+1,i+2,i+3,i+4));
	}

	for(int i=0; i<5; i++) {
		func(move(infoList[i]));
	}

	//auto it = move(func(infoList));
	//unique_ptr<vector<unique_ptr<Info>>> res(move(func(infoList)));

	for(int i=0; i<v.size(); i++) {
		printf("[%d]: ", i); v[i].get()->println();
	}

	return 0;
}
