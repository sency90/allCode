#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
const int lim = 1e7;
bool chk(int x) {
    int cnt=0;
    while(x!=0) {
        if(x%10 == 6) cnt++;
        else cnt=0;
        if(cnt==3) return true;
        x/=10;
    }
    return false;
}
int main() {
    int n; scanf("%d", &n);
    int cnt=0;
    for(int i=0; i<lim; i++) {
        if(chk(i)) {
            if(++cnt==n) return 0&printf("%d\n", i);
        }
    }
    return 0;
}
