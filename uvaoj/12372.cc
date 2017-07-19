#include <iostream>
using namespace std;
char s[2][5]={"good","bad"};
int main() {
    int tc; scanf("%d", &tc);
    for(int z=1; z<=tc; z++) {
        int x, ans=0;
        for(int i=0; i<3; i++) {
            scanf("%d", &x);
            if(x>20) ans=1;
        }
        printf("Case %d: %s\n", z, s[ans]);
    }
    return 0;
}
