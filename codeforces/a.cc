#include <cstdio>
using namespace std;
char v[100001];
int main() {
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    scanf("%s", v);
    if(v[a-1]==v[b-1]) puts("0");
    else puts("1");
    return 0;
}
