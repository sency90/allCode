#include <cstdio>
using namespace std;
int main() {
    unsigned int c = 3000000000U;
    bool flag=false;
    for(int i=0; (unsigned int)i < (unsigned int)c; i++) {
        if((unsigned int)i>=c-500U) flag=true;
        if(flag) printf("%x %x\n",i,c);
    }
    return 0;
}

