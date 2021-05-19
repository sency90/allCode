#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
    int ans=0, h, m; scanf("%d %d", &h, &m);
    if(h==1) ans = 1;
    else if(h==2) ans = min(4, (m+1)/2);
    else if(h>=3) {
        if(m<7) ans = min(4, m);
        else ans = m-2;
    }
    printf("%d", ans);
    return 0;
}
