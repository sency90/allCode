#include <cstdio>
using namespace std;
int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        int a,b;
        scanf("%d%d",&a,&b);
        if(a<b) puts("<");
        else if(a>b) puts(">");
        else puts("=");
    }
    return 0;
}
