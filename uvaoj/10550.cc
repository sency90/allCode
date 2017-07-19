#include <iostream>
using namespace std;
inline int r(int x) { return (x-1+40)%40; }
inline int l(int x) { return (x+1)%40; }
int main() {
    while(true) {
        int a,b,c,d; scanf("%d%d%d%d",&a,&b,&c,&d);
        if(a==0&&b==0&&c==0&&d==0) break;
        int ans=1080;
        int cnt=0;
        while(a!=b) a=r(a), cnt++;
        while(b!=c) b=l(b), cnt++;
        while(c!=d) c=r(c), cnt++;
        printf("%d\n", ans+cnt*9);
    }
    return 0;
}
