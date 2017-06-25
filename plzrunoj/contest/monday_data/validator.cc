#include <iostream>
#include <cassert>
#include <fstream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int main() {
    string fname;
    for(int z=1; z<=135; z++) {
        if(z<10) fname = "data0"+to_string(z)+".in";
        else fname = "data"+to_string(z)+".in";
        ifstream in(fname);
        in.tie(0);
        int n,m;
        in >> n >> m;
        assert(n>=2 && n<=300);
        assert(m>=2 && m<=300);
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                int x;
                in >> x;
                if(i==0 && j==0) assert(x==-1);
                else if(i==n-1 && j==m-1) assert(x==-1);
                else assert(x>=-2 && x<=1000000000);
            }
        }
        in.close();
        printf("data %d is OK!!!\n", z);
    }
}
