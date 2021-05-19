#include <stdio.h>
#include <algorithm>
using namespace std;
char str[11];
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++) {
        scanf("%s", str);
        reverse(str, str+m);
        printf("%s\n", str);
    }
    return 0;
}
