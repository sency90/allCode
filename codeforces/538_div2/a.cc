#include <cstdio>
using namespace std;
int main() {
    int x,y,z;
    scanf("%d%d%d",&x,&y,&z);
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    a-=x;
    if(a<0) return 0&puts("NO");
    a=a+b-y;
    if(a<0) return 0&puts("NO");
    a=a+c-z;
    if(a<0) puts("NO");
    else puts("YES");
    return 0;
}
