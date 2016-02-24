#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <limits.h>
using namespace std;
int d[100001];
bool everV[100001];
int init;
int f(int x) {
    if(x == init) return d[x] = 0;
    if(d[x] >= 0) return d[x];
    if(everV[x]) return d[x];

    everV[x] = true;
    int t;
    if(x+1 > 100000) t = f(x-1);
    else if(x-1 < 0) t = f(x+1);
    else t = min(f(x-1), f(x+1));

    if(x%2 == 0) d[x] = min(t, f(x/2))+1;
    else d[x] = t+1;
    return d[x];
}
int main() {
    int end;
    memset(everV, false, sizeof(everV));
    for(int i=0; i<=100000; i++) d[i] = INT_MAX/2;
    //memset(d, -1, sizeof(d));
    scanf("%d %d", &init, &end);
    printf("%d\n", f(end));
    return 0;
}
