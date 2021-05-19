#include <iostream>
using namespace std;
template<class TYPE>
void f(TYPE data) {
    cout << "Twice: " << data * 2 << endl;
}
int main() {
    f(5);
    return 0;
}
