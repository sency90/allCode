#include <iostream>
#include <cassert>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;
string ifname;
int main() {
    ios::sync_with_stdio(false);
    for(int i=1; i<=60; i++) {
        if(i<10) ifname = string("data")+'0'+to_string(i)+string(".out");
        else ifname = string("data")+to_string(i)+string(".out");
        ifstream in(ifname);

        int n;
        in >> n;
        assert(n>=1 && n<=int(1e9+7));
        printf("data%02d.out test OK!!\n", i);
    }
    return 0;
}
