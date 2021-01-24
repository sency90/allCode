#include <cstdio>
#include <iostream>
#include <thread>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <vector>
#include <cstdlib>
using namespace std;
using ll = long long;
vector<int> v;
void f(const int mx, vector<int> list) {
    ifstream ifs;
    string line;
    ll cnt=0;
    while(true) {
        ifs.open("./rd");
        getline(ifs, line);
        if(line.empty()) continue;

        if(line[0]=='1') {
            printf("CHILD: child file - 1\n");
            ifs.close();
            return;
        }
        else if(list[0]==2) {
            printf("CHILD: Child Thread END!!\n");
            return;
        }
        else {
            list[0] = 1;
        }
        ifs.close();
    }
}
ifstream ifs;
string line;
int main() {
    ll cnt=0;
    int mx = 10;
    v.clear(); v.resize(mx,0);
    thread t(f,mx,ref(v));

    while(true) {
        if(v[0]!=0) {
            printf("PARENT: Parent Process End - 'cause of child\n");
            break;
        }
        else {
            ifs.open("./rd");
            getline(ifs, line);
            if(line[0]=='1') {
                printf("PARENT:rd file - 1 -> break;\n");
                ifs.close();
                break;
            }
            ifs.close();
        }
    }

    puts("PARENT: is joinable()?");
    v[0]=2;

    if(t.joinable()) {
        puts("PARENT: YES JOINABLE");
        t.join();
    }
    return 0;
}
