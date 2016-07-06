#include <stdio.h>
#include <cstdlib>
using namespace std;
int v[10], res=0;
void f(int x, int ans, bool chk) {
    if(x==10 || chk) {
        int t1 = abs(ans-100), t2 = abs(res-100);
        if(t1<t2) res = ans;
        else if(t1==t2 && ans>res) res = ans;
        return;
    }
    if(!chk) f(x+1, ans+v[x], chk);
    f(x+1, ans, true);
}
int main() {
    for(int i=0; i<10; i++) {
        scanf("%d", &v[i]);
    }
    f(0,0, false);
    printf("%d", res);
    return 0;
}
