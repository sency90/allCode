#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
    char str[100][101];
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%s", str[i]);
    }
    int k;
    scanf("%d", &k);
    if(k == 1) {
        for(int i=0; i<n; i++) {
            printf("%s\n", str[i]);
        }
    } else if(k == 2) {
        for(int i=0; i<n; i++) {
            reverse(str[i], str[i]+n);
            printf("%s\n", str[i]);
        }
    } else {
        for(int i=n-1; i>=0; i--) {
            printf("%s\n", str[i]);
        }
    }
    return 0;
}
