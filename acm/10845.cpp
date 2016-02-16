#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
queue<int> q;

int main() {
    char opcode[6];
    int operand, n;
    scanf("%d", &n);
    while(n--) {
        scanf("%s", opcode);
        if(!strcmp(opcode, "push")) {
            scanf("%d", &operand);
            q.push(operand);
        } else if(!strcmp(opcode, "pop")) {
            if(!q.empty()) {
                printf("%d\n", q.front());
                q.pop();
            } else printf("-1\n");
        } else if(!strcmp(opcode, "size")) {
            printf("%lu\n", q.size());
        } else if(!strcmp(opcode, "empty")) {
            printf("%d\n", q.empty());
        } else if(!strcmp(opcode, "front")) {
            !q.empty()? printf("%d\n", q.front()):printf("-1\n");
        } else if(!strcmp(opcode, "back")) {
            !q.empty()? printf("%d\n", q.back()):printf("-1\n");
        }
    }
    return 0;
}
