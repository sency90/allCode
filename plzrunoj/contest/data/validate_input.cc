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
        if(i<10) ifname = string("data")+'0'+to_string(i)+string(".in");
        else ifname = string("data")+to_string(i)+string(".in");
        ifstream in(ifname);

        int n;
        in >> n;
        assert(n>=1 && n<=100000);
        for(int i=0; i<n; i++) {
            int x,k;
            in >> x >> k;
            assert(x>=2 && x<=1000);
            assert(k>=1 && k<=int(1e9));
        }
        printf("data%02d test OK!!\n", i);
    }
    return 0;
}
