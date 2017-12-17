#include <cstdio>
using namespace std;
int main() {
    int n,a,b; scanf("%d%d%d",&n,&a,&b);
    int x = n/a, y;
    for(int i=0; i<=x; i++) {
        y=n-a*i;
        if(y%b==0) {
            puts("YES");
            return 0&printf("%d %d\n",i,y/b);
        }
    }
    puts("NO");
    return 0;
}
