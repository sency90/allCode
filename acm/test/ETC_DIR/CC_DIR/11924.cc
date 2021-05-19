#include <stdio.h>
#include <map>
using namespace std;
map<int, int> chk;
int main() {
    int n, d, a;
    scanf("%d", &n);
    scanf("%d", &a);
    int pd = a, cnt=1, x=0;
    for(int i=1; i<n; i++) {
        scanf("%d", &d);
        if(pd < d) x++;
        else if(pd > d) x--;
        if(x==0) {
            if(d==a) cnt++;
        } else {
            if((d-a)%x == 0) {
                chk[(d-a)/x]++;
            }
        }
        pd=d;
    }
    int mx = 0, k;
    for(auto &p: chk) {
        if(mx<p.second) {
            k=p.first;
            mx=p.second;
        }
    }

    printf("%d\n%d\n", cnt+mx, k);
    return 0;
}
