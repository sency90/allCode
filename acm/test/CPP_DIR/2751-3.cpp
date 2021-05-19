#include<stdio.h>
#define MIL 1000000
#define IDX 2000001
bool arr[IDX];
int main() {
    int n, d; scanf("%d", &n);
    int max = -MIL, min = MIL;
    while(n--) {
        scanf("%d", &d);
        arr[MIL + d] = true;
        if(min > d) min = d;
        if(max < d) max = d;
    }
    int temp = MIL+max+1;
    for(int i=MIL+min; i<temp; i++) {
        if(arr[i]) printf("%d\n", i-MIL);
    }
    return 0;
}
