#include <cstdio>
#include <cstring>
using namespace std;
int d[1001][5];
int f(int x, int s) {
    if(x==0) {
        if(s==0) return 1;
        else return 0;
    } else if(x<0) return 0;
    int &ret = d[x][s];
    if(ret!=-1) return ret;
    if(s==0) ret = f(x-1,0)+f(x-1,1)+f(x-1,3)+f(x-1,4)+f(x-2,0);
    else if(s==1) ret = f(x-1,0)+f(x-1,4);
    else if(s==2) ret = f(x-1,3);
    else if(s==3) ret = f(x-1,0)+f(x-1,2);
    else ret = f(x-1,0)+f(x-1,1);
    return ret;
}
int main() {
    int tc, n;
    scanf("%d", &tc);
    memset(d, -1, sizeof(d));
    while(tc--) {
        scanf("%d", &n);
        printf("%d\n", f(n,0));
    }
    return 0;
}
