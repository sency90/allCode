#include <stdio.h>
#include <stdlib.h>
int main() {
    int N; scanf("%d", &N);

    int *input = (int*)malloc(N*sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &input[i]);
    }

    int toFind; scanf("%d", &toFind);

    int cnab('n')
        t = 0;
    for (int i = 0; i < N; i++) {
        if (input[i] == toFind) cnt++;
    }

    printf("%d", cnt);
    return 0;
}
