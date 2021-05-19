#include <cstdio>
#include <cstring>
using namespace std;
char s[101];
bool chk[27];
int main() {
    int n,ans;
    scanf("%d", &n);
    ans=n;
    for(int i=0; i<n; i++) {
        scanf("%s", s);
        memset(chk,false,sizeof(chk));
        char pc=0;
        for(int i=0; s[i]; i++) {
            if(chk[s[i]-'a']) {
                if(pc==s[i]) continue;
                else {
                    ans--;
                    break;
                }
            } else chk[s[i]-'a']=true;
            pc=s[i];
        }
    }
    printf("%d", ans);
    return 0;
}
