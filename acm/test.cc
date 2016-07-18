#include <cstdio>
#include <map>
using namespace std;
map<int,bool> chk;
int main() {
    for(int i=0; i<300000; i++) {
        chk[i] = true;
    }
    return 0;
}
