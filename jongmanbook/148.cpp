#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            for(int k=j+1; k<n; k++) {
                for(int l=k+1; l<n; l++) {
                    printf("%d %d %d %d\n",i,j,k,l);
                }
            }
        }
    }
    return 0;
}
