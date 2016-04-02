#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int q1=0, q2=0, q3=0, q4=0, axis=0, a, b;
    while(n--) {
        scanf("%d %d", &a, &b);
        if(a==0 || b==0) axis++;
        else if(a>0 && b>0) q1++;
        else if(a<0 && b>0) q2++;
        else if(a<0 && b<0) q3++;
        else q4++;
    }
    printf("Q1: %d\nQ2: %d\nQ3: %d\nQ4: %d\nAXIS: %d\n", q1, q2, q3, q4, axis);
    return 0;
}
