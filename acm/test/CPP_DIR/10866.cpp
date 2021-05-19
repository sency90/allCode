#include <stdio.h>
#include <string.h>
#include <deque>
using namespace std;
deque<int> d;

int main() {
    char opcode[11];
    int operand, n;
    scanf("%d", &n);
    while(n--) {
        scanf("%s", opcode);
        if(!strcmp(opcode, "push_back")) {
            scanf("%d", &operand);
            d.push_back(operand);
        } else if(!strcmp(opcode, "push_front")) {
            scanf("%d", &operand);
            d.push_front(operand);
        } else if(!strcmp(opcode, "pop_back")) {
            if(!d.empty()) {
                printf("%d\n", d.back());
                d.pop_back();
            } else printf("-1\n");
        } else if(!strcmp(opcode, "pop_front")) {
            if(!d.empty()) {
                printf("%d\n", d.front());
                d.pop_front();
            } else printf("-1\n");
        } else if(!strcmp(opcode, "size")) {
            printf("%lu\n", d.size());
        } else if(!strcmp(opcode, "empty")) {
            printf("%d\n", d.empty());
        } else if(!strcmp(opcode, "front")) {
            !d.empty()? printf("%d\n", d.front()):printf("-1\n");
        } else if(!strcmp(opcode, "back")) {
            !d.empty()? printf("%d\n", d.back()):printf("-1\n");
        }
    }
    return 0;
}
