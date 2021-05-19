#include <cstdio>
#include <string>
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string line, line2;
    ifstream ifs("p");
    ifstream ifs2("p2");
    int cnt=0;
    while(!ifs.eof() && !ifs2.eof()) {
        cnt++;
        getline(ifs, line);
        getline(ifs2, line2);
        if(line != line2) {
            printf("[%d] p: %s, p2(good): %s\n", cnt, line.c_str(), line2.c_str());
        }
    }
    ifs.close();
    ifs2.close();
    return 0;
}
