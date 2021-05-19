#include <stdio.h>
int gcd(int b, int l) {
    int t = b%l;
    if(t == 0) return l;
    else return gcd(l, t);
}
int main() {
    int t, n, v[100], res;
    scanf("%d", &t);
    while(t--) {
        res = 0;
        scanf("%d", &n);
        for(int i=0; i<n; i++) scanf("%d", &v[i]);
        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                if(v[i]>v[j]) res += gcd(v[i], v[j]);
                else res += gcd(v[j], v[i]);
            }
        }
        printf("%d\n", res);
    }

}
