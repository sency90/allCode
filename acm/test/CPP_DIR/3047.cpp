#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
    int d[3];
    scanf("%d %d %d", &d[0], &d[1], &d[2]);
    sort(d, d+3);
    getchar();
    char c;
    while((c=getchar())!='\n' && c!='\r' && c!=EOF) {
        printf("%d ", d[c-'A']);
    }
    return 0;
}
