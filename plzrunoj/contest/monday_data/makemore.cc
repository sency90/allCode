#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;
int v[301][301];
int main() {
    string ifname;
    for(int z=4; z<=20; z++) {
        if(z<10) ifname = "data0"+to_string(z)+".in";
        else ifname = "data"+to_string(z)+".in";
        string ofname = "data"+to_string(z+17)+".in";
        ifstream in(ifname);
        ofstream out(ofname);
        int n,m;
        in >> n >> m;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                in >> v[i][j];
            }
        }
        for(int j=0; j<m; j++) {
            for(int i=0; i<n; i++) {
                out << v[i][j];
                out << " \n"[i==n-1];
            }
        }
        out.close();
        in.close();
    }
    int n,m;
    return 0;
}
