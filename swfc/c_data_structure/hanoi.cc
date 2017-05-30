#include <cstdio>
using namespace std;
char c[]={'A','B','C'};
void f(int x, int from, int to) {
    if(x==1) printf("%d -> %d\n",from,to);
    else {
        f(x-1, from, 3-from-to);
        f(1, from, to);
        f(x-1, 3-from-to, to);
    }
}
int main() {
    int n; scanf("%d", &n);
    f(n,0,2);
    return 0;
}
