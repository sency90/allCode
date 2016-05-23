#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int v[1001], cap[1001], idx[1001], n, ma = 0;
int main() {
    memset(cap, 0, sizeof(cap));
    memset(idx, 0, sizeof(idx));
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    cap[v[0]]++;
    idx[0] = v[0];
    int k = 1;
    for(int i=1; i<n; i++) {
        for(int j=0; idx[j]; j++) {
            //if(cap[j] == 0) continue;
            if(idx[j] == v[i]) continue;
            else if(idx[j] < v[i]) {
                //if( 0 == cap[v[i]] )
                printf("cap[%d]:%d, v[%d]:%d\n", idx[j], cap[idx[j]], i, v[i]);
                cap[v[i]]++;
                printf("cap[v[i]]++: %d\n", cap[v[i]]);
            } else cap[idx[j]]++;
            idx[k++] = v[i];
        }
    }
    for(int i=0; i<1001; i++) {
        if(ma < cap[i]) ma = cap[i];
    }
    printf("%d", ma);
    return 0;
}
