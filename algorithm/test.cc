#include <cstdio>
using namespace std;
int main() {
    unsigned char c=200;
    for(char i=0; (unsigned char)i<(unsigned char)c; i=(unsigned char)i+(unsigned char)1) {
        printf("%x %x\n",i,c);
    }
    return 0;
}

