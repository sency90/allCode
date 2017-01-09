#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int v[3];
    for(int i=0; i<3; i++) scanf("%d",&v[i]);
    sort(v, v+3);
    if(v[2]>=v[0]+v[1]) v[2]=v[0]+v[1]-1;
    printf("%d\n", v[0]+v[1]+v[2]);
    return 0;
}
