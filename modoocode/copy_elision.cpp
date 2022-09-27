#include <iostream>
using namespace std;

class A {
    int data;

    public:
    A(int data) : data(data) {
        cout << "Call General Constructor\n";
    }

    A(const A& a) : data(a.data) {
        cout << "Call Copy Constructor!\n";
    }
};

int main() {
    A a(1); //Gen Constructor
    A b(a); //Copy Constructor

    A c(A(2));
}
