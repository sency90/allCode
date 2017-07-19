#include <iostream>
using namespace std;
int main() {
    while(true) {
        int k; scanf("%d", &k);
        if(k==0) return 0;
        int a,b; scanf("%d%d",&a,&b);
        for(int i=0; i<k; i++) {
            int x,y; scanf("%d%d",&x,&y);
            x-=a; y-=b;
            if(x>0) {
                if(y>0) puts("NE");
                else if(y<0) puts("SE");
                else puts("divisa");
            } else if(x<0) {
                if(y>0) puts("NO");
                else if(y<0) puts("SO");
                else puts("divisa");
            } else puts("divisa");
        }
    }
    return 0;
}
