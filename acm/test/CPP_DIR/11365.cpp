#include <stdio.h>
#include <stack>
#include <queue>
using namespace std;
stack<char> s;
int main() {
    char c=0, ppc=0, pc=0;
    while(true) {
        ppc=0; pc=0; c=0;
        while((c=getchar())!='\n' && c!='\r' && c!=EOF) {
            if(ppc=='E' && pc=='N' && c=='D') return 0;
            s.push(c);
            ppc = pc; pc = c;
        }
        while(!s.empty()) {
            printf("%c", s.top()); s.pop();
        }
        printf("\n");
    }
    return 0;
}
