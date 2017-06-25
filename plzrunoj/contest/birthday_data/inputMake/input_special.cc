#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cassert>
using namespace std;
int main() {
    ofstream out("data09.in");
    out.tie(0);
    int n=100000;
    out << n << "\n";
    int x=2,k=1;
    for(int i=0; i<n; i++,k+=2147,x++) {
        out <<"1000 1000000000\n";
    }
    return 0;
}
