#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int v[10],g[10];
int main() {
    int tc; scanf("%d", &tc);
    puts("Lumberjacks:");
    while(tc--) {
        for(int i=0; i<10; i++) {
            scanf("%d", &v[i]);
        }
        memcpy(g,v,sizeof(v));
        sort(v,v+10);
        for(int i=0; i<10; i++) {
            if(v[i]!=g[i]) goto UN1;
        }
        puts("Ordered");
        continue;
UN1:
        for(int i=0; i<10; i++) {
            if(v[i]!=g[9-i]) goto UN2;
        }
        puts("Ordered");
        continue;
UN2:
        puts("Unordered");
    }
    return 0;
}
