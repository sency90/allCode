#include <cstdio>
using namespace std;
int main() {
    int n,x,y,z;
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        scanf("%dd%d%d",&x,&y,&z);
        printf("%d %d %d\n", x,y,z);
    }
}
