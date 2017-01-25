#include <bitset>
#include <cstdio>
#include <stdio.h>
using namespace std;
int main() {
    bitset<20> bit(1);
    for(int i=0; i<5; i++) {
        if(bit[i]) printf("1");
        else printf("0");
    }
    return 0;
}
