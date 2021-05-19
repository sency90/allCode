#include <stdio.h>
int v[21], n, s, cnt=0;
void f(int x, int sum) {
    if(x == n) {
        cnt += (sum == s);
        if(sum == s) cnt++;
        return;
    }
    f(x+1, sum+v[x]);
    f(x+1, sum);
}
int main() {
    scanf("%d%d",&n,&s);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    f(0, 0);
    if(s==0) cnt--;
    printf("%d", cnt);
    return 0;
}
