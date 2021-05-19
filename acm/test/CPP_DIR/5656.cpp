#include <stdio.h>
int idx = 0;
void print(bool l) {
    if(l) printf("Case %d: true\n", ++idx);
    else printf("Case %d: false\n", ++idx);
}
int main() {
    int a, b;
    char op[3];
    while(true) {
        scanf("%d", &a);
        scanf("%s", op);
        scanf("%d", &b);
        switch(op[0]) {
            case '>':
                if(op[1]) print(a>=b);
                else print(a>b);
                break;
            case '<':
                if(op[1]) print(a<=b);
                else print(a<b);
                break;
            case '!':
                print(a!=b);
                break;
            case '=':
                print(a==b);
                break;
            case 'E':
                return 0;
        }
    }
    return 0;
}
