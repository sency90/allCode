#include <cstdio>
using namespace std;
int main() {
    int n, c, pd, d;
    scanf("%d%d", &n,&c);
    scanf("%d", &d);
    pd = d;
    int cnt=1;
    for(int i=1; i<n; i++) {
        scanf("%d", &d);
        if(d-pd > c) cnt=1;
        else cnt++;
        pd = d;
    }
    printf("%d\n", cnt);
    return 0;
}
