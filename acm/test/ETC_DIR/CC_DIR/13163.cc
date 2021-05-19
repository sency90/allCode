#include <cstdio>
#include <cstring>
using namespace std;
int main() {
    int n;
    char s[101];
    scanf("%d ", &n);
    for(int i=0; i<n; i++) {
        scanf("%[^\n]\n", s);
        int j=0, len=strlen(s);
        for(; j<len; j++) {
            if(s[j]==' '||s[j]=='\n') {
                j++; break;
            }
        }
        printf("god");
        for(int k=j; k<len; k++) {
            if(s[k]==' '||s[k]=='\n') continue;
            putchar(s[k]);
        } puts("");
    }
    return 0;
}
