#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <utility>
#include <memory>
#include <algorithm>
using namespace std;
struct Point{
	int x,y;
	Point():x(0),y(0) {}
	Point(int x, int y):x(x),y(y) {}
};

std::vector<std::unique_ptr<Point>> v;
std::vector<std::unique_ptr<Point>> w;
int main() {
	unique_ptr<Point> p(new Point(1,2));
	v.push_back(move(p));
	w.push_back(move(v[0]));
	printf("v.capacity:%lu, v.size:%lu, v.val:(%d,%d)\n",
			v.capacity(), v.size(),
			(v[0]!=nullptr)?(v[0]->x):(-1),
			(v[0]!=nullptr)?(v[0]->y):(-1));
	printf("w.capacity:%lu, w.size:%lu, w.val:(%d,%d)\n", w.capacity(), w.size(), w[0]->x, w[0]->y);
	return 0;
}

