#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
using namespace std;
string sfx=".in", fname,s;
int main() {
    ios::sync_with_stdio(false);
    srand(time(0));
    for(int i=1; i<=50; i++) {
        if(i<10) fname='0'+to_string(i)+sfx;
        else fname=to_string(i)+sfx;
        ofstream out(fname);
        out.tie(0);

        int n;
        if(i<10) n=51+rand()%50;
        else if(i<20) n=101+rand()%9900;
        else if(i<30) n=10001+rand()%40000;
        else if(i<40) n=50001+rand()%50000;
        else n=100000;
        if(n>=1 && n<=100000) printf("%d\n", n);
        assert(n>=1 && n<=100000);

        for(int j=0; j<n; j++) {
            int x=2+rand()%999;
            int k=rand()%1000000001LL;
            out <<  x << " " << k << "\n";
        }
        out.close();

    }
    return 0;
}

