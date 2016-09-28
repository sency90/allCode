#include <cstdio>
#include <vector>
using namespace std;
bool isPalin(int x, int b) {
    int v[22],i;
    for(i=0; x!=0; i++) {
        v[i]=x%b;
        x/=b;
    }
    for(int z=i-1, k=0; z>=0; z--, k++) {
        if(z<=k) return true;
        if(v[z]!=v[k]) return false;
    }
    return true; //error
}
int main() {
    int tc,x; scanf("%d", &tc);
    while(tc--) {
        scanf("%d", &x);
        bool hasAns=false;
        for(int base=2; base<=64; base++) {
            if(isPalin(x,base)) {
                hasAns=true;
                break;
            }
        }
        if(hasAns) puts("1");
        else puts("0");
    }
    return 0;
}
