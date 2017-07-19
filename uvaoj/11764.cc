#include <iostream>
using namespace std;
int v[51];
int main() {
    int tc; scanf("%d",&tc);
    for(int z=1; z<=tc; z++) {
        int n; scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%d", &v[i]);
        }
        int up=0,down=0;
        for(int i=1; i<n; i++) {
            if(v[i]-v[i-1]>0) up++;
            else if(v[i]-v[i-1]<0) down++;
        }
        printf("Case %d: %d %d\n", z,up,down);
    }
    return 0;
}
