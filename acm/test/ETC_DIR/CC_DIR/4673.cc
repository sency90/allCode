#include <cstdio>
using namespace std;
bool chk[10001];
int d(int x) {
    int ret=x;
    while(x!=0) {
        ret += x%10;
        x/=10;
    }
    if(ret>10000) return 0;
    return ret;
}
int main() {
    for(int i=1; i<=10000; i++) {
        chk[d(i)] = true;
    }
    for(int i=1; i<=10000; i++) {
        if(!chk[i]) printf("%d\n", i);
    }
    return 0;
}
