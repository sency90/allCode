#include <stdio.h>

int arr[999][999];
int i, j;
int findNum;
int saveXY[2];
void assignDigit(int x, int n) {
    int val = n*n;
    int end = n+x;

    if(findNum <= val && findNum > (n-2)*(n-2)) {
        for(i=x; i<end; i++) {
            if(val == findNum) {
                saveXY[0] = i;
                saveXY[1] = x;
            }
            arr[i][x] = val--;
        }
        for(i=x+1; i<end; i++) {
            if(val == findNum) {
                saveXY[0] = end-1;
                saveXY[1] = i;
            }
            arr[end-1][i] = val--;
        }
        for(i=end-2; i>x-1; i--) {
            if(val == findNum) {
                saveXY[0] = i;
                saveXY[1] = end-1;
            }
            arr[i][end-1] = val--;
        }
        for(i=end-2; i>x; i--) {
            if(val == findNum) {
                saveXY[0] = x;
                saveXY[1] = i;
            }
            arr[x][i] = val--;
        }
    }
    else {
        for(i=x; i<end; i++) arr[i][x] = val--;
        for(i=x+1; i<end; i++) arr[end-1][i] = val--;
        for(i=end-2; i>x-1; i--) arr[i][end-1] = val--;
        for(i=end-2; i>x; i--) arr[x][i] = val--;
    }

    if(val == 1) {
        arr[x+1][x+1] = 1;
        if(findNum == 1) {
            saveXY[0] = x+1;
            saveXY[1] = x+1;
        }
        return;
    }
    else {
        assignDigit(x+1, n-2);
    }
}

int main() {

    int n;
    scanf("%d", &n);
    scanf("%d", &findNum);

    assignDigit(0, n);

    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("%d %d\n", saveXY[0]+1, saveXY[1]+1);

    return 0;
}
