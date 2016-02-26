#include <stdio.h>
#include <stack>
#include <queue>
using namespace std;
stack<char> s;
queue<char> q;
int main() {
    char c=0, ppc=0, pc=0;
    while(true) {
        while((c=getchar())!='\n' && c!='\r' && c!=EOF) {
            if(ppc=='E' && pc=='N' && c=='D') return 0;
            s.push(c);
            ppc = pc; pc = c;
            if(c==' ') {
                while(!s.empty()) {
                    printf("test:%c\n", s.top());
                    q.push(s.top());
                    s.pop();
                }
            }
        }
        while(!q.empty()) {
            printf("%c", q.front()); s.pop();
        }
        printf("\n");
    }
    return 0;
}
