#include <stdio.h>
#include <algorithm>
using namespace std;
int d[1002];
int a[1002];
int f(int x){
    int maxSet = 0;
    if (x == 1)return a[1];
    else if (d[x]>0)return d[x];
    else{
        for (int i = 1; i <x; i++){
            d[x] = max(f(i)+ f(x-i), a[x]);
            if (d[x] > maxSet)maxSet = d[x];
        }
        return d[x] = maxSet;
    }

}
int main() {
    int n;
    int ans;

    scanf("%d", &n);
    for (int i = 1; i <=n; i++){
        scanf("%d", &a[i]);
    }
    ans=f(n);
    printf("%d\n", ans);
    return 0;
}
