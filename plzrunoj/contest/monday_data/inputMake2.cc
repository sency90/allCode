#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;
int v[303][303];
int main() {
    srand(time(0));
    string ifname, ofname;
    for(int z=3,u=2; z<=20; z++,u+=5) {
        int n,m;
        if(z<10) {
            ifname = "data0"+to_string(z)+".in";
        } else {
            ifname = "data"+to_string(z)+".in";
        }
        ofname = "data"+to_string(z+18)+".in";
        ifstream in(ifname);
        ofstream out(ofname);

        in >> n >> m;
        out << n << " " << m << "\n";
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                in >> v[i][j];
                if((i==0&&j==0)||(i==n-1&&j==m-1)) out << v[i][j];
                else {
                    if(v[i][j]<0) {
                        if(int(rand())&1) out << -2;
                        else out << -1;
                    } else out << v[i][j];
                }
                out << " \n"[j==m-1];
            }
        }

        in.close();
        out.close();
    }
    return 0;
}
