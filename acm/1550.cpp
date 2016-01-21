#include <stdio.h>

int main() {

    char input[7];
    int i;
    for(i=0; i<7; i++) input[i] = '\0';
    
    int result;
    int n16 = 1;

    scanf("%s", input);
    for(int i=5; i>=0; i--) {
        switch(input[i]) {
            case '0':
                n16 *= 16;
                break;
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                result += (input[i]-'0') * n16;
                n16 *= 16;
                break;
            case 'A':
                result += 10*n16;
                n16 *= 16;
                break;
            case 'B':
                result += 11*n16;
                n16 *= 16;
                break;
            case 'C':
                result += 12*n16;
                n16 *= 16;
                break;
            case 'D':
                result += 13*n16;
                n16 *= 16;
                break;
            case 'E':
                result += 14*n16;
                n16 *= 16;
                break;
            case 'F':
                result += 15*n16;
                n16 *= 16;
                break;
            default:
                break;
        }
    }
    printf("%d\n", result);

    return 0;
}
