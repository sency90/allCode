#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
int main() {
    int s,a,b,c,d;
    scanf("%d%d%d%d%d",&s,&a,&b,&c,&d);
    int x=s*a+2*c, y=s*b+2*d;
    if(x<y) puts("First");
    else if(x>y) puts("Second");
    else puts("Friendship");
    return 0;
}
