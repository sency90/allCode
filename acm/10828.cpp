#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;
stack<int> s;
int main() {
    char opcode[6];
    int operand, n;

    scanf("%d", &n);
    while(n--) {
        scanf("%s", opcode);
        switch(opcode[0]) {
            case 'p':
                if(opcode[1] == 'u') { //push
                    scanf("%d", &operand);
                    s.push(operand);
                } else { //pop
                    if(s.empty()) printf("-1\n");
                    else {
                        printf("%d\n", s.top());
                        s.pop();
                    }
                }
                break;
            case 's': //size
                printf("%lu\n", s.size());
                break;
            case 'e': //empty
                printf("%d\n", s.empty());
                break;
            case 't': //top
                if(s.empty()) printf("-1\n");
                else printf("%d\n", s.top());
                break;
        }
    }
    return 0;
}
