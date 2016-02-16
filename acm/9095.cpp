#include <stdio.h>
#include <string.h>

int memo[12];

int calc(int x) {
    int sum = 0;
    if(x == 0) return 1; //base case
    else {
        if(x-1 >= 0) {
            if(0 == memo[x-1]) memo[x-1] = calc(x-1);
            sum += memo[x-1];

            if(x-2 >= 0) {
                if(0 == memo[x-2]) memo[x-2] = calc(x-2);
                sum += memo[x-2];

                if(x-3 >= 0) {
                    if(0 == memo[x-3]) memo[x-3] = calc(x-3);
                    sum += memo[x-3];
                }
            }
        }
    }

    if(0 == sum) sum = 1;
    return sum;
}

int main() {
    int t, n;
    scanf("%d", &t);
    while(t--) {
        memset(memo, 0, sizeof(memo));
        scanf("%d", &n);
        printf("%d\n", calc(n));
    }
    return 0;
}
