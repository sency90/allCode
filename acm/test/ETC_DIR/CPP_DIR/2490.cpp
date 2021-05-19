#include <stdio.h>
int main() {
    char c, cnt;
    for(int i=0; i<3; i++) {
        cnt = 0;
        for(int j=0; j<4; j++) {
            scanf("%hhd", &c);
            if(c==1) cnt++;
        }
        switch(cnt) {
            case 0: puts("D"); break;
            case 1: puts("C"); break;
            case 2: puts("B"); break;
            case 3: puts("A"); break;
            case 4: puts("E"); break;
        }
    }
}
