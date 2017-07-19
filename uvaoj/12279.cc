#include <iostream>
using namespace std;
int main() {
    for(int z=1;;z++) {
        int n; scanf("%d", &n);
        if(n==0) return 0;
        int nc=0, zc=0;
        for(int i=0; i<n; i++) {
            int x; scanf("%d", &x);
            if(x==0) zc++;
            else nc++;
        }
        printf("Case %d: %d\n",z,nc-zc);
    }
    return 0;
}
