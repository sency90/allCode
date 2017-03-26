#include <cstdio>
#include <cstring>
using namespace std;
char ch[52][3], s[4];
int ans[52];
int main() {
    memset(ans, 0, sizeof(ans));
    for(int i=0; i<26; i++) ch[i][0]='A'+i;
    for(int i=26; i<52; i++) {
        ch[i][0]='A'+i-26;
        ch[i][1]='a'+i-26;
    }

    int n,k; scanf("%d%d",&n,&k);
    for(int i=0; i<n; i++) ans[i]=i;
    for(int i=0; i<n-k+1; i++) {
        scanf("%s", s);
        if(s[0]=='N') ans[i+k-1]=ans[i];
    }
    for(int i=0; i<n; i++) printf("%s ", ch[ans[i]]);
    return 0;
}
