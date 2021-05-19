#include <stdio.h>
int arr[1000001];
int main() {
    int n, ans=0, d;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &d);
        if(arr[d]==0) {
            ans++;
            arr[d-1]++;
        } else {
            arr[d]--;
            arr[d-1]++;
        }
    }
    printf("%d", ans);
    return 0;
}
