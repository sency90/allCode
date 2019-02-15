#include <cstdio>
#include <cstring>
using namespace std;
char s[310];
int main() {
    int q; scanf("%d",&q);
    for(int i=0; i<q; i++) {
        memset(s, 0, sizeof(s));
        int n; scanf("%d",&n);
        scanf("%s", s);
        if(n==2) {
            if(s[0]>s[1]) {
                puts("YES");
                printf("2\n%c %c\n",s[0],s[1]);
            }
            else puts("NO");
        } else {
            puts("YES");
            puts("2");
            printf("%c %s\n",s[0], s+1);
        }
    }
    return 0;
}
