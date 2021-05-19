#include <stdio.h>
int main() {
    int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char day[7][10] = {"Wednesday", "Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday"};
    int m, d, cnt=0; scanf("%d %d", &d, &m);
    for(int i=0; i<m-1; i++) {
        cnt += month[i];
    } cnt += d;
    printf("%s", day[cnt%7]);
    return 0;
}
