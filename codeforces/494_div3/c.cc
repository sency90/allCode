#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int v[5001];
int main() {
    int n,k; scanf("%d%d", &n,&k);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    double mx=0.0;
    for(int z=k; z<=n; z++) {
        int sum=0,s=-1;
        for(int i=0; i<z-1; i++) {
            sum+=v[i];
        }
        for(int i=z-1; i<n; i++, s++) {
            if(s>=0) sum-=v[s];
            sum+=v[i];
            mx=max(mx,(double)sum/z);
        }
    }
    printf("%.7lf", mx);
    return 0;
}
