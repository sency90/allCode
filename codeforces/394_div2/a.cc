#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>
using namespace std;
int main() {
    int e,o;
    scanf("%d%d",&e,&o);
    if(o==0 && e==0) puts("NO");
    else if(abs(o-e)<=1) puts("YES");
    else puts("NO");
    return 0;
}
