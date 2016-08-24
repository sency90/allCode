#include <cstdio>
using namespace std;
int d[2][500001], v[50];
int main() {
    int n; scanf("%d", &n);
    memset(d, 0, sizeof(d));
    for(int i=0; i<n; i++) scanf("%d", &v[i]);
    for(int i=0; i<n; i++) {
        if(dif+v[i]<500000) 
        d[s^1][dif+v[i]] = max(d[s][dif], d[s^1][dif+v[i]]+v[i]);
        d[s^1][abs(dif-v[i])] = max(d[s][dif], d[s^1][abs(dif-v[i])+v[i]]);
        d[s^1][dif] = max(d[s^1][dif],)
    }
    return 0;
}
