#include <iostream>
using namespace std;
char cmd[10], v[101];
int main() {
    int tc; scanf("%d", &tc);
    while(tc--) {
        int co=0;
        int n; scanf("%d",&n);
        for(int i=0; i<n; i++) {
            scanf("%s", cmd);
            if(cmd[0]=='L') v[i]=-1;
            else if(cmd[0]=='R') v[i]=1;
            else {
                int x;
                scanf("%s %d",cmd,&x);
                v[i]=v[x-1];
            }
            co+=v[i];
        }
        printf("%d\n", co);
    }
    return 0;
}
