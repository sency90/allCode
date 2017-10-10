#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
char a[2],b[2];
int chg(char x) {
    if(x=='v') return 0;
    else if(x=='<') return 1;
    else if(x=='^') return 2;
    else return 3;
}
int main() {
    scanf("%s%s",a,b);
    int x=chg(a[0]), y=chg(b[0]);
    int p=x-y, q=y-x;
    int n; scanf("%d", &n);
    bool ccw=false, cw=false;
    if(n%4==(p+4)||n%4==p) ccw=true;
    if(n%4==(q+4)||n%4==q) cw=true;
    if(cw&&ccw) puts("undefined");
    else if(cw) puts("cw");
    else puts("ccw");
    return 0;

}
