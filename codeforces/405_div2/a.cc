#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int a, b;
    scanf("%d%d",&a,&b);
    int cnt=0;
    for(int i=0; i<=1000; i++) {
        a*=3;
        b*=2;
        cnt++;
        if(a>b) break;
    }
    printf("%d", cnt);
    return 0;
}
