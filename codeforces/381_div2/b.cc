#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int v[101];
int main() {
    //ios::sync_with_stdio(false); cin.tie(0);
    int n,m,sum=0;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++) {
        scanf("%d", &v[i]);
        v[i]+=v[i-1];
    }
    int a,b;
    for(int i=0; i<m; i++) {
        scanf("%d%d",&a,&b);
        if(v[b]-v[a-1] >= 0) sum+=v[b]-v[a-1];
    }
    printf("%d", sum);
    return 0;
}
