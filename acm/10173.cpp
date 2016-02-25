#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main() {
    int i=0;
    bool isFound;
    char c, s[5] = {"nemo"}, ppc='0', pc='0';
    while(true) {
        isFound = false;
        while((c=getchar())!='\n' && c!='\r' && c!=EOF) {
            if(ppc=='E' && pc=='O' && c=='I') return 0;
            ppc = pc; pc = c;
            if(isupper(c)) c+=32;
            if(s[i++]!=c) {
                i=0;
                continue;
            } else if(i==4) isFound = true;
        }
        if(isFound) printf("Found\n");
        else printf("Missing\n");
    }
    return 0;
}
