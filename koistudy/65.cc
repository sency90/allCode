#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    int a,b,c; scanf("%d%d%d",&a,&b,&c);
    printf("%s\n", (a&1)?"odd":"even");
    printf("%s\n", (b&1)?"odd":"even");
    printf("%s\n", (c&1)?"odd":"even");
    return 0;
}
