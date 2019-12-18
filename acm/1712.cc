#include <cstdio>
using namespace std;
int main() {
    int a,b,c;
    scanf("%d%d%d", &a,&b,&c);
    if(c<=b) puts("-1");
    else {
        int n = a/(c-b);
        for(int i=n; i<=n+1; i++) {
            if(a+b*i<c*i) return 0&printf("%d\n", i);
        }
        puts("-1");
    }
    return 0;
}
