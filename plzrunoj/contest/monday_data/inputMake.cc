#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;
const int COSTLIM = int(1e9);
int main() {
    srand(time(0));
    for(int z=40,u=2; z<=130; z++,u+=5) {
        int n,m;
        string fname = "data"+to_string(z)+".in";
        ofstream out(fname);

        n = u+rand()%u;
        m = u+rand()%u;
        if(n>300) n=300;
        if(m>300) m=300;
        out << n << " " << m << "\n";
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if((i==0 && j==0) || (i==n-1 && j==m-1)) out << -1;
                else {
                    int rnd = rand()%101;
                    if(rnd>=10) {
                        if(rnd>=z) rnd=-2;
                        else rnd=-1;
                    } else rnd = rand()%COSTLIM;
                    out << rnd;
                }
                out << " \n"[j==m-1];
            }
        }

        out.close();
    }
    return 0;
}
