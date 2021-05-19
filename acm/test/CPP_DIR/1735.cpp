#include <stdio.h>
int gcdCalc(int b, int l) {
    int temp;

    if( (temp = b%l) == 0) return l;
    else {
        b = l;
        l = temp;
        return gcdCalc(b, l);
    }
}

int main() {
    int nume[2], deno[2];
    for(int i=0; i<2; i++) {
        scanf("%d %d", &nume[i], &deno[i]);
    }

    int gcd;
    if(deno[0] > deno[1]) {
        gcd = gcdCalc(deno[0], deno[1]);
    } else {
        gcd = gcdCalc(deno[1], deno[0]);
    }

    int part[2];
    part[0] = deno[0]/gcd;
    part[1] = deno[1]/gcd;

    int lcm = part[0] * part[1] * gcd;
    int numeSum = (nume[0] * part[1]) + (nume[1] * part[0]);

    if(lcm > numeSum) {
        gcd = gcdCalc(lcm, numeSum);
    } else {
        gcd = gcdCalc(numeSum, lcm);
    }

    printf("%d %d\n", numeSum/gcd, lcm/gcd);

    return 0;
}
