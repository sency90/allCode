#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
ifstream in;
ofstream out("output_test.txt");
string pre="input_", sfx=".txt", ifname, ofname;
int main() {
    for(int i=10; i<=100; i++) {
        ifname=pre+to_string(i)+sfx;
        in = ifstream(ifname);
        int n;
        in >> n;
        out << n <<"\n";
    }
    return 0;
}
