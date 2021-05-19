#include <stdio.h>
int main() {
    bool s[100];
    int a[10] = {1,2,3,4,5,1,2,3,4,5};
    int n, d; scanf("%d", &n);
    for(int i=0; i<n; i++) s[i] = true;
    for(int i=0; i<n; i++) {
        for(int j=0; j<10; j++) {
            scanf("%d", &d);
            if(d!=a[j]) s[i] = false;
        }
    }
    for(int i=0; i<n; i++) {
        if(s[i]) printf("%d\n", i+1);
    }
    return 0;
}
