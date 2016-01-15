#include <stdio.h>

int main() {
    int t;
    int a, b;
    int temp;
    scanf("%d", &t);

    while(t--) {
        scanf("%d %d", &a, &b);
        a = a%10;
        if(a == 0) a = 10;

        switch(a) {
            case 1:
            case 5:
            case 6:
            case 10:
                printf("%d\n", a);
                break;
            case 2:
                temp = b%4;
                if(temp == 0) printf("6\n");
                else if(temp == 1) printf("2\n");
                else if(temp == 2) printf("4\n");
                else printf("8\n");
                break;
            case 3:
                temp = b%4;
                if(temp == 0) printf("1\n");
                else if(temp == 1) printf("3\n");
                else if(temp == 2) printf("9\n");
                else printf("7\n");
                break;
            case 4:
                temp = b%2;
                if(temp == 0) printf("6\n");
                else printf("4\n");
                break;
            case 7:
                temp = b%4;
                if(temp == 0) printf("1\n");
                else if(temp == 1) printf("7\n");
                else if(temp == 2) printf("9\n");
                else printf("3\n");
                break;
            case 8:
                temp = b%4;
                if(temp == 0) printf("6\n");
                else if(temp == 1) printf("8\n");
                else if(temp == 2) printf("4\n");
                else printf("2\n");
                break;
            case 9:
                temp = b%2;
                if(temp == 0) printf("1\n");
                else printf("9\n");
                break;
        }
    }

    return 0;
}
