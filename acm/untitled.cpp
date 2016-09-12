#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
using namespace std;

void hanoi (int a_N, int a_dep, int a_arr) {      // N, departure, arrival
    int temp;
    // Basis
    if (a_N == 1) {
        printf ("%d %d\n", a_dep, a_arr);
        return ;
    }

    temp = 6 - a_dep - a_arr;
    hanoi (a_N-1, a_dep, temp);
    printf ("%d %d\n", a_dep, a_arr);
    hanoi (a_N-1, temp, a_arr);
}

int main() {
    int N;
    unsigned long result;

    scanf("%d", &N);
    result = (unsigned long) pow (2, N) - 1;    // 결과값
    printf("%lu\n", result);
    hanoi (N, 1, 3);   
}
