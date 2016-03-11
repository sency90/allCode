#include <stdio.h>
#include <limits.h>
#include <algorithm>
using namespace std;
int idx[10], v[10][10];
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        idx[i] = i;
        for(int j=0; j<n; j++) {
            scanf("%d", &v[i][j]);
        }
    }
    int min=INT_MAX/2, tmp;
    do{
        tmp = 0;
        for(int i=0; i<n-1; i++) {
            if(v[idx[i]][idx[i+1]]==0) {
                tmp = INT_MAX/2;
                break;
            }
            tmp+=v[idx[i]][idx[i+1]];
        }
        tmp+=v[idx[n-1]][idx[0]];
        if(min > tmp) min = tmp;
    } while(next_permutation(idx, idx+n));
    printf("%d", min);
    return 0;
}
