#include <stdio.h>
int v[1000001];
int arrow[1000001];
int main() {
    int n, cnt=0;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    for(int i=0; i<n; i++) {
        if(arrow[v[i]]>0) {
            arrow[v[i]]--;
        } else cnt++;
        arrow[v[i]-1]++;
    }
    printf("%d", cnt);
    return 0;
}
