#include <cstdio>
using namespace std;
int month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main() {
    int m,d;
    scanf("%d%d",&m,&d);
    int sum = d+month[m];
    printf("%d", (sum+5)/7);
    return 0;
}
