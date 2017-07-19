#include <iostream>
#include <cstring>
using namespace std;
int v[2];
int main() {
    int tc; scanf("%d", &tc);
    for(int z=1; z<=tc; z++) {
        int n; scanf("%d", &n);
        memset(v,0,sizeof(v));
        for(int i=0; i<n; i++) {
            int x;
            scanf("%d", &x);
            v[0]+=((x+30)/30)*10;
            v[1]+=((x+60)/60)*15;
        }
        printf("Case %d: ", z);
        if(v[0]==v[1]) printf("Mile Juice %d\n", v[0]);
        else if(v[0]<v[1]) printf("Mile %d\n", v[0]);
        else printf("Juice %d\n", v[1]);
    }
    return 0;
}
