#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
    int a, b, c;
    scanf("%d %d %d", &a,&b,&c);
    int s[3], e[3];
    for(int i=0; i<3; i++) {
        scanf("%d %d", &s[i], &e[i]);
    }
    sort(s, s+3);
    sort(e, e+3);

    int cnt, sum = 0;
    for(int i=s[0]+1; i<=e[2]; i++) {
        cnt=1;
        if(i>s[1]) cnt++;
        if(i>s[2]) cnt++;
        if(i>e[0]) cnt--;
        if(i>e[1]) cnt--;
        if(cnt == 1) sum += cnt*a;
        else if(cnt == 2) sum += cnt*b;
        else sum += cnt*c;
    }
    printf("%d", sum);
    return 0;
}
