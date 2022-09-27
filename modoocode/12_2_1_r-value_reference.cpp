#include <cstdio>
#include <utility>
using namespace std;
class A{
	public:
		A() { printf("A Gen Constructor\n"); }
		A(const A& rhs) { printf("A Copy Constructor\n"); }
		A(A&& rhs) noexcept { printf("A Move Constructor\n"); }

		A& operator=(const A& rhs) {
			printf("The 'A& operator=(const A&)' function was called.\n");
			return *this;
		}
		A& operator=(const A&& rhs) noexcept {
			printf("The 'A& operator=(A&&)' function was called.\n");
			return *this;
		}
};

class B{
	public:
		A a;
		B(const A& a) {
			printf("B Copy Constructor\n");
			this->a = std::move(a);
		}
		B(A&& a) {
			printf("B Move Constructor\n");
			this->a = std::move(a);
		}
};
int main() {
	printf("create A\n");
	A a;
	printf("create B with a\n");
	B b(a);
	return 0;
}
