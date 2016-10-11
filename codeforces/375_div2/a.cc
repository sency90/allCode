#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
int main() {
    int v[3];
    for(int i=0; i<3; i++){
        scanf("%d",&v[i]);
    }
    sort(v,v+3);
    int mn=0x3f3f3f3f;
    for(int i=v[0]; i<=v[2]; i++) {
        int sum=0;
        for(int j=0; j<3; j++) {
            sum+=abs(i-v[j]);
        }
        mn=min(sum,mn);
    }
    printf("%d\n", mn);
    return 0;
}
