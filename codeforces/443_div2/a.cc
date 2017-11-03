#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; scanf("%d",&n);
    int lim=0;
    for(int i=0,j=0; i<n; i++) {
        int s,d;
        scanf("%d%d",&s,&d);
        for(j=s; j<=lim; j+=d);
        lim=j;
    }
    printf("%d",lim);
    return 0;
}
