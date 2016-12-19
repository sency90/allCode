#include <cstdio>
using namespace std;
int main() {
    int a,b,c,ans=0;
    scanf("%d%d%d",&a,&b,&c);
    for(int i=1,j=2,k=4; i<=a && j<=b && k<=c; i++,j=2*i,k=4*i) {
        ans=i+j+k;
    }
    printf("%d", ans);
    return 0;
}
