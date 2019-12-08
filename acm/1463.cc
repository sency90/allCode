#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int d[1000001];
int main() {
    int n; scanf("%d", &n);
    memset(d,0x3f,sizeof(d));
    d[1]=0;
    for(int i=2; i<=n; i++) {
        if(i%2==0) d[i]=min(d[i],d[i/2]+1);
        if(i%3==0) d[i]=min(d[i],d[i/3]+1);
        d[i]=min(d[i],d[i-1]+1);
    }
    for(int i=1; i<=n; i++) {
        printf("%d\n", d[i]);
    }
    return 0;
}
