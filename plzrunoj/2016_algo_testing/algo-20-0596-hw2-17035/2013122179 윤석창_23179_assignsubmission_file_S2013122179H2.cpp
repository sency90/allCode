#include <stdio.h>
#include <algorithm>
using namespace std;

int a[1001];
int main(){
    int n, ans = 0;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    sort(a, a+n);
    for(int i=0;i<n;i++){
        if(a[i] >= n-i){
            ans = n-i;
            break;
        }
    }
    printf("%d", ans);
    return 0;
}
