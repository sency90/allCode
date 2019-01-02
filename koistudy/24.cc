#include <cstdio>
#include <cstring>
using namespace std;
char s[10];
int main() {
    scanf("%s", s);
    int len = strlen(s);
    for(int i=0; i<len ;i++) {
        if(s[i]=='0') printf("[0]\n");
        else {
            printf("[%c", s[i]);
            for(int j=i+1; j<len; j++) printf("0");
            printf("]");
            puts("");
        }
    }
    return 0;
}
